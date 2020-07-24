/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaomi <snaomi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:35:40 by snaomi            #+#    #+#             */
/*   Updated: 2020/07/23 21:09:35 by snaomi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_struct		*ft_lstnew_printf(t_struct *tmp)
{

	tmp->width = 0;
	tmp->flag_minus = 0;
	tmp->flag_zero = 0;
	tmp->precision = 0;
	tmp->precision_num = 0;
	tmp->type = '\0';
	tmp->res = 0;
	return (tmp);
}
