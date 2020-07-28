/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 07:52:16 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/27 21:29:08 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_int(int i, t_struct *tmp)
{
	char	*ptr;
	char	*temp;
	int		len;

	if (!(ptr = ft_itoa(i)))
		return (-1);
	temp = ptr;
	len = ft_strlen(ptr);
	(tmp->flag_minus || tmp->precision || tmp->precision_null) ? tmp->flag_zero = 0 : tmp->flag_zero;
	if (tmp->precision >= len)
		tmp->precision = (*temp == '-') ? (tmp->precision - len + 1) : (tmp->precision - len);
	else
		tmp->precision = 0;
	(*temp == '0' && tmp->precision_null) ? len = 0 : len;
	if (*temp == '-')
		tmp->res = ft_print_minus(temp, len, tmp);
	else
	{
		if (tmp->flag_minus)
		{	
			print_zero(tmp, tmp->precision);
			tmp->res += write(1, temp++, len);
			print_blank(tmp, tmp->width -(len + tmp->precision));	
		}
		else if (tmp->flag_zero)
		{
			print_zero(tmp, tmp->width - (len + tmp->precision));
			write_int(temp, len, tmp);
		}
		else
		{
			print_blank(tmp, tmp->width -(len + tmp->precision));
			print_zero(tmp, tmp->precision);
			write_int(temp, len, tmp);
		}
	}
	free(ptr);
	return (tmp->res);	
}
