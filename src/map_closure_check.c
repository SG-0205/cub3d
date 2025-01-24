/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closure_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:28:18 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/01/24 14:34:11 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <fcntl.h>

void	init_iterators(int *imax, int *jmax, t_gm *gm)
{
	int	i;
	int	j;
	int	p_j;

	i = -1;
	j = -1;
	*imax = 0;
	*jmax = 0;
	p_j = 0;
	while (gm->map[++i])
	{
		*imax = i;
		while (gm->map[i][++j])
		{
			p_j = j;
		}
		if (p_j > *jmax)
			*jmax = p_j;
		j = -1;
	}
}

int	check_border(char *border, int *jmax)
{
	int	i;

	if (!border || !*border)
		return (0);
	i = -1;
	while (++i < *jmax)
		if (border[i] != '1')
			return (1);
	return (0);
}

static int	is_supported_char(char *to_test)
{
	char	value;

	value = *to_test;
	if (value == ' ' || value == '\t' || value == '\r' || value == 'N'
		|| value == 'S' || value == 'E' || value == 'W' || value == '1')
		return (1);
	return (0);
}

int	floodfill(t_gm *gm, int x, int y, int *max)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (!gm)
		return (-1);
	if ((((x > max[0] || !gm->map[x][y]) && gm->map[x - 1][y] != '1')
			|| ((y > max[1] || !gm->map[x][y]) && gm->map[x][y - 1] != '1')))
		ft_error(gm, "Map isn't fully bordered by walls.\n");
	if (is_supported_char(&gm->map[x][y]))
		return (1);
	else if (gm->map[x][y] == '*')
		return (1);
	gm->map[x][y] = '*';
	up = floodfill(gm, x - 1, y, max);
	down = floodfill(gm, x + 1, y, max);
	left = floodfill(gm, x, y - 1, max);
	right = floodfill(gm, x, y + 1, max);
	return (up && down && left && right);
}

void	map_closure_check(t_gm *gm, char *file)
{
	int	x;
	int	y;
	int	xmax;
	int	ymax;

	if (!gm || !file)
		return ;
	x = -1;
	y = -1;
	init_iterators(&xmax, &ymax, gm);
	while (gm->map[++x])
	{
		while (gm->map[x][++y])
			if (gm->map[x][y] == '0')
				floodfill(gm, x, y, (int [2]){xmax, ymax});
		y = -1;
	}
	x = y;
	while (gm->map[++x])
	{
		while (gm->map[x][++y])
			if (gm->map[x][y] == '*')
				gm->map[x][y] = '0';
		y = -1;
	}
}
