/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:10:21 by amarna            #+#    #+#             */
/*   Updated: 2022/05/17 11:08:32 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
	i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (str[i] > 47 && str[i] < 58)
			res = (res * 10) + (str[i] - 48);
	i++;
	}
	return (res * sign);
}
