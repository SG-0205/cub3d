/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:31 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 14:35:22 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>
#include <string.h>

static void	ft_bzero_array(void **ptr, size_t n)
{
	int		i;
	char	**ptr_cast;

	i = -1;
	ptr_cast = (char **)ptr;
	while ((size_t)++i < n)
		ptr_cast[i] = NULL;
}

int	ft_parsing_map(char *file, t_gm *gm)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(file, O_RDONLY);
	gm->map = malloc(sizeof(char *) * (gm->nblines + 1));
	if (!(gm->map))
		return (0);
	ft_bzero_array((void **)gm->map, gm->nblines + 1);
	gm->map[gm->nblines] = NULL;
	while (ret != 0)
		parsing_routine_map(gm, &ret, &fd, str);
	close(fd);
	map_closure_check(gm, file);
	ft_mlx(gm);
	return (0);
}

void	ft_parsing_2(char *file, t_gm *gm)
{
	if (gm->sizeline == 0 || gm->nblines == 0)
		ft_error(gm, "No map\n");
	if (gm->sizeline > 200 || gm->nblines > 200)
		ft_error(gm, "Map too big.\n");
	ft_parsing_map(file, gm);
}

void	ft_parsing(char *file, t_gm *gm)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		ft_error(gm, "Invalid : is a directory\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(gm, "File .cub is invalid\n");
	gm->erreur = 0;
	while (ret != 0)
		parsing_routine(&ret, str, &fd, gm);
	close(fd);
	gm->gnl_internal_link = NULL;
	ft_parsing_2(file, gm);
}

int	ft_cub(char *str, t_gm *gm)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(gm, "Invalid map name\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, gm);
	else
		ft_error(gm, "Invalid map extension\n");
	return (0);
}
