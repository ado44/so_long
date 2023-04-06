/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:20:04 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:35:33 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] != '1')
	{
		if (map[y][x] != '-')
		{
			map[y][x] = '-';
			flood_fill(map, y + 1, x);
			flood_fill(map, y - 1, x);
			flood_fill(map, y, x + 1);
			flood_fill(map, y, x - 1);
		}
	}
}

void	find_pos_p(t_data *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->m.y)
	{
		j = 0;
		while (v->m.map[i][j])
		{
			if (v->m.map[i][j] == 'P')
			{
				v->m.y_pos = i;
				v->m.x_pos = j;
				break ;
			}
			j++;
		}
		if (v->m.map[i][j])
			break ;
		i++;
	}
}

void	is_playable(char *av[], t_data *v)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = get_map(av, v);
	find_pos_p(v);
	flood_fill(tmp, v->m.y_pos, v->m.x_pos);
	while (i < v->m.y)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'P' || tmp[i][j] == 'C' || tmp[i][j] == 'E')
			{
				free_tmp(tmp, v);
				error_return(v, 7);
			}
			j++;
		}
		i++;
	}
	free_tmp(tmp, v);
}
