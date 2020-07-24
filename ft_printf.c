/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:56:20 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/24 08:22:21 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//%[флаги][ширина][точность][модификаторы][тип преобразования]
static const char		*parser(const char *s, t_struct *tmp, va_list ap)
{
	int		temp;
	int 	digit;

	temp = 0;
	while (*s && !tmp->type)
	{
		if (*s == '-')
			tmp->flag_minus = 1;
		else if (*s == '0' && !tmp->flag_minus && !tmp->precision_num)
				tmp->flag_zero = 1;
		else if (*s == '*' || ('0' <= *s && *s <= '9'))
				(*s == '*') ? (tmp->width = va_arg(ap, int)) : (tmp->width = ft_atoi(s));
		else if (*s == '.')
				(*(s + 1) == '*') ? (tmp->precision = va_arg(ap, int)) : (tmp->precision = ft_atoi(++s));
		else if (ft_strchr("cspdiuxX%", *s))
				tmp->type = *s;
		s++;
	}
	return (s);
}

static int	processor(va_list ap, t_struct *tmp)
{
	if (tmp->type == '%')
		ft_print_char('%', tmp);
	else if (tmp->type == 'd' || tmp->type == 'i')
		ft_print_int(va_arg(ap, int), tmp);
	else if (tmp->type == 's')
		tmp->res += ft_print_str(va_arg(ap, char*), tmp);
	else if (tmp->type == 'c')
		ft_print_char(va_arg(ap, int), tmp);
	else if (tmp->type == 'p')
		ft_print_ptr(va_arg(ap, char*), tmp);
	else if (tmp->type == 'u' || tmp->type == 'x' || tmp->type == 'X')
		ft_print_hex(va_arg(ap, unsigned int), tmp);
	return (tmp->res);
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_struct	container;

	va_start(ap, s);
	if (ft_lstnew_printf(&container) == NULL)
		return (-1);
	while(*s)
	{
		if (*s != '%')
			(write(1, s++, 1) == -1) ? (container.res = -1) : (container.res++);
		else
		{
			s = parser((++s), &container, ap);
			processor(ap, &container);
		}
	}
	va_end(ap);
	return (container.res);
}
