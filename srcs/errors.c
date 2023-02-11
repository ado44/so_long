/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:12:34 by amarna            #+#    #+#             */
/*   Updated: 2023/02/10 18:18:36 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	err_msg(char *s)
{
	ft_putendl_fd(s, 2);
	exit (EXIT_FAILURE);
}

void	err_msg_2(char *s)
{
	ft_putendl_fd(s, 2);
}

void	err_img(char *s, t_program *p)
{
	ft_putendl_fd(s, 2);
	free_img(p);
	free_map(p);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	exit(EXIT_SUCCESS);
}

void	check_ber(char *filename)
{
	int		len;
	int		old_len;
	int		j;
	char	*ber;

	old_len = ft_strlen(filename);
	len = old_len - 4;
	ber = ".ber";
	j = 0;
	if (old_len < 5)
		err_msg("Error.\nUse a .ber file!");
	while (filename[len] != '\0' && ber[j] != '\0')
	{
		if (filename[len] != ber[j])
			err_msg("Error.\nOnly .ber extension as second argument.");
		len++;
		j++;
	}
}
