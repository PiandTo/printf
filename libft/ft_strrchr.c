/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 08:03:40 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/23 10:15:58 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	ptr = (char*)s;
	if (c == '\0')
	{
		while (*ptr != '\0')
			ptr++;
		return (ptr);
	}
	while (*ptr != '\0')
		ptr++;
	while (len >= 0)
	{
		if (*ptr == c)
			return (ptr);
		len--;
		ptr--;
	}
	return (NULL);
}
