/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:24:09 by amarna            #+#    #+#             */
/*   Updated: 2022/05/13 14:33:29 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	destsize;
	size_t	srcsize;

	j = 0;
	i = ft_strlen(dest);
	destsize = ft_strlen(dest);
	srcsize = ft_strlen(src);
	if (size < 1)
		return (srcsize + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < destsize)
		return (srcsize + size);
	else
		return (destsize + srcsize);
}
/*int main()
{
	char test1[20] = "desT";
	char test2[20] = "src";
	printf("%d", ft_strlcat(test1, test2, 8));
}*/
