# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/16 21:54:50 by snaomi            #+#    #+#              #
#    Updated: 2020/07/28 13:29:46 by snaomi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c\
		ft_printf_utils.c\
		ft_printf_printing.c\
		ft_printf_printing_int.c

OBJ = $(SRC:.c=.o)
HEADER = printf.h
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft

all: $(NAME)

%.o: %.c $(SRC) $(HEADER)
	gcc -c $(FLAGS) -o $@ $<

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	cp ./libft/libft.a $(NAME)
	ar -rcsv $@ $^

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libftprintf.so

re: fclean all