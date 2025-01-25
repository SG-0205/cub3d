/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_color_res.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:57 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 12:11:53 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_atoi2(const char *str, t_gm *gm)
{
	int	verify;

	verify = 0;
	if (str[1] != ' ')
		gm->erreur = 2;
	ft_atoi2_check(str, gm);
	while (str[gm->i] == ' ' || str[gm->i] == '\t' || str[gm->i] == ',' ||
			str[gm->i] == '\n' || str[gm->i] == '\r' || str[gm->i] == '\v' ||
			str[gm->i] == '\f')
	{
		gm->i++;
		verify = 0;
		if (str[gm->i] >= '0' && str[gm->i] <= '9')
			gm->ierror2++;
		while (str[gm->i] >= '0' && str[gm->i] <= '9')
		{
			verify = (verify * 10) + str[gm->i] - 48;
			gm->sum = (gm->sum * 10) + (str[gm->i] - 48);
			gm->i++;
		}
		if (verify > 255 || verify < 0)
			gm->erreur = 2;
	}
	return (gm->sum);
}

int	ft_path_texture(char *str, char **texture, t_gm *gm, int j)
{
	gm->count2 = 0;
	if (*texture)
	{
		ft_error(gm, "More than one texture provided for one side.");
	}
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0 ||
		ft_strlen2(str) <= 2)
		gm->erreur = 2;
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			gm->erreur = 2;
		j++;
	}
	*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)));
	if (!*texture)
		gm->erreur = 2;
	while (str[j] != '\0')
	{
		(*texture)[gm->count2] = str[j];
		gm->count2++;
		j++;
	}
	(*texture)[gm->count2] = '\0';
	return (0);
}

void	ft_texture(char *str, t_gm *gm)
{
	int	i;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_path_texture(str, &gm->north, gm, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_path_texture(str, &gm->south, gm, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_path_texture(str, &gm->west, gm, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_path_texture(str, &gm->east, gm, 2);
	else if (str[0] != 'N' && str[0] != 'S' &&
				str[0] != 'W' && str[0] != 'E' &&
				str[0] != 'F' && str[0] != 'C' && str[0] > 65 && str[0] < 122)
		gm->erreur = 2;
}

static void	check_rgb_format(char *str, t_gm *gm)
{
	int	i;
	int	coma_count;

	if (!str || !gm)
		return ;
	i = -1;
	coma_count = 0;
	while (str[++i])
		if (str[i] == ',')
			coma_count++;
	if (coma_count != 2)
		ft_error(gm, "Invalid RGB format.");
}

void	ft_color_res(char **str, t_gm *gm)
{
	int	i;

	i = 0;
	gm->i = 1;
	if (gm->sizeline > 0 && (gm->north == NULL || gm->south == NULL
			|| gm->west == NULL || gm->east == NULL))
		gm->erreur = 2;
	if ((gm->north != NULL || gm->south != NULL || gm->west != NULL ||
			gm->east != NULL) &&
		(gm->rx == 0 || gm->ry == 0))
		gm->erreur = 2;
	gm->rx = WIN_X;
	gm->ry = WIN_Y;
	if (*str[i] == 'F' || *str[i] == 'C')
	{
		check_rgb_format(&(*str[i]), gm);
		if (*str[i] == 'F' && gm->f < 0)
			gm->f = ft_atoi2(*str, gm);
		else if (*str[i] == 'F')
			ft_error(gm, "Double RGB data for Floor.");
		else if (*str[i] == 'C' && gm->c < 0)
			gm->c = ft_atoi2(*str, gm);
		else if (*str[i] == 'C')
			ft_error(gm, "Double RGB data for Ceiling.");
	}
}
