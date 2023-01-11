/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:05:11 by amarna            #+#    #+#             */
/*   Updated: 2023/01/11 09:52:01 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_data(t_program *p)
{
	p->data.total_collect = 0;
	p->data.total_empty = 0;
	p->data.total_exit = 0;
	p->data.total_player = 0;
	p->data.total_wall = 0;
	p->data.collect = 'C';
	p->data.empty = '0';
	p->data.exit = 'E';
	p->data.player = 'P';
	p->data.collect = '1';
	p->sprite.x = 60;
	p->sprite.y = 60;
	p->sprite.ref_w = mlx_xpm_file_to_image(p->mlx, "wall.xpm",
			&p->sprite.size.y, &p->sprite.size.y);
	p->sprite.ref_c = mlx_xpm_file_to_image(p->mlx, "collectable.xpm",
			&p->sprite.size.x, &p->sprite.size.y);
	p->sprite.ref_ex = mlx_xpm_file_to_image(p->mlx, "exit.xpm",
			&p->sprite.size.x, &p->sprite.size.y);
	p->sprite.ref_em = mlx_xpm_file_to_image(p->mlx, "floor2.xpm",
			&p->sprite.size.x, &p->sprite.size.y);
	p->sprite.ref_p = mlx_xpm_file_to_image(p->mlx, "player.xpm",
			&p->sprite.size.x, &p->sprite.size.y);
}

void	count_all(t_program *prog)
{
	int	i;
	int	j;

	i = 0;
	while (prog->map.map[i])
	{
		j = 0;
		while (prog->map.map[i][j])
		{
			if (prog->map.map[i][j] == 'P')
				prog->data.total_player += 1;
			if (prog->map.map[i][j] == '0')
				prog->data.total_empty += 1;
			if (prog->map.map[i][j] == '1')
				prog->data.total_wall += 1;
			if (prog->map.map[i][j] == 'E')
				prog->data.total_exit += 1;
			if (prog->map.map[i][j] == 'C')
				prog->data.total_collect += 1;
			j++;
		}
		i++;
	}
}
