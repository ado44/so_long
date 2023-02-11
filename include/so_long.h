/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:46:51 by amarna            #+#    #+#             */
/*   Updated: 2023/02/10 18:24:59 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window
{
	void		*ref;
	t_vector	size;
}				t_window;

typedef struct s_image
{
	void		*ref_w;
	void		*ref_p;
	void		*ref_ex;
	void		*ref_em;
	void		*ref_c;
	int			x;
	int			y;
	t_vector	size;
}				t_image;

typedef struct s_map
{
	char	**map;
	char	**tmp;
	int		width;
	int		w_tmp;
	int		h_tmp;
	int		height;
	int		player_pos_x;
	int		pos_x;
	int		player_pos_y;
	int		pos_y;
	int		exit_x;
	int		exit_y;
}				t_map;

typedef struct s_data
{
	char	wall;
	char	player;
	char	empty;
	char	collect;
	char	exit;
	int		total_wall;
	int		total_empty;
	int		total_player;
	int		total_exit;
	int		total_collect;
	int		total_move;
}				t_data;

typedef struct s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
	t_map		map;
	t_data		data;
}				t_program;

t_window	ft_new_window(void *mlx, int widht, int height, char *name);
int			ft_closes(t_program *p);
int			check_each_line_wall(char c, char *map);
int			check_only_wall(char c, char *map);
int			check_char(char *map);
int			check_only_one_char(char c, char **map);
int			check_form(char **map);
int			ft_input(int key, t_program *p);
int			render(t_program *prog);
int			render_scnd(t_program *prog);
int			render_p(t_program *prog);
int			render_all(t_program *prog);
char		**get_map(int fd, t_program prog);
void		err_msg_2(char *s);
void		err_msg(char *s);
void		check_ber(char *filename);
void		ft_close(int fd);
void		count_all(t_program *prog);
int			put_data(t_program *p);
void		end_game(t_program *data);
void		display_img(t_program *p, void *s, int a, int b);
int			right(t_program *p);
int			left(t_program *p);
int			up(t_program *p);
int			down(t_program *p);
void		free_map(t_program *data);
void		free_img(t_program *p);
void		err_img(char *s, t_program *p);
void		is_playable(char *av[], t_program *v);
char		**get_map_tmp(char *av[], t_program *prog);
void		set_data(t_program *p);
void		set_exit(t_program *prog);
int			handle_kp(int keysym, t_program *p);
void		map_info(t_program *p);
void		free_all(t_program *p);

#endif