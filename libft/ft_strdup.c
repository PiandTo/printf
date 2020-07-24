/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 06:24:19 by snaomi            #+#    #+#             */
/*   Updated: 2020/06/27 10:44:27 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*temp;
	const char	*buf;
	int			len;
	int			i;

	len = 0;
	i = 0;
	buf = s;
	while (*buf != '\0')
	{
		len++;
		buf++;
	}
	temp = malloc(sizeof(*s) * len + 1);
	if (temp == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
