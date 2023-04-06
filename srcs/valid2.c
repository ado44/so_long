/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:20:30 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:38:17 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_rectangle(t_data *v)
{
	int	i;

	i = 1;
	if (v->m.x > 61 || v->m.y > 33)
		error_return(v, 11);
	if (v->m.x <= 3 || v->m.y < 3)
		error_return(v, 10);
	if (v->m.x - 1 == v->m.y)
		error_return(v, 1);
	while (i < v->m.y)
	{
		if ((int)ft_strlen(v->m.map[i - 1]) != v->m.x)
			error_return(v, 1);
		i++;
	}
	if ((int)ft_strlen(v->m.map[i - 1]) != v->m.x - 1)
		error_return(v, 1);
}

void	is_wall(t_data *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < v->m.y)
	{
		while (j < v->m.x - 1 && i == 0)
		{
			if (v->m.map[0][j] != '1' || v->m.map[v->m.y - 1][j] != '1')
				error_return(v, 2);
			j++;
		}
		if (v->m.map[i][0] != '1' || v->m.map[i][v->m.x - 2] != '1')
			error_return(v, 2);
		i++;
	}
}

int	get_exit(t_data *v, int i, int j, int exit)
{
	exit++;
	v->m.x_exit = j;
	v->m.y_exit = i;
	return (exit);
}

void	check_items(t_data *v, int exit, int player)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->m.y)
	{
		j = 0;
		while (v->m.map[i][j])
		{
			if (v->m.map[i][j] == 'E')
				exit = get_exit(v, i, j, exit);
			if (v->m.map[i][j] == 'P')
				player++;
			if (v->m.map[i][j] == 'C')
				v->m.item++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		error_return(v, 4);
	if (player != 1)
		error_return(v, 5);
	if (!v->m.item)
		error_return(v, 6);
}

void	is_items(t_data *v)
{
	int	exit;
	int	player;
	int	i;
	int	j;

	i = 0;
	exit = 0;
	player = 0;
	v->m.item = 0;
	while (i < v->m.y)
	{
		j = 0;
		while (v->m.map[i][j])
		{
			if (v->m.map[i][j] != '1' && v->m.map[i][j] != '0'
			&& v->m.map[i][j] != 'C' && v->m.map[i][j] != 'E'
			&& v->m.map[i][j] != 'P' && v->m.map[i][j] != '\n')
				error_return(v, 3);
			j++;
		}
		i++;
	}
	check_items(v, exit, player);
}
