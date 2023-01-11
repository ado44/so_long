/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:27:11 by amarna            #+#    #+#             */
/*   Updated: 2023/01/11 17:26:40 by amarna           ###   ########.fr       */
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
	if (key == XK_w || key == XK_Up)
		up(p);
	if (key == XK_d || key == XK_Right)
		right(p);
	if (key == XK_a || key == XK_Left)
		left(p);
	if (key == XK_s || key == XK_Down)
		down(p);
	mlx_clear_window(p->mlx, p->window.ref);
	render_all(p);
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

int	main(int ac, char *av[])
{
	t_program	prog;
	int			fd;

	if (ac != 2)
		err_msg("Error\nUse only 2 arguments.");
	check_ber(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		err_msg("Error\nCannot open the file");
	prog.map.map = get_map(fd, prog);
	if (prog.map.map == NULL)
		exit(EXIT_FAILURE);
	prog.mlx = mlx_init();
	put_data(&prog);
	count_all(&prog);
	map_info(&prog);
	prog.window = ft_new_window(prog.mlx, prog.map.width, prog.map.height,
			"so_long");
	mlx_key_hook(prog.window.ref, *ft_input, &prog);
	mlx_loop_hook(prog.mlx, &render_all, &prog);
	mlx_hook(prog.window.ref, KeyPress, KeyPressMask, &handle_kp, &prog);
	mlx_hook(prog.window.ref, 17, 0, &ft_closes, &prog);
	mlx_loop(prog.mlx);
}
