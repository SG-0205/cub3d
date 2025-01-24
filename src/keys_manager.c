/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:05 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/21 15:40:49 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_key_press(int keycode, t_gm *gm)
{
	if (keycode == FORWARD_W_Z)
		gm->data.forward = 1;
	else if (keycode == BACK_S_S)
		gm->data.back = 1;
	else if (keycode == LEFT_A_Q)
		gm->data.left = 1;
	else if (keycode == RIGHT_D_D)
		gm->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		gm->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		gm->data.rotate_right = 1;
	else if (keycode == 65307)
		ft_error(gm, "cub3d closed\n");
	return (1);
}

int	ft_key_release(int keycode, t_gm *gm)
{
	if (keycode == FORWARD_W_Z)
		gm->data.forward = 0;
	else if (keycode == BACK_S_S)
		gm->data.back = 0;
	else if (keycode == LEFT_A_Q)
		gm->data.left = 0;
	else if (keycode == RIGHT_D_D)
		gm->data.right = 0;
	else if (keycode == ROTATE_LEFT)
		gm->data.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		gm->data.rotate_right = 0;
	return (1);
}

int	ft_color_column(t_gm *gm)
{
	int	j;
	int	i;

	j = -1;
	gm->ray.drawend = gm->ry - gm->ray.drawstart;
	i = gm->ray.drawend;
	while (++j < gm->ray.drawstart)
		gm->data.addr[j * gm->data.line_length / 4 + \
						gm->ray.x] = gm->c;
	if (j <= gm->ray.drawend)
		ft_draw_texture(gm, gm->ray.x, j);
	j = i;
	while (++j < gm->ry)
		gm->data.addr[j * gm->data.line_length / 4 + \
						gm->ray.x] = gm->f;
	return (0);
}

void	ft_draw_texture(t_gm *gm, int x, int y)
{
	y = gm->ray.drawstart - 1;
	ft_init_texture(gm);
	gm->t.step = 1.0 * gm->texture[0].height / gm->ray.lineheight;
	gm->t.texx = (int)(gm->t.wallx * (double)gm->texture[gm->t.texdir].width);
	if (gm->ray.side == 0 && gm->ray.raydirx > 0)
		gm->t.texx = gm->texture[gm->t.texdir].width - gm->t.texx - 1;
	else if (gm->ray.side == 1 && gm->ray.raydiry < 0)
	{
		gm->t.texx = gm->texture[gm->t.texdir].width - gm->t.texx - 1;
	}
	gm->t.texpos = (gm->ray.drawstart - gm->ry / 2 + gm->ray.lineheight / 2) \
	* gm->t.step;
	while (++y <= gm->ray.drawend)
	{
		gm->t.texy = (int)gm->t.texpos & (gm->texture[gm->t.texdir].height - 1);
		gm->t.texpos += gm->t.step;
		if ((x >= 0 && y >= 0) && y < gm->ry && x < gm->rx)
			gm->data.addr[y * gm->data.line_length / 4 + x] = \
				gm->texture[gm->t.texdir].addr[gm->t.texy * \
					gm->texture[gm->t.texdir].line_length \
					/ 4 + gm->t.texx];
	}
}
