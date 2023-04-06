/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:05:42 by amarna            #+#    #+#             */
/*   Updated: 2023/01/04 16:20:45 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_from_fd(int fd, char *static_line)
{
	int		reader;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader = 1;
	while (reader)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		static_line = ft_strjoin(static_line, buffer);
		if (is_newline(static_line))
			break ;
	}
	free(buffer);
	return (static_line);
}

char	*get_next_line_bonus(int fd)
{
	static char	*line[1024];
	char		*str;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = read_from_fd(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	str = get_returned_line(line[fd]);
	line[fd] = free_str_from_stat(line[fd]);
	return (str);
}
