/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:26:47 by armeyer           #+#    #+#             */
/*   Updated: 2024/12/19 09:05:20 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strlen2(char *str)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_starting_pos_2(char c, t_gm *gm)
{
	if (c == 'N')
	{
		gm->ray.dirx = 0;
		gm->ray.diry = -1;
	}
	else if (c == 'S')
	{
		gm->ray.dirx = 0;
		gm->ray.diry = 1;
	}
	else if (c == 'E')
	{
		gm->ray.dirx = 1;
		gm->ray.diry = 0;
	}
	else if (c == 'W')
	{
		gm->ray.dirx = -1;
		gm->ray.diry = 0;
	}
	return (0);
}

int	ft_starting_pos(char c, t_gm *gm, int i, int j)
{
	static int	start_count;

	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (gm->starting_pos != 'x')
			gm->multiple_player = 1;
		gm->starting_pos = c;
		gm->dx = i;
		gm->dy = j;
		start_count++;
		if (start_count > 1)
		{
			gm->nblines = i;
			ft_error(gm, "Multiple starting points detected.");
			return (2);
		}
		ft_starting_pos_2(c, gm);
		return (1);
	}
	return (0);
}

int	ft_wall_util(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
