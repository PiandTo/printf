/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:36:20 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/28 19:33:03 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count(int c)
{
	int i;

	i = 0;
	if (c < 0)
		i++;
	if (c == 0)
		i++;
	while (c)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		buf;

	len = count(n);
	if (!(res = malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (n)
	{
		buf = n % 10;
		if (buf < 0)
			buf = -buf;
		res[--len] = buf + '0';
		n /= 10;
	}
	return (res);
}
