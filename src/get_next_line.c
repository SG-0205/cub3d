/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:23:45 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 14:34:44 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_eof(int ret, char **buff, char **line)
{
	if (ret == -1)
		return (-1);
	if (*buff)
	{
		free(*buff);
		*buff = NULL;
	}
	if (*line == NULL)
	{
		*line = malloc(sizeof(char) * 1);
		*line[0] = 0;
	}
	return (0);
}

int	ft_free_buff(char **buff, t_gm *gm)
{
	if (gm->erreur == 2 && *buff)
	{
		free(*buff);
		gm->gnl_buff_link = NULL;
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line, t_gm *gm)
{
	static char	*buff;
	int			ret;

	if (ft_free_buff(&buff, gm) == 1)
		return (0);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	if (handle_existing_buff(line, &buff, gm) == 1)
		return (1);
	if (prepare_buff(&buff) == -1)
		return (-1);
	ret = read_and_process(fd, line, &buff, gm);
	if (ret <= 0)
		return (ft_eof(ret, &buff, line));
	if (buff)
		gm->gnl_buff_link = &buff;
	return (1);
}
