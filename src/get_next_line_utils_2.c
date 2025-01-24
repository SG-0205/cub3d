/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:03:37 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 14:34:30 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	prepare_buff(char **buff)
{
	if (*buff)
		return (1);
	*buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buff))
		return (-1);
	return (0);
}

int	handle_existing_buff(char **line, char **buff, t_gm *gm)
{
	if (*buff)
	{
		if (!ft_copy(line, buff, gm))
			return (1);
	}
	return (0);
}

int	read_and_process(int fd, char **line, char **buff, t_gm *gm)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, *buff, BUFFER_SIZE);
		if (ret > 0)
		{
			(*buff)[ret] = '\0';
			if (!ft_copy(line, buff, gm))
				return (1);
		}
	}
	return (ret);
}
