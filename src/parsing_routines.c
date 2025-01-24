/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:10:52 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 14:34:18 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parsing_routine(int *ret, char *str, int *fd, t_gm *gm)
{
	*ret = get_next_line(*fd, &str, gm);
	gm->gnl_internal_link = &str;
	if (gm->erreur == 2)
		ft_error(gm, "Parsing error\n");
	ft_color_res(&str, gm);
	ft_texture(str, gm);
	ft_map(str, gm);
	free(str);
	str = NULL;
}

void	parsing_routine_map(t_gm *gm, int *ret, int *fd, char *str)
{
	*ret = get_next_line(*fd, &str, gm);
	gm->gnl_internal_link = &str;
	if (gm->insidemap == 1 && ft_empty_line(str) == 0 \
		&& gm->count < gm->nblines)
		gm->empty_line = 1;
	gm->insidemap = ft_is_map(str, gm);
	if (gm->insidemap == 1)
	{
		gm->count++;
		ft_copy_map(str, gm);
	}
	free(str);
	gm->gnl_internal_link = NULL;
}
