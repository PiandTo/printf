/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 08:07:21 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/24 08:31:13 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_nofind_char(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		while (s1[i] == set[j] && s1[i] != '\0')
			i++;
		j++;
		if (s1[i] == set[j] && s1[i] != '\0')
		{
			i++;
			j = 0;
		}
	}
	return (i);
}

static int	end_nofind_char(char const *s1, char const *set)
{
	int i;
	int j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] != '\0')
	{
		while (s1[i] == set[j])
			i--;
		j++;
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char			*temp;
	unsigned int	begin;
	unsigned int	end;
	size_t			len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	begin = start_nofind_char(s1, set);
	end = end_nofind_char(s1, set);
	if (begin == len)
	{
		temp = malloc(1);
		*temp = '\0';
		return (temp);
	}
	temp = ft_substr(s1, begin, end - begin + 1);
	return (temp);
}
