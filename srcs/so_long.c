/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:27:11 by amarna            #+#    #+#             */
/*   Updated: 2023/02/11 17:44:00 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_all(t_program prog)
{
	prog.mlx = mlx_init();
	if (!prog.mlx)
		free_map(&prog);
	if (put_data(&prog) == -1)
		err_img("Error\nCannot use the image.", &prog);
	prog.window = ft_new_window(prog.mlx, prog.map.width, prog.map.height,
			"so_long");
	ft_printf("Total moves : \n");
	mlx_key_hook(prog.window.ref, *ft_input, &prog);
	mlx_loop_hook(prog.mlx, &render_all, &prog);
	mlx_hook(prog.window.ref, KeyPress, KeyPressMask, &handle_kp, &prog);
	mlx_hook(prog.window.ref, 17, 0, &ft_closes, &prog);
	mlx_loop(prog.mlx);
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
	close(fd);
	if (prog.map.map == NULL)
		exit(EXIT_FAILURE);
	set_data(&prog);
	is_playable(av, &prog);
	map_info(&prog);
	count_all(&prog);
	display_all(prog);
	return (0);
}
