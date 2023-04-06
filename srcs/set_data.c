/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:20:09 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:31:42 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	end_move(t_data *v, int y, int x)
{
	ft_printf("Moves : %d\n", v->move_counter + 1);
	if (v->m.map[y][x] == 'E')
		ft_printf("YOU WIN !\n");
	else
		ft_printf("GAME OVER !\n");
	v->m.map[y][x] = 'P';
	v->m.map[v->m.y_pos][v->m.x_pos] = '0';
	display_objects(v);
	free_mlx(v);
}

void	normal_move(t_data *v, int y, int x)
{
	if (v->m.map[y][x] == 'C')
		v->m.item--;
	v->m.map[y][x] = 'P';
	if (v->m.y_pos != v->m.y_exit || v->m.x_pos != v->m.x_exit)
		v->m.map[v->m.y_pos][v->m.x_pos] = '0';
	v->m.x_pos = x;
	v->m.y_pos = y;
}

void	move(t_data *v, int y, int x)
{
	if (v->m.map[y][x] != '1')
	{
		if (v->m.y_pos == v->m.y_exit && v->m.x_pos == v->m.x_exit)
			v->m.map[v->m.y_pos][v->m.x_pos] = 'E';
		if (v->m.map[y][x] == 'E' && !v->m.item)
			end_move(v, y, x);
		if (v->m.map[y][x] == 'C' || v->m.map[y][x] == '0')
			normal_move(v, y, x);
		if (v->m.map[y][x] == 'E')
		{
			v->m.map[y][x] = 'P';
			v->m.map[v->m.y_pos][v->m.x_pos] = '0';
			v->m.x_pos = x;
			v->m.y_pos = y;
		}
		v->move_counter++;
		ft_printf("Moves : %d\n", v->move_counter);
		display_objects(v);
	}
	else
		put_object_to_window(v, v->m.y_pos, v->m.x_pos);
}

int	keypress_events(int keysym, t_data *v)
{
	if (keysym == XK_W || keysym == XK_w)
		move(v, v->m.y_pos - 1, v->m.x_pos);
	if (keysym == XK_S || keysym == XK_s)
		move(v, v->m.y_pos + 1, v->m.x_pos);
	if (keysym == XK_A || keysym == XK_a)
		move(v, v->m.y_pos, v->m.x_pos - 1);
	if (keysym == XK_D || keysym == XK_d)
		move(v, v->m.y_pos, v->m.x_pos + 1);
	if (keysym == XK_Escape)
		free_mlx(v);
	return (0);
}
