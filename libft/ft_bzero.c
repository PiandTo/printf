/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 07:05:44 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/19 05:47:41 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *src, size_t num)
{
	unsigned int	i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char*)src;
	while (i < num)
		dest[i++] = '\0';
	return (src);
}
