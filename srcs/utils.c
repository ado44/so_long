/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:59:23 by amarna            #+#    #+#             */
/*   Updated: 2023/01/11 17:09:15 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_img(t_program *p)
{
	mlx_destroy_image(p->mlx, p->sprite.ref_c);
	mlx_destroy_image(p->mlx, p->sprite.ref_p);
	mlx_destroy_image(p->mlx, p->sprite.ref_ex);
	mlx_destroy_image(p->mlx, p->sprite.ref_em);
	mlx_destroy_image(p->mlx, p->sprite.ref_w);
}

void	free_map(t_program *data)
{
	int	i;

	i = 0;
	if (data->map.map)
	{
		while (data->map.map[i])
		{
			free(data->map.map[i]);
			i++;
		}
		free(data->map.map);
	}
}

void	end_game(t_program *p)
{
	free_img(p);
	free_map(p);
	mlx_clear_window(p->mlx, p->window.ref);
	mlx_destroy_window(p->mlx, p->window.ref);
	mlx_destroy_display(p->mlx);
	ft_printf("You won!!\n");
	free(p->mlx);
	exit(EXIT_SUCCESS);
}
