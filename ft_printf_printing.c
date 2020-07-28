/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 06:53:41 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/28 13:34:37 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_str(char* temp, t_struct *tmp)
{
	int		len;

	if (!temp)
		return (-1);
	if (tmp->precision_null && !tmp->width)
		return (0);
	len = ft_strlen(temp);
	len = (tmp->precision_null) ? 0 : len;
	len = (tmp->precision && tmp->precision <= len) ? tmp->precision : len;
	if (tmp->flag_minus)
	{
		tmp->res += write(1, temp, len);
		while (tmp->width > tmp->res)
		{
			ft_putchar_fd(' ', 1);
			tmp->res++;
		}
	}
	else if (tmp->flag_zero)
	{
		while (tmp->width > tmp->res)
		{
			ft_putchar_fd('0', 1);
			tmp->res++;
		}
		tmp->res += write(1, temp, len);	
	}
	else 
	{
		while (tmp->width > (tmp->res + len))
		{
			ft_putchar_fd(' ', 1);
			tmp->res++;
		}
		tmp->res += write(1, temp, len);
	}
	return (tmp->res);
}

int		ft_print_char(char c, t_struct *tmp)
{
	int		len;

	len = 1;
	if (tmp->flag_minus)
	{
		tmp->res += write(1, &c, 1);
		while (tmp->width > tmp->res)
		{
			ft_putchar_fd(' ', 1);
			tmp->res++;
		}
	}
	else if (tmp->flag_zero)
	{
		while ((tmp->width - tmp->res) > len)
		{
			ft_putchar_fd('0', 1);
			tmp->res++;
		}
		tmp->res += write(1, &c, 1);
	}
	else
	{
		while ((tmp->width - tmp->res) > len)
		{
			ft_putchar_fd(' ', 1);
			tmp->res++;
		}
		tmp->res += write(1, &c, 1);
	}
	return (tmp->res);
}

int		ft_print_u(unsigned int i, t_struct *tmp)
{
	char	*temp;
	char	*buf;
	int		len;

	len = 0;
	if (!(temp = ft_utoa(i)))
		return (0);
	(tmp->flag_minus || tmp->precision || tmp->precision_null) ? tmp->flag_zero = 0 : tmp->flag_zero;
	buf = temp;
	while (buf[len] != '\0')
		len++;
	(*temp == '0' && tmp->precision_null) ? len = 0 : len;
	(tmp->precision >= len) ? (tmp->precision -= len) : (tmp->precision = 0);
	if (tmp->flag_minus)
	{
		while (tmp->precision-- > 0)
			tmp->res += write(1, "0" , 1);
		tmp->res += write(1, temp, len);
		while (tmp->width > tmp->res)
		{
			ft_putchar_fd(' ', 1);
			tmp->res++;
		}
	}
	else if (tmp->flag_zero)
	{
		while ((tmp->width - tmp->res) > (tmp->precision + len) || (tmp->precision--))
		{
			ft_putchar_fd('0', 1);
			tmp->res++;
		}
		tmp->res += write(1, temp, len);	
	}
	else 
	{
		while ((tmp->width - tmp->res) > (len + tmp->precision))
		{
			ft_putchar_fd(' ', 1);
			tmp->res++;
		}
		while (tmp->precision-- > 0)
			tmp->res += write(1, "0" , 1);
		tmp->res += write(1, temp, len);
	}
	free(temp);
	return (tmp->res);
}

int		ft_print_hex(unsigned int i, t_struct *tmp)
{
	char	*temp;
	char	*buf;
	int		len;

	len = 0;
	if (!(temp = ft_xtoa(i, "0123456789abcdef")))
		return (0);
	(tmp->flag_minus || tmp->precision || tmp->precision_null) ? tmp->flag_zero = 0 : tmp->flag_zero;
	buf = temp;
	while (buf[len] != '\0')
	{
		if (tmp->type == 'X')
			temp[len] = ft_toupper(buf[len]);
		len++;
	}
	(*temp == '0' && tmp->precision_null) ? len = 0 : len;
	(tmp->precision >= len) ? (tmp->precision -= len) : (tmp->precision = 0);
	if (tmp->flag_minus)
	{
		while (tmp->precision-- > 0)
			tmp->res += write(1, "0" , 1);
		tmp->res += write(1, temp, len);
		while (tmp->width > tmp->res)
		{
			ft_putchar_fd(' ', 1);
			tmp->res++;
		}
	}
	else if (tmp->flag_zero)
	{
		while ((tmp->width - tmp->res) > (len + tmp->precision) || (tmp->precision--))
		{
			ft_putchar_fd('0', 1);
			tmp->res++;
		}
		tmp->res += write(1, temp, len);	
	}
	else 
	{
		while ((tmp->width - tmp->res) > (len + tmp->precision))
		{
			ft_putchar_fd(' ', 1);
			tmp->res++;
		}
		while (tmp->precision-- > 0)
			tmp->res += write(1, "0" , 1);
		tmp->res += write(1, temp, len);
	}
	free(temp);
	return (tmp->res);
}

int		ft_print_ptr(unsigned int i, t_struct *tmp)
{
	int		len;
	char 	*buf;
	char 	*temp;

	len = 0;
	if (!(buf = ft_xtoa(i, "0123456789abcdef")))
		return (0);
	temp = buf;
	(*temp == '0' && tmp->precision_null) ? (len = 0) : (len = ft_strlen(temp));
	tmp->precision = (tmp->precision >= len) ? tmp->precision - len : 0;
	if (tmp->flag_minus)
	{
		tmp->res += write(1, "0x", 2);
		while ((tmp->precision - tmp->res) > 0)
			tmp->res += write(1, "0", 1);
		tmp->res += write(1, temp, len);
		while ((tmp->width - tmp->res) > 0)
			tmp->res += write(1, " ", 1);
	}
	else 
	{
		while ((tmp->width - tmp->res) > (len + 2 + tmp->precision))
			tmp->res += write(1, " ", 1);	
		tmp->res += write(1, "0x", 2);
		while ((tmp->precision - tmp->res) > 0)
			tmp->res += write(1, "0", 1);
		tmp->res += write(1, temp, len);
	}
	free (buf);
	return (tmp->res);
}