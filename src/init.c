/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:17:19 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/05 22:26:27 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	clean_exit_w(void *data)
{
	t_cub3D	*cast;

	cast = (t_cub3D *)data;
	return (clean_exit(cast));
}

int	clean_exit(t_cub3D *data)
{
	if (!data)
		exit(1);
	if (data->mlx && data->mlx->img)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	if (data->mlx && data->mlx->win)
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	gc_flush(data->gc);
	exit(0);
}

static t_map	*init_map(t_cub3D *data)
{
	t_map	*new;
	int		i;

	if (!data)
		return (NULL);
	new = (t_map *)gc_malloc(data->gc, sizeof(t_map), 0);
	if (!new)
		error(NULL, E_INITD, errno, data->mlx);
	new->fd = FD_INIT;
	new->textures_paths = NULL;
	new->path = NULL;
	new->translated = NULL;
	i = -1;
	while (++i < 3)
	{
		new->rgb_c[i] = CO_INIT;
		new->rgb_f[i] = CO_INIT;
	}
	return (new);
}

static t_mlx	*init_mlx(t_cub3D *data)
{
	t_mlx	*new;

	if (!data)
		return (NULL);
	new = (t_mlx *)gc_malloc(data->gc, (sizeof(t_mlx)), 0);
	if (!new)
		error(NULL, E_INIT, errno, NULL);
	new->gc = data->gc;
	new->mlx = mlx_init();
	if (!new->mlx)
		error(NULL, E_INITM, errno, new);
	new->img = NULL;
	new->img_data = NULL;
	new->win = mlx_new_window(new->mlx, WIN_W, WIN_H, WIN_T);
	mlx_hook(new->win, EVENT_CLOSE_BTN, 0, clean_exit_w, data);
	mlx_key_hook(new->win, key_hooks, data);
	return (new);
}

t_cub3D	*init_data(void)
{
	t_cub3D		*new;
	t_collector	*gc;

	gc = gc_init(2);
	if (!gc)
		error(NULL, E_INIT, errno, NULL);
	new = (t_cub3D *)gc_malloc(gc, (sizeof(t_cub3D)), 0);
	if (!new)
		error(NULL, E_INIT, errno, NULL);
	new->gc = gc;
	new->mlx = init_mlx(new);
	new->map = init_map(new);
	if (!new->mlx || !new->map)
		error(NULL, E_INIT, ENOMEM, new->mlx);
	return (new);
}
