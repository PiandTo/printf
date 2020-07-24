/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 08:38:53 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/23 11:46:01 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	size_t			dst_len;
	unsigned int	src_i;
	unsigned int	dst_i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	src_i = 0;
	dst_i = 0;
	if (dst_len == size)
		return (src_len + dst_len);
	if (dst_len < size)
	{
		dst_i = dst_len;
		while (dst_i < size - 1 && src[src_i] != '\0')
			dst[dst_i++] = src[src_i++];
		dst[dst_i] = '\0';
		return (src_len + dst_len);
	}
	return (size + src_len);
}
