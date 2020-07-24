# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/16 21:54:50 by snaomi            #+#    #+#              #
#    Updated: 2020/07/21 08:00:18 by snaomi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c\
		ft_printf_utils.c\
		ft_printf_printing.c

OBJ = $(SRC:.c=.o)
HEADER = ./include/
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft

all: $(NAME)

%.o: %.c $(SRC) $(HEADER)
	gcc -c $(FLAGS) -o $@ $<

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	cp ./libft/libft.a $(NAME)
	ar -rcsv $@ $^

so:
	gcc -fPIC -c $(SRC) $(FLAGS)
	gcc $(OBJ) -shared -o libftprintf.so

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libftprintf.so
