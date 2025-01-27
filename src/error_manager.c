/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:23:13 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 14:35:57 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_normal_exit(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = "cub3d closed\n";
	while (str[i] != '\0' && str2[i] != '\0')
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_verify_errors(t_gm *gm)
{
	if (ft_wall(gm) == 1)
		ft_error(gm, "The map is not closed with wall.\n");
	if (gm->starting_pos == 'x')
		ft_error(gm, "No player on map\n");
	if (gm->ierror2 != 6)
		ft_error(gm, "Error with F or C (floor and ceiling)\n");
	if (gm->multiple_player == 1)
		ft_error(gm, "More than 1 player on map\n");
	if (gm->empty_line == 1)
		ft_error(gm, "Empty line in map\n");
	if (gm->wrongcharmap == 2)
		ft_error(gm, "Unrecognized char in map\n");
}

void	ft_error_2(t_gm *gm)
{
  if (gm->strjoin_link)
    free(*gm->strjoin_link);
	if (gm->gnl_buff_link)
		free(*gm->gnl_buff_link);
	if (gm->gnl_internal_link)
		if (*gm->gnl_internal_link)
			free(*gm->gnl_internal_link);
	if (gm->map)
		free(gm->map);
}

void	ft_error(t_gm *gm, char *str)
{
	int	i;

	i = -1;
	if (ft_normal_exit(str) == 0)
		write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	gm->ierror3 = 1;
	if (gm->north)
		free(gm->north);
	if (gm->south)
		free(gm->south);
	if (gm->west)
		free(gm->west);
	if (gm->east)
		free(gm->east);
	if (gm->map)
	{
		while (++i <= gm->nb_v_lines && gm->map[i])
			free(gm->map[i]);
	}
	ft_error_2(gm);
	ft_exit(gm);
}

int	ft_exit(t_gm *gm)
{
	if (gm->ierror3 == 0)
		ft_error(gm, "cub3d closed\n");
	if (gm->data.img)
		mlx_destroy_image(gm->data.mlx_ptr, gm->data.img);
	if (gm->data.img2)
		mlx_destroy_image(gm->data.mlx_ptr, gm->data.img2);
	if (gm->texture[0].img)
		mlx_destroy_image(gm->data.mlx_ptr, gm->texture[0].img);
	if (gm->texture[1].img)
		mlx_destroy_image(gm->data.mlx_ptr, gm->texture[1].img);
	if (gm->texture[2].img)
		mlx_destroy_image(gm->data.mlx_ptr, gm->texture[2].img);
	if (gm->texture[3].img)
		mlx_destroy_image(gm->data.mlx_ptr, gm->texture[3].img);
	if (gm->texture[4].img)
		mlx_destroy_image(gm->data.mlx_ptr, gm->texture[4].img);
	if (gm->data.mlx_win)
		mlx_destroy_window(gm->data.mlx_ptr, gm->data.mlx_win);
	if (gm->data.mlx_ptr)
	{
		mlx_destroy_display(gm->data.mlx_ptr);
		free(gm->data.mlx_ptr);
	}
	exit(0);
}
