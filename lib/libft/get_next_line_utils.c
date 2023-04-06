/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:41:15 by amarna            #+#    #+#             */
/*   Updated: 2023/01/11 13:01:56 by amarna           ###   ########.fr       */
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

/*If this function is called, it means we know for a fact that there is a \n
in the static variable
(or that there is nothing left to read in the file). We will extract
the characters up to the \n to get the line we must later return*/

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
/*As with the previous function, by the time we call this function,
we know that there is a \n in the static variable. If we have reached the end
of the file, there is no need to call this function because we will end up
returning the last line with the previous function. We must now “reset”
the static variable by taking all the characters after the \n*/

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
