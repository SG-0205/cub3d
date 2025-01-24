/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:27:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/01/24 11:38:52 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_buff(char **buff)
{
	if (!*buff)
	{
		*buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!(*buff))
			return (-1);
	}
	return (0);
}

int	gnl_final_check(int *ret, char *buff, char **line)
{
	if (*ret <= 0)
		return (ft_eof(*ret, &buff, line));
	else
		return (1);
}

int	gnl_initial_check(char *buff, char **line, t_gm *gm, int *fd)
{
	if (ft_free_buff(&buff, gm) == 1)
		return (0);
	if (*fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	return (-2);
}
