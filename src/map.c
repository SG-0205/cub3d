/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:26:19 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 14:34:06 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_wall(t_gm *gm)
{
	int	i;

	i = 0;
	while (i < gm->nblines)
	{
		if (gm->map[i][0] != '1')
			return (1);
	i++;
	}
	i = 0;
	while (i < gm->nblines)
	{
		if (gm->map[i][gm->sizeline - 1] != '1')
			return (1);
		i++;
	}
	if (ft_wall_util(gm->map[0]) == 1)
		return (1);
	if (ft_wall_util(gm->map[gm->nblines - 1]) == 1)
		return (1);
	return (0);
}

int	ft_copy_map(char *str, t_gm *gm)
{
	static int	i;
	int			j;

	j = -1;
	gm->nb_v_lines = i;
	gm->map[i] = malloc(sizeof(char) * (gm->sizeline + 1));
	if (!gm->map[i])
		return (0);
	while (str[++j] != '\0')
	{
		if (ft_starting_pos(str[j], gm, i, j) == 1 || str[j] == '0')
			gm->map[i][j] = '0';
		else if (str[j] == ' ' || str[j] == '1')
		{
			gm->map[i][j] = '1';
			if (str[j] == ' ')
				printf("Warning: spaces inside of map @[%d][%d]" \
						"replacing with 1...\n", i, j);
		}
		else
		gm->map[i][j] = str[j];
	}
	gm->map[i][j] = '\0';
	i++;
	return (0);
}

int	ft_is_map(char *str, t_gm *gm)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' && \
				str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && \
				str[i] != 'W' && str[i] != '\n' && str[i] != '\t')
			{
				if (gm->insidemap == 1)
				{
					gm->wrongcharmap = 2;
					ft_error(gm, "Invalid character in map.");
				}
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_map(char *str, t_gm *gm)
{
	int			i;
	static int	snblines;
	static int	ssizeline;

	i = 0;
	if (ft_is_map(str, gm) == 1)
	{
		if (gm->f == -1 || gm->c == -1 || gm->north == NULL || \
		gm->south == NULL || gm->west == NULL || gm->east == NULL)
		gm->erreur = 2;
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	gm->nblines = snblines;
	gm->sizeline = ssizeline;
}
