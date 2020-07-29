/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:11:50 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/29 16:21:36 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_xtoa(unsigned long long n, char *base)
{
	char					*res;
	int						len;
	unsigned long long		buf;

	buf = n;
	len = 1;
	while (buf >= 16)
	{
		len++;
		buf /= 16;
	}
	if (!(res = malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	while (n >= 16)
	{
		buf = n % 16;
		res[len--] = *(base + buf);
		n /= 16;
	}
	res[len] = *(base + n);
	return (res);
}
