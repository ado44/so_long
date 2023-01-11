/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:49:59 by amarna            #+#    #+#             */
/*   Updated: 2022/05/11 15:03:55 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;
	size_t	p;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	p = 0;
	while (i < n)
		d[i++] = s[p++];
	return (d);
}
