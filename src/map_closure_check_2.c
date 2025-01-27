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

void	check_last_data(t_gm *gm, char *file)
{
	int		fd;
	int		ret;
	char	*str;

	if (!gm || !file)
		return ;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	ret = 1;
	while (ret > 0) {
		ret = get_next_line(fd, &str, gm);
  }
	if (*str && !ft_is_map(str, gm))
  {
    if (str)
      free(str);
		ft_error(gm, "Map isn't the last element of the file.");
  }
  if (str)
    free(str);
}
