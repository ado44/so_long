/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hex_ptr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:07:26 by amarna            #+#    #+#             */
/*   Updated: 2023/01/04 16:24:28 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_hex_ptr(unsigned long n, char *base, int *len)
{
	if (n >= 16)
	{
		ft_putnbr_base_hex_ptr(n / 16, base, len);
		n %= 16;
	}
	ft_putchar(base[n], len);
}
