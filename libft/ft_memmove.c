/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:12:57 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/19 06:48:48 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (d == s && d == (NULL))
		return (NULL);
	if (d < s)
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
		return (dest);
	}
	while (n-- > 0)
		*(d + n) = *(s + n);
	return (dest);
}
