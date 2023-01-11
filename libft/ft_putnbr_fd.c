/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:33:53 by amarna            #+#    #+#             */
/*   Updated: 2022/05/13 14:19:05 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a = -n;
	}
	if (a > 9)
	{
		ft_putnbr_fd((a / 10), fd);
		ft_putchar_fd((a % 10) + '0', fd);
	}
	else
		ft_putchar_fd(a + '0', fd);
}
