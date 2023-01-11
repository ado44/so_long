/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:46:28 by amarna            #+#    #+#             */
/*   Updated: 2023/01/11 09:46:00 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_each_line_wall(char c, char *map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	if (map[0] == c && map[j - 1] == c)
		return (1);
	return (-1);
}

int	check_only_wall(char c, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != c)
			return (-1);
		i++;
	}
	return (1);
}

int	check_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != 'P' && map[i] != 'C' && map[i] != '0' && map[i] != 'E'
			&& map[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	check_only_one_char(char c, char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		return (-1);
	return (1);
}

int	check_form(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	j = 0;
	x = 0;
	while (map[0][x])
		x++;
	while (map[i] != NULL)
	{
		while (map[i][j])
			j++;
		if (j != x)
			return (-1);
		j = 0;
		i++;
	}
	return (1);
}
