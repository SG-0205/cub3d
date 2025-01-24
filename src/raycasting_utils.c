/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:28:57 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/21 16:18:21 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_stepsidedist(t_gm *gm)
{
	if (gm->ray.raydirx < 0)
	{
		gm->ray.stepx = -1;
		gm->ray.sidedistx = (gm->ray.posx - gm->ray.mapx) * gm->ray.deltadistx;
	}
	else
	{
		gm->ray.stepx = 1;
		gm->ray.sidedistx = (gm->ray.mapx + 1.0 - gm->ray.posx)
			* gm->ray.deltadistx;
	}
	if (gm->ray.raydiry < 0)
	{
		gm->ray.stepy = -1;
		gm->ray.sidedisty = (gm->ray.posy - gm->ray.mapy) * gm->ray.deltadisty;
	}
	else
	{
		gm->ray.stepy = 1;
		gm->ray.sidedisty = (gm->ray.mapy + 1.0 - gm->ray.posy)
			* gm->ray.deltadisty;
	}
	ft_incrementray(gm);
}

void	ft_incrementray(t_gm *gm)
{
	while (gm->ray.hit == 0)
	{
		if (gm->ray.sidedistx < gm->ray.sidedisty)
		{
			gm->ray.sidedistx += gm->ray.deltadistx;
			gm->ray.mapx += gm->ray.stepx;
			gm->ray.side = 0;
		}
		else
		{
			gm->ray.sidedisty += gm->ray.deltadisty;
			gm->ray.mapy += gm->ray.stepy;
			gm->ray.side = 1;
		}
		if (gm->map[gm->ray.mapx][gm->ray.mapy] == '1')
			gm->ray.hit = 1;
	}
	ft_drawstartend(gm);
}

void	ft_drawstartend(t_gm *gm)
{
	if (gm->ray.side == 0)
		gm->ray.perpwalldist = ((double)gm->ray.mapx - \
			gm->ray.posx + (1 - (double)gm->ray.stepx) / 2) \
			/ gm->ray.raydirx;
	else
		gm->ray.perpwalldist = ((double)gm->ray.mapy - \
			gm->ray.posy + (1 - (double)gm->ray.stepy) / 2) \
			/ gm->ray.raydiry;
	gm->ray.lineheight = (int)(gm->ry / gm->ray.perpwalldist);
	gm->ray.drawstart = -gm->ray.lineheight / 2 + gm->ry / 2;
	if (gm->ray.drawstart < 0)
		gm->ray.drawstart = 0;
	gm->ray.drawend = gm->ray.lineheight / 2 + gm->ry / 2;
	if (gm->ray.drawend >= gm->ry || gm->ray.drawend < 0)
		gm->ray.drawend = gm->ry - 1;
}

void	ft_swap(t_gm *gm)
{
	void	*tmp;

	tmp = gm->data.img;
	gm->data.img = gm->data.img2;
	gm->data.img2 = tmp;
	tmp = gm->data.addr;
	gm->data.addr = gm->data.addr2;
	gm->data.addr2 = tmp;
}
