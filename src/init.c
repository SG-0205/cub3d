/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:24:36 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 14:32:36 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_game(t_gm *gm)
{
	gm->north = NULL;
	gm->south = NULL;
	gm->west = NULL;
	gm->east = NULL;
	gm->f = -1;
	gm->c = -1;
	gm->rx = 0;
	gm->ry = 0;
	gm->nblines = 0;
	gm->sizeline = 0;
	gm->map = NULL;
	gm->dx = 0;
	gm->dy = 0;
	gm->multiple_player = 0;
	gm->empty_line = 0;
	gm->insidemap = 0;
	gm->count = 0;
	gm->sum = 0;
	gm->wrongcharmap = 0;
	ft_init_game_2(gm);
}

static void	init_t(t_gm *gm)
{
	gm->t.step = 0;
	gm->t.texdir = 0;
	gm->t.texpos = 0;
	gm->t.texx = 0;
	gm->t.texy = 0;
	gm->t.wallx = 0;
}

void	ft_init_game_2(t_gm *gm)
{
	gm->starting_pos = 'x';
	gm->nb_v_lines = 0;
	gm->ierror2 = 0;
	gm->ierror3 = 0;
	gm->data.img = NULL;
	gm->data.img2 = NULL;
	gm->texture[0].img = NULL;
	gm->texture[1].img = NULL;
	gm->texture[2].img = NULL;
	gm->texture[3].img = NULL;
	gm->texture[4].img = NULL;
	gm->data.mlx_win = NULL;
	gm->data.mlx_ptr = NULL;
	gm->map = NULL;
	gm->gnl_buff_link = NULL;
	gm->gnl_internal_link = NULL;
	gm->strjoin_link = NULL;
	init_t(gm);
}

void	ft_init_game_3(t_gm *gm)
{
	double	a;
	double	b;

	a = 0;
	b = 0;
	if (gm->ray.raydiry == 0)
		gm->ray.deltadistx = 0;
	else if (gm->ray.raydirx == 0)
		gm->ray.deltadistx = 1;
	else
	{
		a = gm->ray.raydiry * gm->ray.raydiry;
		b = gm->ray.raydirx * gm->ray.raydirx;
		gm->ray.deltadistx = sqrt(1 + a / b);
	}
	if (gm->ray.raydirx == 0)
		gm->ray.deltadisty = 0;
	else if (gm->ray.raydiry == 0)
		gm->ray.deltadisty = 1;
	else
	{
		a = gm->ray.raydirx * gm->ray.raydirx;
		b = gm->ray.raydiry * gm->ray.raydiry;
		gm->ray.deltadisty = sqrt(1 + a / b);
	}
}

void	ft_init_direction(t_gm *gm)
{
	if (gm->starting_pos == 'x')
	{
		if (!gm->map)
			ft_error(gm, "No starting position in map.");
		else
			ft_error(gm, "Invalid data order");
	}
	if (gm->starting_pos == 'N')
		gm->ray.dirx = -1;
	if (gm->starting_pos == 'S')
		gm->ray.dirx = 1;
	if (gm->starting_pos == 'E')
		gm->ray.diry = 1;
	if (gm->starting_pos == 'W')
		gm->ray.diry = -1;
	if (gm->starting_pos == 'N')
		gm->ray.plany = 0.66;
	if (gm->starting_pos == 'S')
		gm->ray.plany = -0.66;
	if (gm->starting_pos == 'E')
		gm->ray.planx = 0.66;
	if (gm->starting_pos == 'W')
		gm->ray.planx = -0.66;
}
