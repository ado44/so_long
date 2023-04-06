/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:19:50 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:34:03 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tmp(char **map, t_data *v)
{
	int	i;

	i = 0;
	while (i < v->m.y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(t_data *v)
{
	int	i;

	i = 0;
	while (i < v->m.y)
	{
		free(v->m.map[i]);
		i++;
	}
	free(v->m.map);
}

int	free_mlx(t_data *v)
{
	mlx_destroy_image(v->x.mlx, v->x.img_0);
	mlx_destroy_image(v->x.mlx, v->x.img_1);
	mlx_destroy_image(v->x.mlx, v->x.img_e);
	mlx_destroy_image(v->x.mlx, v->x.img_c);
	mlx_destroy_image(v->x.mlx, v->x.img_p);
	mlx_destroy_window(v->x.mlx, v->x.win);
	mlx_destroy_display(v->x.mlx);
	free(v->x.mlx);
	free_map(v);
	free(v);
	exit (0);
}

void	destroy_images(t_data *v)
{
	if (v->x.img_0)
		mlx_destroy_image(v->x.mlx, v->x.img_0);
	if (v->x.img_1)
		mlx_destroy_image(v->x.mlx, v->x.img_1);
	if (v->x.img_e)
		mlx_destroy_image(v->x.mlx, v->x.img_e);
	if (v->x.img_c)
		mlx_destroy_image(v->x.mlx, v->x.img_c);
	if (v->x.img_p)
		mlx_destroy_image(v->x.mlx, v->x.img_p);
	mlx_destroy_display(v->x.mlx);
	free(v->x.mlx);
}
