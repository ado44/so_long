/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:02:54 by amarna            #+#    #+#             */
/*   Updated: 2022/05/24 15:55:44 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*begin;

	if (lst == 0 || f == 0)
		return (NULL);
	result = ft_lstnew((*f)(lst->content));
	if (!result)
		return (NULL);
	begin = result;
	lst = lst->next;
	while (lst)
	{
		begin->next = ft_lstnew((*f)(lst->content));
		if (!begin->next)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		begin = begin->next;
		lst = lst->next;
	}
	return (result);
}
