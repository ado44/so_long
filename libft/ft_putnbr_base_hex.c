/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:12 by amarna            #+#    #+#             */
/*   Updated: 2022/06/07 15:12:04 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_hex(unsigned int n, char *base, int *len)
{
	if (n >= 16)
	{
		ft_putnbr_base_hex(n / 16, base, len);
		n %= 16;
	}
	ft_putchar(base[n], len);
}
