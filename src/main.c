/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:36:05 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/05 22:24:00 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3D	*data;

	if (argc != 2)
		return (argc);
	data = init_data();
	if (!data)
		return (argc);
	clean_exit(data);
	(void)argv;
	return (0);
}
