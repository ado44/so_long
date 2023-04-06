/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:19:39 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:31:42 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_return2(t_data *v, int n)
{
	if (n == 10)
		ft_putendl_fd("Error\nThe map is not big enough.\n", 2);
	if (n == 11)
		ft_putendl_fd("Error\nThe map is too big.\n", 2);
	if (n == 12)
	{
		destroy_images(v);
		ft_putendl_fd("Error\nUnable to initialize sprites.\n", 2);
	}
	if (n == 13)
	{
		free_mlx(v);
		ft_putendl_fd("Error\nUnable to initialize a new window.\n", 2);
	}
	free(v);
	exit(EXIT_FAILURE);
}

void	error_return(t_data *v, int n)
{
	if (v->m.map)
		free_map(v);
	if (n == 0)
		ft_putendl_fd("Error\nUnable to initialize minilibx.\n", 2);
	if (n == 1)
		ft_putendl_fd("Error\nThe map is not a rectangle.\n", 2);
	if (n == 2)
		ft_putendl_fd("Error\nThe map is not surrounded by walls.\n", 2);
	if (n == 3)
		ft_putendl_fd("Error\nThe map contains unknown elements.\n", 2);
	if (n == 4)
		ft_putendl_fd("Error\nThe map does not contain only one exit.\n", 2);
	if (n == 5)
		ft_putendl_fd("Error\nThe map does not contain only one player.\n", 2);
	if (n == 6)
		ft_putendl_fd("Error\nThe map does not contain any collectibles.\n", 2);
	if (n == 7)
		ft_putendl_fd("Error\nThe map is not playable.\n", 2);
	if (n == 8)
		ft_putendl_fd("Error\nCould not open file descriptor.\n", 2);
	if (n == 9)
		ft_putendl_fd("Error\nThe map is empty.\n", 2);
	error_return2(v, n);
}
