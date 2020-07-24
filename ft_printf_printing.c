/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 06:53:41 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/24 09:53:44 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_str(char* temp, t_struct *tmp)
{
	char	*new;
	int		len;
	int		res;

	if (!temp && !(temp = ft_strdup("(null)")))
		return (-1);
	len = ft_strlen(temp);
	(tmp->width > len) ? (res = (tmp->width - len)) : (res = 0);
	(tmp->precision) ? len = tmp->precision : len;
	while (((tmp->width--) > len) && !(tmp->flag_minus))
	{
		ft_putchar_fd(' ', 1);
		res += 1;
	}
	if (tmp->precision)
		res += write(1, temp, tmp->precision);
	else
	{
		ft_putstr_fd(temp, 1);
		res += len;
	}
	while (tmp->flag_minus && (res <= tmp->width))
	{
		ft_putchar_fd(' ', 1);
		res++;
	}
	return (res);
}

int		ft_print_char(char c, t_struct *tmp)
{
	char	*new;
	int		res;

	if (!c)
		return (-1);
	ft_putchar_fd(c, 1);
	tmp->res++;
	if (tmp->flag_minus)
		while (tmp->width-- > 1)
			tmp->res += write(1, " ", 1);
	return (tmp->res);
}

int		ft_print_int(int i, t_struct *tmp)
{
	char	*ptr;
	char	*temp;
	int		len;

	if (!i || !(ptr = ft_itoa(i)))
		return (-1);
	temp = ptr;
	len = ft_strlen(ptr);
	(tmp->flag_minus) ? tmp->flag_zero = 0 : tmp->flag_zero;
	if (tmp->flag_minus)
	{	
		if (tmp->precision)
		{
			(tmp->precision < len) ? len = tmp->precision : len;
			while (tmp->precision-- > len)
				tmp->res += write(1, "0", 1);
			while(len--)
				tmp->res += write(1, temp++, 1);
		}
		if (tmp->width)
		{
			while (tmp->width-- > len)
				tmp->res += write(1, " ", 1);
		}
		ft_putstr_fd(temp, 1);
	}
	while (tmp->flag_zero && ((tmp->width - len) > 0))
	{
		tmp->res += write(1, "0", 1);
		tmp->width--;		
	}
	while (--tmp->width > tmp->precision)
		tmp->res += write(1, " ", 1);
	if (i < 0)
	{
		tmp->res += write(1, temp++, 1);
		len--;
	} 
	while (tmp->precision-- > len)
		tmp->res += write(1, "0", 1);
	while(len--)
		tmp->res += write(1, temp++, 1);
	free(ptr);
	ptr = NULL;
	return (tmp->res);	
}
/*Hexadecimal value has 16 alphanumeric values from 0 to 9 and A to F, with the base 16
**"%x" prints the value in Hexadecimal format with alphabets in lowercase (a-f).
**"%X" prints the value in Hexadecimal format with alphabets in uppercase (A-F).
**There is no special type of data type to store Hexadecimal values in C programming, Hexadecimal number is an integer value and you can store it in the integral type of data types (char, short or int).
**Let suppose, we have two values in Hexadecimal "64" (100 in Decimal) and "FAFA" (64250 in Decimal).
**We are storing "64" in an unsigned char variable (64 is small value and can be stored with in a Byte) and "FAFA" in the int variable.
*/
int		ft_print_hex(unsigned int i, t_struct *tmp)
{
	char	*temp;
	char	*buf;
	int		len;

	len = 0;
	if (!(temp = ft_xtoa(i, "0123456789abcdef")))
		return (0);
	buf = temp;
	while (buf[len] != '\0')
	{
		if (tmp->type == 'X')
			temp[len] = ft_toupper(buf[len]);
		len++;
	}
	ft_putstr_fd(temp, 1);
	tmp->res = len;
	return (tmp->res);
}

int		ft_print_ptr(char *temp, t_struct *tmp)
{
	
}