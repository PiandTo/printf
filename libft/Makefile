# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/08 09:05:19 by snaomi            #+#    #+#              #
#    Updated: 2020/07/25 08:19:01 by snaomi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_memset.c\
		ft_bzero.c\
		ft_memcmp.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memcpy.c\
		ft_memchr.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strdup.c\
		ft_calloc.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_xtoa.c\
		ft_itoa.c\
		ft_utoa.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c

SRC_B = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c

OBJ_B = $(SRC_B:.c=.o)
OBJ = $(SRC:.c=.o)
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(SRC_B) $(HEADER)
	gcc -c $(FLAGS) -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: all $(OBJ_B)
	ar rc $(NAME) $(OBJ_B)
	ranlib $(NAME)

so:
	gcc -fPIC -c $(SRC) $(SRC_B) $(FLAGS)
	gcc $(OBJ) $(OBJ_B) -shared -o libft.so

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)
	rm -f libft.so

re: fclean all

.PHONY: all clean fclean re bonus so
