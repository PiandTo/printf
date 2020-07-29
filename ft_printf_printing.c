/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 06:53:41 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/29 19:20:09 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_str(char *temp, t_struct *tmp)
{
	int		len;
	int		nil;

	nil = (!temp) ? 1 : 0;
	if (!temp && !(temp = ft_strdup("(null)")))
		return (-1);
	len = (tmp->precision_null) ? 0 : ft_strlen(temp);
	len = (tmp->precision && tmp->precision <= len) ? tmp->precision : len;
	if (tmp->flag_minus)
	{
		tmp->res += write(1, temp, len);
		print_blank(tmp, tmp->width - tmp->res);
	}
	else if (tmp->flag_zero)
	{
		print_zero(tmp, tmp->width - tmp->res);
		tmp->res += write(1, temp, len);
	}
	else
	{
		print_blank(tmp, tmp->width - (tmp->res + len));
		tmp->res += write(1, temp, len);
	}
	(nil) ? free(temp) : temp;
	return (tmp->res);
}

int		ft_print_char(char c, t_struct *tmp)
{
	int		len;

	len = 1;
	if (tmp->flag_minus)
	{
		tmp->res += write(1, &c, 1);
		print_blank(tmp, tmp->width - tmp->res);
	}
	else if (tmp->flag_zero)
	{
		print_zero(tmp, tmp->width - tmp->res - len);
		tmp->res += write(1, &c, 1);
	}
	else
	{
		print_blank(tmp, tmp->width - tmp->res - len);
		tmp->res += write(1, &c, 1);
	}
	return (tmp->res);
}

int		ft_print_u(unsigned int i, t_struct *tmp)
{
	char	*temp;
	int		len;

	if (!(temp = ft_utoa(i)))
		return (-1);
	len = check_len(tmp, temp);
	if (tmp->flag_minus)
	{
		print_zero(tmp, tmp->precision);
		tmp->res += write(1, temp, len);
		print_blank(tmp, tmp->width - tmp->res);
	}
	else if (tmp->flag_zero)
	{
		print_zero(tmp, (tmp->width - tmp->res - len - tmp->precision));
		tmp->res += write(1, temp, len);
	}
	else
	{
		print_blank(tmp, (tmp->width - tmp->res - len - tmp->precision));
		print_zero(tmp, tmp->precision);
		tmp->res += write(1, temp, len);
	}
	free(temp);
	return (tmp->res);
}

int		ft_print_hex(unsigned int i, t_struct *tmp, int len)
{
	char	*temp;

	if (!(temp = ft_xtoa(i, "0123456789abcdef")))
		return (-1);
	len = check_len(tmp, temp);
	temp = ft_toupper_register(tmp, temp);
	if (tmp->flag_minus)
	{
		print_zero(tmp, tmp->precision);
		tmp->res += write(1, temp, len);
		print_blank(tmp, tmp->width - tmp->res);
	}
	else if (tmp->flag_zero)
	{
		print_zero(tmp, (tmp->width - tmp->res - len - tmp->precision));
		tmp->res += write(1, temp, len);
	}
	else
	{
		print_blank(tmp, (tmp->width - tmp->res - len - tmp->precision));
		print_zero(tmp, tmp->precision);
		tmp->res += write(1, temp, len);
	}
	free(temp);
	return (tmp->res);
}

int		ft_print_ptr(unsigned long long i, t_struct *tmp)
{
	int		len;
	char	*buf;
	char	*temp;

	if (!(buf = ft_xtoa(i, "0123456789abcdef")))
		return (0);
	temp = buf;
	len = (*temp == '0' && tmp->precision_null) ? 0 : ft_strlen(temp);
	tmp->precision = (tmp->precision >= len) ? tmp->precision - len : 0;
	if (tmp->flag_minus)
	{
		tmp->res += write(1, "0x", 2);
		print_zero(tmp, tmp->precision - tmp->res);
		tmp->res += write(1, temp, len);
		print_blank(tmp, tmp->width - tmp->res);
	}
	else
	{
		print_blank(tmp, (tmp->width - tmp->res - len - 2 - tmp->precision));
		tmp->res += write(1, "0x", 2);
		print_zero(tmp, tmp->precision - tmp->res);
		tmp->res += write(1, temp, len);
	}
	free(buf);
	return (tmp->res);
}
