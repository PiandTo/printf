/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 22:55:31 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/19 05:48:42 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int value, size_t num)
{
	unsigned int	i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char*)src;
	while (i < num)
		dest[i++] = (unsigned char)value;
	return (src);
}
