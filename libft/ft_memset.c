/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:57:15 by amarna            #+#    #+#             */
/*   Updated: 2022/05/11 15:04:26 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	if (!str)
	{
		return (NULL);
	}
	while (i < n)
	{
		str[i++] = c;
	}
	return (str);
}
/*int main()
{
	int c = 9;
	char test[] = "qalpp";
	printf("%p\n", ft_memset(test,c,3));
	printf("%p\n",memset(test,c,3));
}*/
