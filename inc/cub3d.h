/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:36:21 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/03 21:18:24 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <dirent.h>

# define B_MAPS_DIR "../maps/bad/"
# define G_MAPS_DIR "../maps/good/"

# define MAP_CHARS "NSEW01"

typedef enum e_texture
{
			NO,
			SO,
			WE,
			EA
};			t_texture_id;

typedef struct s_map
{
	char	*path;
	int		fd;
	int		*translated;
	int		rgb_f[3];
	int		rgb_c[3];
	char	**textures_paths;
};			t_map;

#endif