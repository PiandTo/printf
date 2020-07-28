/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:56:20 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/28 15:24:53 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const char		*parser(const char *s, t_struct *tmp, va_list ap)
{
	while (*s && !tmp->type)
	{
		if (*s == '-')
			tmp->flag_minus = 1;
		else if (*s == '0' && !tmp->flag_minus && !tmp->precision_null)
			tmp->flag_zero = 1;
		else if (*s == '*' || ('0' <= *s && *s <= '9'))
		{
			if (*s == '*')
				(tmp->width = va_arg(ap, int));
			else
			{
				tmp->width = ft_atoi(s);
				tmp->width > 9 ? s++ : s;
			}
			if (tmp->width < 0)
			{
				tmp->width = -tmp->width;
				tmp->flag_minus = 1;
			}
		}
		else if (*s == '.')
		{
			if (*(++s) == '*' || ('0' < *s && *s <= '9'))
			{
				('0' < *s && *s <= '9') ? (tmp->precision = ft_atoi(s)) : (tmp->precision = va_arg(ap, int));
				tmp->precision == 0 ? tmp->precision_null = 1 : tmp->precision;
			}
			else if (*s == '0')
				tmp->precision_null = 1;
			else
			{
				s--;
				tmp->precision_null = 1;
			}
			if (tmp->precision < 0)
				tmp->precision = 0;
		}
		else if (ft_strchr("cspdiuxX%", *s))
			tmp->type = *s;
		s++;
	}
	return (s);
}

static int				processor(va_list ap, t_struct *tmp)
{
	if (tmp->type == '%')
		ft_print_char('%', tmp);
	else if (tmp->type == 'd' || tmp->type == 'i')
		ft_print_int(va_arg(ap, int), tmp);
	else if (tmp->type == 's')
		ft_print_str(va_arg(ap, char*), tmp);
	else if (tmp->type == 'c')
		ft_print_char(va_arg(ap, int), tmp);
	else if (tmp->type == 'p')
		ft_print_ptr(va_arg(ap, unsigned int), tmp);
	else if (tmp->type == 'u')
		ft_print_u(va_arg(ap, unsigned int), tmp);
	else if (tmp->type == 'x' || tmp->type == 'X')
		ft_print_hex(va_arg(ap, unsigned int), tmp);
	return (tmp->res);
}

int						ft_printf(const char *s, ...)
{
	va_list		ap;
	t_struct	container;
	int			res;

	res = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			(write(1, s++, 1) == -1) ? (res = -1) : (res++);
		else
		{
			if (ft_lstnew_printf(&container) == NULL)
				return (-1);
			s = parser((++s), &container, ap);
			(processor(ap, &container) == -1) ? (res = -1) : (res += container.res);
		}
	}
	va_end(ap);
	return (res);
}
