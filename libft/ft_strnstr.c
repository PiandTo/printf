/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 08:39:36 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/28 19:56:00 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		ptr_little;
	size_t		ptr_big;

	ptr_big = 0;
	if (*little == '\0')
		return ((char*)big);
	while (ptr_big < len && big[ptr_big] != '\0')
	{
		ptr_little = 0;
		while (big[ptr_big + ptr_little] == little[ptr_little] &&
		little[ptr_little] != '\0')
		{
			if (big[ptr_big + ptr_little] == '\0' ||
			(ptr_big + ptr_little) > len)
				return (NULL);
			ptr_little++;
		}
		if (little[ptr_little] == '\0')
			return ((char*)(big + ptr_big));
		ptr_big++;
	}
	return (NULL);
}
