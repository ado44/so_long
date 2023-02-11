/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:41:55 by amarna            #+#    #+#             */
/*   Updated: 2023/02/10 11:18:56 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	up(t_program *p)
{
	if (p->map.map[p->map.player_pos_x -1][p->map.player_pos_y] == 'E' &&
		p->data.total_collect == 0)
		end_game(p);
	if (p->map.map[p->map.player_pos_x -1][p->map.player_pos_y] == 'E'
		|| p->map.map[p->map.player_pos_x -1][p->map.player_pos_y] == '1')
		return (-1);
	if (p->map.map[p->map.player_pos_x - 1][p->map.player_pos_y] == 'C'
			||p->map.map[p->map.player_pos_x - 1][p->map.player_pos_y] == '0')
	{
		if (p->map.map[p->map.player_pos_x - 1][p->map.player_pos_y] == 'C')
			p->data.total_collect -= 1;
		p->map.map[p->map.player_pos_x][p->map.player_pos_y] = '0';
		p->map.map[p->map.player_pos_x - 1][p->map.player_pos_y] = 'P';
		p->map.player_pos_x -= 1;
	}
	return (1);
}

int	down(t_program *p)
{
	if (p->map.map[p->map.player_pos_x + 1][p->map.player_pos_y] == 'E' &&
		p->data.total_collect == 0)
		end_game(p);
	if (p->map.map[p->map.player_pos_x + 1][p->map.player_pos_y] == 'E'
		|| p->map.map[p->map.player_pos_x + 1][p->map.player_pos_y] == '1')
		return (-1);
	if (p->map.map[p->map.player_pos_x + 1][p->map.player_pos_y] == 'C'
			||p->map.map[p->map.player_pos_x + 1][p->map.player_pos_y] == '0')
	{
		if (p->map.map[p->map.player_pos_x + 1][p->map.player_pos_y] == 'C')
			p->data.total_collect -= 1;
		p->map.map[p->map.player_pos_x][p->map.player_pos_y] = '0';
		p->map.map[p->map.player_pos_x + 1][p->map.player_pos_y] = 'P';
		p->map.player_pos_x += 1;
	}
	return (1);
}

int	right(t_program *p)
{
	if (p->map.map[p->map.player_pos_x][p->map.player_pos_y + 1] == 'E' &&
		p->data.total_collect == 0)
		end_game(p);
	if (p->map.map[p->map.player_pos_x][p->map.player_pos_y + 1] == 'E'
		|| p->map.map[p->map.player_pos_x][p->map.player_pos_y + 1] == '1')
		return (-1);
	if (p->map.map[p->map.player_pos_x][p->map.player_pos_y + 1] == 'C'
			||p->map.map[p->map.player_pos_x][p->map.player_pos_y + 1] == '0')
	{
		if (p->map.map[p->map.player_pos_x][p->map.player_pos_y + 1] == 'C')
			p->data.total_collect -= 1;
		p->map.map[p->map.player_pos_x][p->map.player_pos_y] = '0';
		p->map.map[p->map.player_pos_x][p->map.player_pos_y + 1] = 'P';
		p->map.player_pos_y += 1;
	}
	return (1);
}

int	left(t_program *p)
{
	if (p->map.map[p->map.player_pos_x][p->map.player_pos_y - 1] == 'E' &&
		p->data.total_collect == 0)
		end_game(p);
	if (p->map.map[p->map.player_pos_x][p->map.player_pos_y -1] == 'E'
		|| p->map.map[p->map.player_pos_x][p->map.player_pos_y -1] == '1')
		return (-1);
	if (p->map.map[p->map.player_pos_x][p->map.player_pos_y - 1] == 'C'
			||p->map.map[p->map.player_pos_x][p->map.player_pos_y - 1] == '0')
	{
		if (p->map.map[p->map.player_pos_x][p->map.player_pos_y - 1] == 'C')
			p->data.total_collect -= 1;
		p->map.map[p->map.player_pos_x][p->map.player_pos_y] = '0';
		p->map.map[p->map.player_pos_x][p->map.player_pos_y - 1] = 'P';
		p->map.player_pos_y -= 1;
	}
	return (1);
}
