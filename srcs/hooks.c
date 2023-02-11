/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:33:05 by amarna            #+#    #+#             */
/*   Updated: 2023/02/11 17:49:30 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_kp(int keysym, t_program *p)
{
	if (keysym == XK_Escape)
	{
		free_img(p);
		free_map(p);
		mlx_clear_window(p->mlx, p->window.ref);
		mlx_destroy_window(p->mlx, p->window.ref);
		mlx_destroy_display(p->mlx);
		free(p->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_input(int key, t_program *p)
{
	char	*str;

	if (key == XK_w || key == XK_Up)
		if (up(p) == 1)
			p->data.total_move++;
	if (key == XK_d || key == XK_Right)
		if (right(p) == 1)
			p->data.total_move++;
	if (key == XK_a || key == XK_Left)
		if (left(p) == 1)
			p->data.total_move++;
	if (key == XK_s || key == XK_Down)
		if (down(p) == 1)
			p->data.total_move++;
	str = ft_itoa(p->data.total_move);
	ft_putendl_fd(str, 1);
	mlx_clear_window(p->mlx, p->window.ref);
	render_all(p);
	free(str);
	return (0);
}

void	map_info(t_program *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p->map.map[i])
		i++;
	p->map.height = i;
	j = ft_strlen(p->map.map[0]);
	p->map.width = j;
}
