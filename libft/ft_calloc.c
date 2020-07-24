/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 06:29:20 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/18 13:40:02 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (void*)(malloc(nmemb * size));
	if (temp == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		temp[i] = '\0';
		i++;
	}
	return ((void*)temp);
}
