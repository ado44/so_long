/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:03:49 by amarna            #+#    #+#             */
/*   Updated: 2023/02/10 17:29:15 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*gnl(int fd)
{
	char	*line;
	char	*map;

	map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line)
			map = ft_join(map, line);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

int	check_all(t_program *prog)
{
	if (check_form(prog->map.map) == -1)
	{
		err_msg_2("Error\nMap must be rectangular.");
		return (-1);
	}
	if (check_only_one_char('P', prog->map.map) == -1)
	{
		err_msg_2("Error\nMust be only one player!");
		return (-1);
	}
	if (check_only_one_char('E', prog->map.map) == -1)
	{
		err_msg_2("Error\nMust be only one exit!");
		return (-1);
	}
	return (1);
}

int	check_all_scnd(t_program *prog, int i)
{
	while (prog->map.map[i])
	{
		if (check_each_line_wall('1', prog->map.map[i]) == -1)
		{
			err_msg_2("Error\nBorders must be wall.");
			return (-1);
		}
		if (check_only_wall('1', prog->map.map[0]) == -1)
		{
			err_msg_2("Error\nBorder problem");
			return (-1);
		}
		if (check_char(prog->map.map[i]) == -1)
		{
			err_msg_2("Error\nInvalid character");
			return (-1);
		}
		i++;
	}
	if (check_only_wall('1', prog->map.map[i - 1]) == -1)
	{
		err_msg_2("Error\nBorder problem");
		return (-1);
	}
	return (1);
}

char	**get_map(int fd, t_program prog)
{
	int		i;
	char	*line;

	line = gnl(fd);
	prog.map.map = ft_split(line, '\n');
	free(line);
	i = 0;
	if (check_all(&prog) == -1)
	{
		free_map(&prog);
		ft_close(fd);
		return (NULL);
	}
	if (check_all_scnd(&prog, i) == -1)
	{
		free_map(&prog);
		ft_close(fd);
		return (NULL);
	}
	ft_close(fd);
	return (prog.map.map);
}

char	**get_map_tmp(char *av[], t_program *prog)
{
	char	*line;
	char	**map;
	int		i;
	int		j;
	int		fd;

	fd = open(av[1], O_RDONLY);
	i = 0;
	j = 0;
	line = gnl(fd);
	map = ft_split(line, '\n');
	while (map[i])
		i++;
	prog->map.h_tmp = i;
	j = ft_strlen(map[0]);
	prog->map.w_tmp = j;
	free(line);
	ft_close(fd);
	return (map);
}
