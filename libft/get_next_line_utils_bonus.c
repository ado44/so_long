/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:09:08 by amarna            #+#    #+#             */
/*   Updated: 2023/01/04 16:20:37 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_returned_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		str[j] = line[j];
		j++;
	}
	if (line[j] == '\n')
	{
		str[j] = line[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*free_str_from_stat(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line)) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}
