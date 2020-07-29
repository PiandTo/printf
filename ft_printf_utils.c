/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:35:40 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/29 16:06:44 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_struct		*ft_lstnew_printf(t_struct *tmp)
{
	tmp->width = 0;
	tmp->flag_minus = 0;
	tmp->flag_zero = 0;
	tmp->precision = 0;
	tmp->precision_null = 0;
	tmp->type = '\0';
	tmp->res = 0;
	return (tmp);
}

int				write_int(char *temp, int len, t_struct *tmp)
{
	while (len > 0)
	{
		tmp->res += write(1, temp, 1);
		temp++;
		len--;
	}
	return (tmp->res);
}

int				ft_print_minus(char *temp, int len, t_struct *tmp)
{
	if (tmp->flag_minus)
	{
		tmp->res += write(1, temp++, 1);
		print_zero(tmp, tmp->precision);
		write_int(temp, len - 1, tmp);
		print_blank(tmp, tmp->width - (len + tmp->precision));
	}
	else if (tmp->flag_zero)
	{
		tmp->res += write(1, temp++, 1);
		print_zero(tmp, tmp->width - (len + tmp->precision));
		write_int(temp, len - 1, tmp);
	}
	else
	{
		print_blank(tmp, tmp->width - (len + tmp->precision));
		tmp->res += write(1, temp++, 1);
		print_zero(tmp, tmp->precision);
		write_int(temp, len - 1, tmp);
	}
	return (tmp->res);
}

int				print_zero(t_struct *tmp, int temp)
{
	int i;

	i = 0;
	while (i < temp)
	{
		tmp->res += write(1, "0", 1);
		i++;
	}
	return (tmp->res);
}

int				print_blank(t_struct *tmp, int temp)
{
	int i;

	i = 0;
	while (i < temp)
	{
		tmp->res += write(1, " ", 1);
		i++;
	}
	return (tmp->res);
}
