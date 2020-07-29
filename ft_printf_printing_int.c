/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 07:52:16 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/29 19:25:07 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	check_int(char *ptr, t_struct *tmp)
{
	int		len;

	if (!ptr)
		return (-1);
	len = ft_strlen(ptr);
	(tmp->flag_minus || tmp->precision || tmp->precision_null) ? \
	tmp->flag_zero = 0 : tmp->flag_zero;
	if (tmp->precision >= len)
		tmp->precision = (*ptr == '-') ? (tmp->precision - len + 1) : \
		(tmp->precision - len);
	else
		tmp->precision = 0;
	(*ptr == '0' && tmp->precision_null) ? len = 0 : len;
	return (len);
}

int			ft_print_int(char *ptr, t_struct *tmp, int len)
{
	if ((len = check_int(ptr, tmp)) == -1)
		return (-1);
	if (*ptr == '-')
		tmp->res = ft_print_minus(ptr, len, tmp);
	else if (tmp->flag_minus)
	{
		print_zero(tmp, tmp->precision);
		tmp->res += write(1, ptr, len);
		print_blank(tmp, tmp->width - (len + tmp->precision));
	}
	else if (tmp->flag_zero)
	{
		print_zero(tmp, tmp->width - (len + tmp->precision));
		write_int(ptr, len, tmp);
	}
	else
	{
		print_blank(tmp, tmp->width - (len + tmp->precision));
		print_zero(tmp, tmp->precision);
		write_int(ptr, len, tmp);
	}
	free(ptr);
	return (tmp->res);
}

int			check_len(t_struct *tmp, char *temp)
{
	int	len;

	len = 0;
	len = (*temp == '0' && tmp->precision_null) ? 0 : ft_strlen(temp);
	(tmp->flag_minus || tmp->precision || tmp->precision_null) ? \
	tmp->flag_zero = 0 : tmp->flag_zero;
	(tmp->precision >= len) ? (tmp->precision -= len) : (tmp->precision = 0);
	return (len);
}

char		*ft_toupper_register(t_struct *tmp, char *temp)
{
	int len;

	len = 0;
	while (temp[len] != '\0')
	{
		if (tmp->type == 'X')
			temp[len] = ft_toupper(temp[len]);
		len++;
	}
	return (temp);
}
