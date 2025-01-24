/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:27:07 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/20 12:17:23 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_texture_adress(t_gm *gm)
{
	gm->texture[0].addr = (int *)mlx_get_data_addr(gm->texture[0].img,
			&gm->texture[0].bits_per_pixel,
			&gm->texture[0].line_length,
			&gm->texture[0].endian);
	gm->texture[1].addr = (int *)mlx_get_data_addr(gm->texture[1].img,
			&gm->texture[1].bits_per_pixel,
			&gm->texture[1].line_length,
			&gm->texture[1].endian);
	gm->texture[2].addr = (int *)mlx_get_data_addr(gm->texture[2].img,
			&gm->texture[2].bits_per_pixel,
			&gm->texture[2].line_length,
			&gm->texture[2].endian);
	gm->texture[3].addr = (int *)mlx_get_data_addr(gm->texture[3].img,
			&gm->texture[3].bits_per_pixel,
			&gm->texture[3].line_length,
			&gm->texture[3].endian);
}

void	ft_get_texture(t_gm *gm)
{
	gm->texture[0].img = mlx_xpm_file_to_image(gm->data.mlx_ptr,
			gm->north,
			&(gm->texture[0].width),
			&(gm->texture[0].height));
	if (!gm->texture[0].img)
		ft_error(gm, "Texture SO\n");
	gm->texture[1].img = mlx_xpm_file_to_image(gm->data.mlx_ptr,
			gm->south,
			&(gm->texture[1].width),
			&(gm->texture[1].height));
	if (!gm->texture[1].img)
		ft_error(gm, "Texture NO\n");
	gm->texture[2].img = mlx_xpm_file_to_image(gm->data.mlx_ptr,
			gm->west,
			&(gm->texture[2].width),
			&(gm->texture[2].height));
	if (!gm->texture[2].img)
		ft_error(gm, "Texture EA\n");
	gm->texture[3].img = mlx_xpm_file_to_image(gm->data.mlx_ptr,
			gm->east,
			&(gm->texture[3].width),
			&(gm->texture[3].height));
	if (!gm->texture[3].img)
		ft_error(gm, "Texture WE\n");
	ft_get_texture_adress(gm);
}

int	ft_raycasting(t_gm *gm)
{
	gm->ray.x = 0;
	while (gm->ray.x < gm->rx)
	{
		ft_initialisation3(gm);
		ft_stepsidedist(gm);
		ft_color_column(gm);
		gm->ray.x++;
	}
	mlx_put_image_to_window(gm->data.mlx_ptr, gm->data.mlx_win, gm->data.img, 0,
		0);
	ft_forward_back(gm);
	ft_left_right(gm);
	ft_rotate_right_left(gm);
	ft_swap(gm);
	return (0);
}

void	launch_mlx_hook(t_gm *gm)
{
	mlx_hook(gm->data.mlx_win, 33, 1L << 17, ft_exit, gm);
	mlx_hook(gm->data.mlx_win, 2, 1L << 0, ft_key_press, gm);
	mlx_loop_hook(gm->data.mlx_ptr, ft_raycasting, gm);
	mlx_hook(gm->data.mlx_win, 3, 1L << 1, ft_key_release, gm);
	mlx_loop(gm->data.mlx_ptr);
}

int	ft_mlx(t_gm *gm)
{
	ft_initialisation2(gm);
	gm->data.mlx_ptr = mlx_init();
	if (!gm->data.mlx_ptr)
		ft_error(gm, "Mlx init impossible\n");
	mlx_get_screen_size(gm->data.mlx_ptr, &gm->screenx, &gm->screeny);
	if (gm->rx > gm->screenx)
		gm->rx = gm->screenx;
	if (gm->ry > gm->screeny)
		gm->ry = gm->screeny;
	ft_get_texture(gm);
	gm->data.img = mlx_new_image(gm->data.mlx_ptr, gm->rx, gm->ry);
	gm->data.addr = (int *)mlx_get_data_addr(gm->data.img,
			&gm->data.bits_per_pixel,
			&gm->data.line_length,
			&gm->data.endian);
	gm->data.mlx_win = mlx_new_window(gm->data.mlx_ptr, gm->rx, gm->ry,
			"Cub3d");
	gm->data.img2 = mlx_new_image(gm->data.mlx_ptr, gm->rx, gm->ry);
	gm->data.addr2 = (int *)mlx_get_data_addr(gm->data.img2,
			&gm->data.bits_per_pixel,
			&gm->data.line_length,
			&gm->data.endian);
	launch_mlx_hook(gm);
	return (0);
}
