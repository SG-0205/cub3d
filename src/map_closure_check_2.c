/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closure_check_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:23:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/01/24 13:24:14 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[++i])
		new_str[i] = str[i];
	return (new_str);
}

void	check_last_data(t_gm *gm, char *file)
{
	int		fd;
	int		ret;
	char	*str;
	char	*str_save;

	if (!gm || !file)
		return ;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	ret = get_next_line(fd, &str, gm);
	while (ret > 0)
	{
		str_save = ft_strdup(str);
		ret = get_next_line(fd, &str, gm);
	}
	if (!ft_is_map(str_save, gm))
		ft_error(gm, "Map isn't the last element of the file.");
}
