/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:10:54 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:31:42 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "mlx.h"

# define IMG_SIZE 32

typedef struct s_map
{
	int		x;
	int		y;
	int		item;
	int		x_pos;
	int		y_pos;
	int		x_exit;
	int		y_exit;
	char	**map;
}	t_map;
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		img_pxl;
	void	*img_0;
	void	*img_1;
	void	*img_e;
	void	*img_c;
	void	*img_p;
	void	*img_p_top;
	void	*img_p_left;
	void	*img_p_right;
	void	*img_h;
}	t_mlx;

typedef struct s_data
{
	t_mlx	x;
	t_map	m;
	int		move_counter;
}	t_data;

char	**get_map(char *av[], t_data *v);
void	extension_check(char *str);
void	error_return(t_data *v, int n);
void	extension_check(char *str);
void	is_valid(t_data *v);
void	is_rectangle(t_data *v);
void	is_wall(t_data *v);
void	is_items(t_data *v);
void	free_map(t_data *v);
void	free_tmp(char **map, t_data *v);
int		free_mlx(t_data *v);
int		keypress_events(int keysym, t_data *v);
void	put_object_to_window(t_data *v, int y, int x);
void	destroy_images(t_data *v);
void	is_playable(char *av[], t_data *v);
void	get_sprites(t_data *v);
void	display_map(t_data *v);
void	display_objects(t_data *v);
int		display_moves(t_data *v);

#endif