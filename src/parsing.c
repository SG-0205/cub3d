/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:46 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/05 22:27:31 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void error(char *arg, const char *source, int errcode, t_mlx *data) {
  if (!arg)
    printf("Error\n%s: %s\n", source, strerror(errcode));
  else
    printf("Error\n%s: %s: %s\n", source, arg, strerror(errcode));
  if (data && data->img)
    mlx_destroy_image(data->mlx, data->img);
  if (data && data->win)
    mlx_destroy_window(data->mlx, data->win);
  if (data)
    (mlx_destroy_display(data->mlx), gc_flush(data->gc));
  exit(errcode);
}

t_map *parse(char *cubfile_path, t_cub3D *data) {
  t_map *map;

  if (!cubfile_path)
    error(NULL, E_PARSE, ENOENT, data->mlx);
  (void)map;
  return (NULL);
}

