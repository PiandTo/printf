/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 08:16:39 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/29 18:15:47 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count(unsigned int c)
{
	int i;

	i = 0;
	if (c == 0)
		i++;
	while (c)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char			*ft_utoa(unsigned int n)
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
	while (n)
	{
		buf = n % 10;
		res[--len] = buf + '0';
		n /= 10;
	}
	return (res);
}
