# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/16 21:54:50 by snaomi            #+#    #+#              #
#    Updated: 2020/07/29 11:59:49 by snaomi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = printf.h
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft

SRC =	ft_printf.c\
		ft_printf_utils.c\
		ft_printf_printing.c\
		ft_printf_printing_int.c

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	@$(MAKE) all -C $(LIBFTDIR)
	@cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	rm -f $(NAME)

bonus: $(make) all

re: fclean all

.PHONY:	all clean fclean re bonus
