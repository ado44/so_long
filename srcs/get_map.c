/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:19:55 by amarna            #+#    #+#             */
/*   Updated: 2023/04/06 14:34:42 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_size(char *av[], t_data *v)
{
	int			fd;
	char		*map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_return(v, 8);
	map = get_next_line(fd);
	if (!map)
		error_return(v, 9);
	v->m.x = (int)ft_strlen(map);
	free(map);
	v->m.y = 1;
	while (map)
	{
		map = get_next_line(fd);
		if (map)
			v->m.y++;
		free(map);
	}
	close(fd);
}

char	**get_map(char *av[], t_data *v)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	get_size(av, v);
	map = malloc(v->m.y * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_return(v, 8);
	map[i] = get_next_line(fd);
	i++;
	while (i < v->m.y)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
