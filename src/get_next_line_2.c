/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:58:00 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/14 15:58:07 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	switch_buff(char *temp, char **line, char **buff)
{
	if (!buff)
		return (-1);
	temp = NULL;
	if (*line)
		temp = *line;
	*line = ft_strjoin2(*line, *buff);
	if (temp)
		free(temp);
	return (1);
}

int	ft_copy(char **line, char **buff, t_gm *gm)
{
	int		start;
	char	*temp;
	char	*line_temp;

	start = ft_check(*buff);
	temp = NULL;
	line_temp = NULL;
	if (start >= 0)
	{
		temp = ft_substr(*buff, 0, start);
		line_temp = *line;
		*line = ft_strjoin2(*line, temp);
		free(temp);
		free(line_temp);
		*buff = ft_subbuff(*buff, start + 1, (ft_strlen(*buff) - start), gm);
		return (0);
	}
	else
		return (switch_buff(temp, line, buff));
	return (-1);
}
