/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 05:41:45 by snaomi            #+#    #+#             */
/*   Updated: 2020/05/23 10:16:39 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int s)
{
	if ((s >= 65) && (s <= 90))
	{
		return (s += 32);
	}
	else
		return (s);
}
