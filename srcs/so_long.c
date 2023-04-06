/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:15:06 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:31:42 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	extension_check(char *str)
{
	char	*ext;
	int		i;
	int		j;

	ext = ".ber";
	i = (int)ft_strlen(str) - 4;
	j = 0;
	if ((i + 4) > 4)
	{
		while (str[i])
		{
			if (str[i] != ext[j])
			{
				ft_putendl_fd("Error\nWrong extension name.\n", 2);
				exit(EXIT_FAILURE);
			}
			i++;
			j++;
		}
	}
	else
	{
		ft_putendl_fd("Error\nWrong extension name.\n", 2);
		exit(EXIT_FAILURE);
	}
}


int	main(int ac, char *av[])
{
	t_data	*v;

	if (ac != 2)
	{
		ft_putendl_fd("Error\nWrong numbers of args.\n", 2);
		exit(EXIT_FAILURE);
	}
	extension_check(av[1]);
	v = (t_data *)malloc(sizeof(t_data));
	if (!v)
		return (-1);
	v->m.map = NULL;
	v->m.map = get_map(av, v);
	is_valid(v);
	is_playable(av, v);
	display_map(v);
	return (0);
}
