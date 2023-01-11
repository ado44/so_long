/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:37:30 by amarna            #+#    #+#             */
/*   Updated: 2023/01/11 11:30:28 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_closes(t_program *p)
{
	free_img(p);
	free_map(p);
	mlx_clear_window(p->mlx, p->window.ref);
	mlx_destroy_window(p->mlx, p->window.ref);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	exit(0);
}

t_window	ft_new_window(void *mlx, int width, int height, char *name)
{
	t_window	window;

	window.ref = mlx_new_window(mlx, width * 60, height * 60, name);
	return (window);
}
