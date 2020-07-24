/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:55:24 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/23 20:51:35 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct		s_struct
{
	int				flag_minus;//результат преобразования выравнивается по левому краю (по умолчанию - по правому краю)
	int				flag_zero;//если не указан флаг '-', то слева от выводимого числа будут выведены символы '0' для подгона числа к указанной ширене. если для преобразователей d, i, o, x или x указана точность, то флаг 0 игнорируется.
	int				width;//Ширина указывается либо целым числом, либо символом * с последующим указанием имени переменной типа int, содержащей значение ширины, перед аргументом к которому он относится. если аргумент имеет отрицательное значение, то он эквивалентен соответствующему положительному значению с флагом "-".
	int				precision;//
	int				precision_num;
	char			type;//conversions: cspdiuxX%//
	int				res;
}					t_struct;

int					ft_printf(const char *format, ...);
t_struct			*ft_lstnew_printf(t_struct *tmp);
int					ft_print_str(char* temp, t_struct *tmp);
int					ft_print_char(char s, t_struct *tmp);
int					ft_print_int(int i, t_struct *tmp);
int					ft_print_ptr(char *temp, t_struct *tmp);
int					ft_print_hex(unsigned int i, t_struct * tmp);
t_struct			free_struct(t_struct *container);

#endif