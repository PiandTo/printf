/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 08:13:31 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/27 17:26:17 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX 9223372036854775807

int		ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	res;

	res = 0;
	sign = 1;
	while ((*nptr == '\t') || (*nptr == '\n') || (*nptr == '\v') ||\
	(*nptr == '\r') || (*nptr == '\f') || (*nptr == ' '))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		if (sign == -1 && res >= MAX)
			return (0);
		if (sign == 1 && res >= MAX)
			return (-1);
		res = 10 * res + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}
