/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:59:32 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/29 22:33:40 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const char		*prc_prec(t_struct *tmp, const char *s, va_list ap)
{
	if ((*s == '*') || ('0' <= *s && *s <= '9'))
	{
		(*s == '0' && *(s + 1) == '*') ? s++ : s;
		tmp->precision = ('0' <= *s && *s <= '9') ? ft_atoi(s) : \
		va_arg(ap, int);
		tmp->precision == 0 ? tmp->precision_null = 1 : tmp->precision;
	}
	return (s);
}

static const char		*parser_addition(int i, const char *s, t_struct *tmp)
{
	if (i == 1)
	{
		if (*s == '-' && !tmp->flag_minus)
			tmp->flag_minus = 1;
		else if (*s == '0' && !tmp->flag_minus && !tmp->precision_null &&\
		!tmp->flag_zero)
			tmp->flag_zero = 1;
	}
	if (i == 2)
	{
		if (tmp->width < 0)
		{
			tmp->width = -tmp->width;
			tmp->flag_minus = 1;
		}
	}
	if (i == 3)
	{
		if (*(++s) == '0' || *s != '0')
			tmp->precision_null = 1;
		else
			s--;
	}
	return (s);
}

static const char		*parser(const char *s, t_struct *tmp, va_list ap)
{
	while (*s && !tmp->type)
	{
		if ((*s == '-' && !tmp->flag_minus) || (*s == '0' && \
		!tmp->flag_minus && !tmp->precision_null))
			parser_addition(1, s, tmp);
		else if (!tmp->precision && (*s == '*' || ('0' <= *s && *s <= '9')))
		{
			tmp->width = (*s == '*') ? va_arg(ap, int) : ft_atoi(s);
			if (*s != '*' && tmp->width > 9)
				s++;
			parser_addition(2, s, tmp);
		}
		else if (*s == '.')
		{
			if (*(++s) == '*' || ('0' <= *s && *s <= '9'))
				prc_prec(tmp, s, ap);
			else
				parser_addition(3, --s, tmp);
			(tmp->precision < 0) ? tmp->precision = 0 : tmp->precision;
		}
		else if (ft_strchr("cspdiuxX%", *s))
			tmp->type = *s;
		s++;
	}
	return (s);
}

static int				processor(va_list ap, t_struct *tmp)
{
	int len;

	len = 0;
	if (tmp->type == '%')
		ft_print_char('%', tmp);
	else if (tmp->type == 'd' || tmp->type == 'i')
		ft_print_int(ft_itoa(va_arg(ap, int)), tmp, len);
	else if (tmp->type == 's')
		ft_print_str(va_arg(ap, char*), tmp);
	else if (tmp->type == 'c')
		ft_print_char(va_arg(ap, int), tmp);
	else if (tmp->type == 'p')
		ft_print_ptr(va_arg(ap, unsigned long long), tmp);
	else if (tmp->type == 'u')
		ft_print_u(va_arg(ap, unsigned int), tmp);
	else if (tmp->type == 'x' || tmp->type == 'X')
		ft_print_hex(va_arg(ap, unsigned int), tmp, len);
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
			container.res = processor(ap, &container);
			res = (container.res == -1) ? -1 : (res + container.res);
		}
	}
	va_end(ap);
	return (res);
}
