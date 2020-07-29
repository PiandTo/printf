/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:55:24 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/29 19:28:01 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct		s_struct
{
	int				flag_minus;
	int				flag_zero;
	int				width;
	int				precision;
	int				precision_null;
	char			type;
	int				res;
}					t_struct;

int					ft_printf(const char *format, ...);
t_struct			*ft_lstnew_printf(t_struct *tmp);
int					ft_print_str(char *temp, t_struct *tmp);
int					ft_print_char(char s, t_struct *tmp);
int					ft_print_int(char *ptr, t_struct *tmp, int len);
int					ft_print_ptr(unsigned long long i, t_struct *tmp);
int					ft_print_hex(unsigned int i, t_struct *tmp, int len);
int					ft_print_u(unsigned int i, t_struct *tmp);
t_struct			free_struct(t_struct *container);
int					write_int(char *temp, int len, t_struct *tmp);
int					ft_print_minus(char *temp, int len, t_struct *tmp);
int					print_zero(t_struct *tmp, int temp);
int					print_blank(t_struct *tmp, int len);
int					check_len(t_struct *tmp, char *temp);
char				*ft_toupper_register(t_struct *tmp, char *temp);

#endif
