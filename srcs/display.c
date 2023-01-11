/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:57:11 by amarna            #+#    #+#             */
/*   Updated: 2023/01/11 09:43:56 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_img(t_program *p, void *s, int a, int b)
{
	mlx_put_image_to_window(p->mlx, p->window.ref, s, a * p->sprite.y, b
		* p->sprite.x);
}

int	render(t_program *prog)
{
	int	x;
	int	y;

	x = 0;
	while (prog->map.map[x])
	{
		y = 0;
		while (prog->map.map[x][y])
		{
			if (prog->map.map[x][y] == 'C')
				display_img(prog, prog->sprite.ref_c, y, x);
			if (prog->map.map[x][y] == 'E')
				display_img(prog, prog->sprite.ref_ex, y, x);
			y++;
		}
		x++;
	}
	return (0);
}

int	render_scnd(t_program *prog)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (prog->map.map[x])
	{
		y = 0;
		while (prog->map.map[x][y])
		{
			if (prog->map.map[x][y] == '0')
				display_img(prog, prog->sprite.ref_em, y, x);
			if (prog->map.map[x][y] == '1')
				display_img(prog, prog->sprite.ref_w, y, x);
			y++;
		}
		x++;
	}
	return (0);
}

int	render_p(t_program *prog)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (prog->map.map[x])
	{
		y = 0;
		while (prog->map.map[x][y])
		{
			if (prog->map.map[x][y] == 'P')
			{	
				display_img(prog, prog->sprite.ref_p, y, x);
				prog->map.player_pos_x = x;
				prog->map.player_pos_y = y;
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	render_all(t_program *prog)
{
	render_scnd(prog);
	render(prog);
	render_p(prog);
	return (0);
}
