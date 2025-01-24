/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:27:57 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/20 16:38:16 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_initialisation2(t_gm *gm)
{
	gm->data.forward = 0;
	gm->data.back = 0;
	gm->data.left = 0;
	gm->data.right = 0;
	gm->data.rotate_right = 0;
	gm->data.rotate_left = 0;
	gm->ray.posx = (double)gm->dx + 0.5;
	gm->ray.posy = (double)gm->dy + 0.5;
	gm->ray.dirx = 0;
	gm->ray.diry = 0;
	gm->ray.planx = 0;
	gm->ray.plany = 0;
	gm->ray.texx = 0;
	ft_init_direction(gm);
}

void	ft_initialisation3(t_gm *gm)
{
	gm->ray.hit = 0;
	gm->ray.perpwalldist = 0;
	gm->ray.camerax = 2 * gm->ray.x / (double)gm->rx - 1;
	gm->ray.raydirx = gm->ray.dirx + gm->ray.planx * gm->ray.camerax;
	gm->ray.raydiry = gm->ray.diry + gm->ray.plany * gm->ray.camerax;
	gm->ray.mapx = (int)gm->ray.posx;
	gm->ray.mapy = (int)gm->ray.posy;
	gm->ray.movespeed = 0.1;
	gm->ray.rotspeed = 0.033 * 1.8;
	ft_init_game_3(gm);
}

void	ft_init_texture(t_gm *gm)
{
	if (gm->ray.side == 0 && gm->ray.raydirx < 0)
		gm->t.texdir = 0;
	if (gm->ray.side == 0 && gm->ray.raydirx >= 0)
		gm->t.texdir = 1;
	if (gm->ray.side == 1 && gm->ray.raydiry < 0)
		gm->t.texdir = 2;
	if (gm->ray.side == 1 && gm->ray.raydiry >= 0)
		gm->t.texdir = 3;
	if (gm->ray.side == 0)
		gm->t.wallx = gm->ray.posy + gm->ray.perpwalldist * gm->ray.raydiry;
	else
		gm->t.wallx = gm->ray.posx + gm->ray.perpwalldist * gm->ray.raydirx;
	gm->t.wallx -= floor((gm->t.wallx));
}
