/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:36:21 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/05 22:33:59 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "keycodes.h"
# include "libft/garbage_collector/garbagecollector.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysymdef.h>
# include <dirent.h>
# include <stdio.h>

# define WIN_T "cub3D"

# define WIN_W 800
# define WIN_H 800

# define E_PARSE "parsing"
# define E_INIT "initialisation"
# define E_INITM "mlx initialisation"
# define E_INITD "map initialisation"

# define B_MAPS_DIR "../maps/bad/"
# define G_MAPS_DIR "../maps/good/"

# define MAP_CHARS "NSEW01"
# define FD_INIT -2
# define CO_INIT -1
# define RGB_MIN 0
# define RGB_MAX 255

# define TXT_NO "NO"
# define TXT_SO "SO"
# define TXT_WE "WE"
# define TXT_EA "EA"

typedef enum e_texture
{
	NO,
	SO,
	WE,
	EA
}				t_texture_id;

typedef struct s_map
{
	char		*path;
	int			fd;
	int			**translated;
	int			rgb_f[3];
	int			rgb_c[3];
	char		**textures_paths;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	t_collector	*gc;
}				t_mlx;

typedef struct s_cub3D
{
	t_mlx		*mlx;
	t_map		*map;
	t_collector	*gc;
}				t_cub3D;

void			error(char *arg, const char *source, int errcode, t_mlx *data);
t_map			*parse(char *cubfile_path, t_cub3D *data);
t_cub3D			*init_data(void);
int				clean_exit(t_cub3D *data);
int				clean_exit_w(void *data);
int				key_hooks(int key, t_cub3D *data);

#endif
