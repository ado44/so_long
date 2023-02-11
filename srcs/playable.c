/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:31 by amarna            #+#    #+#             */
/*   Updated: 2023/02/10 14:57:40 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_tmp(char **map, t_program *v)
{
	int	i;

	i = 0;
	while (i < v->map.h_tmp)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// void	free_tmp(t_program *data)
// {
// 	int	i;

// 	i = 0;
// 	if (data->map.tmp)
// 	{
// 		while (data->map.tmp[i])
// 		{
// 			free(data->map.tmp[i]);
// 			i++;
// 		}
// 		free(data->map.tmp);
// 	}
// }

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] != '1')
	{
		if (map[y][x] != '+')
		{
			map[y][x] = '+';
			flood_fill(map, y + 1, x);
			flood_fill(map, y - 1, x);
			flood_fill(map, y, x + 1);
			flood_fill(map, y, x - 1);
		}
	}
}

void	find_player(t_program *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->map.h_tmp)
	{
		j = 0;
		while (v->map.map[i][j])
		{
			if (v->map.map[i][j] == 'P')
			{
				v->map.pos_y = i;
				v->map.pos_x = j;
			}
			j++;
		}
		if (v->map.map[i][j])
			break ;
		i++;
	}
}

void	is_playable(char *av[], t_program *v)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = get_map_tmp(av, v);
	find_player(v);
	flood_fill(tmp, v->map.pos_y, v->map.pos_x);
	while (i < v->map.h_tmp)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'P' || tmp[i][j] == 'C' || tmp[i][j] == 'E')
			{
				free_tmp(tmp, v);
				free_map(v);
				err_msg("Error\nMap not playable.");
			}
			j++;
		}
		i++;
	}
	free_tmp(tmp, v);
}
