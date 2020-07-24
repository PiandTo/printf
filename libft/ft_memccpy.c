/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:13:14 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/23 07:57:06 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int ch, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned int	i;

	i = 0;
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (d == s && s == (NULL))
		return (dest);
	while (i < count)
	{
		d[i] = s[i];
		if (d[i] == ((unsigned char)ch))
			return ((void*)dest + i + 1);
		i++;
	}
	return (NULL);
}
