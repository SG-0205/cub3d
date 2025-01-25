/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:28:28 by armeyer           #+#    #+#             */
/*   Updated: 2024/12/13 15:03:10 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_forward_back(t_gm *gm)
{
	if (gm->data.forward == 1)
	{
		if (gm->map[(int)(gm->ray.posx + (gm->ray.dirx * gm->ray.movespeed
					* 2))][(int)gm->ray.posy] == '0')
			gm->ray.posx += gm->ray.dirx * gm->ray.movespeed;
		if (gm->map[(int)(gm->ray.posx)][(int)(gm->ray.posy +
												(gm->ray.diry
														* gm->ray.movespeed
														* 2))] == '0')
			gm->ray.posy += gm->ray.diry * gm->ray.movespeed;
	}
	if (gm->data.back == 1)
	{
		if (gm->map[(int)(gm->ray.posx - (gm->ray.dirx * gm->ray.movespeed
					* 2))][(int)(gm->ray.posy)] == '0')
			gm->ray.posx -= gm->ray.dirx * gm->ray.movespeed;
		if (gm->map[(int)(gm->ray.posx)][(int)(gm->ray.posy -
												(gm->ray.diry
														* gm->ray.movespeed
														* 2))] == '0')
			gm->ray.posy -= gm->ray.diry * gm->ray.movespeed;
	}
}

void	ft_left_right(t_gm *gm)
{
	if (gm->data.right == 1)
	{
		if (gm->map[(int)(gm->ray.posx + gm->ray.diry * (gm->ray.movespeed
					* 2))][(int)gm->ray.posy] == '0')
			gm->ray.posx += gm->ray.diry * gm->ray.movespeed;
		if (gm->map[(int)gm->ray.posx][(int)(gm->ray.posy -
												gm->ray.dirx
													* (gm->ray.movespeed
														* 2))] == '0')
			gm->ray.posy -= gm->ray.dirx * gm->ray.movespeed;
	}
	if (gm->data.left == 1)
	{
		if (gm->map[(int)(gm->ray.posx - gm->ray.diry * (gm->ray.movespeed
					* 2))][(int)gm->ray.posy] == '0')
			gm->ray.posx -= gm->ray.diry * gm->ray.movespeed;
		if (gm->map[(int)gm->ray.posx][(int)(gm->ray.posy +
												gm->ray.dirx
													* (gm->ray.movespeed
														* 2))] == '0')
			gm->ray.posy += gm->ray.dirx * gm->ray.movespeed;
	}
}

void	ft_rotate_right_left(t_gm *gm)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = gm->ray.planx;
	olddirx = gm->ray.dirx;
	if (gm->data.rotate_right == 1)
	{
		gm->ray.dirx = gm->ray.dirx * cos(-gm->ray.rotspeed / 2) -
			gm->ray.diry * sin(-gm->ray.rotspeed / 2);
		gm->ray.diry = olddirx * sin(-gm->ray.rotspeed / 2) +
			gm->ray.diry * cos(-gm->ray.rotspeed / 2);
		gm->ray.planx = gm->ray.planx * cos(-gm->ray.rotspeed / 2)
			- gm->ray.plany * sin(-gm->ray.rotspeed / 2);
		gm->ray.plany = oldplanx * sin(-gm->ray.rotspeed / 2) +
			gm->ray.plany * cos(-gm->ray.rotspeed / 2);
	}
	ft_rotate_left(gm, olddirx);
}

void	ft_rotate_left(t_gm *gm, double olddirx)
{
	double	oldplanex;

	if (gm->data.rotate_left == 1)
	{
		olddirx = gm->ray.dirx;
		oldplanex = gm->ray.planx;
		gm->ray.dirx = gm->ray.dirx * cos(gm->ray.rotspeed / 2) -
			gm->ray.diry * sin(gm->ray.rotspeed / 2);
		gm->ray.diry = olddirx * sin(gm->ray.rotspeed / 2) + gm->ray.diry
			* cos(gm->ray.rotspeed / 2);
		gm->ray.planx = gm->ray.planx * cos(gm->ray.rotspeed / 2) -
			gm->ray.plany * sin(gm->ray.rotspeed / 2);
		gm->ray.plany = oldplanex * sin(gm->ray.rotspeed / 2) +
			gm->ray.plany * cos(gm->ray.rotspeed / 2);
	}
}
