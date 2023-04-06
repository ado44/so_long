/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:20:20 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:36:46 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	set_data(t_data *v)
{
	v->x.img_0 = NULL;
	v->x.img_1 = NULL;
	v->x.img_e = NULL;
	v->x.img_c = NULL;
	v->x.img_p = NULL;
	v->move_counter = 0;
}

void	set_sprites(t_data *v)
{
	v->x.img_0 = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_0.xpm",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_0)
		error_return(v, 12);
	v->x.img_1 = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_1.xpm",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_1)
		error_return(v, 12);
	v->x.img_e = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_e.xpm",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_e)
		error_return(v, 12);
	v->x.img_c = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_c.xpm",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_c)
		error_return(v, 12);
	v->x.img_p = mlx_xpm_file_to_image(v->x.mlx, "./sprites/img_p.xpm",
			&v->x.img_pxl, &v->x.img_pxl);
	if (!v->x.img_p)
		error_return(v, 12);
}

void	get_sprites(t_data *v)
{
	set_data(v);
	set_sprites(v);
}
