/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 08:51:17 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/27 06:28:05 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*temp;
	size_t		len_str;
	int			i;
	int			j;

	j = 0;
	if (s == NULL)
		return (NULL);
	len_str = ft_strlen(s);
	if (len_str < start)
		return (ft_strdup(""));
	len_str < len ? len = len_str : len;
	if (!(temp = malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	i = start;
	while (len && *s != '\0')
	{
		temp[j++] = s[i++];
		len--;
	}
	temp[j] = '\0';
	return (temp);
}
