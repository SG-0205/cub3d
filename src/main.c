/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:37:33 by armeyer           #+#    #+#             */
/*   Updated: 2024/12/17 14:35:07 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv, char **envp)
{
	t_gm	gm;

	if (!*envp)
	{
		printf("Error\nPas d'environnement (mlx KO).\n");
		exit(1);
	}
	ft_init_game(&gm);
	if (argc == 2)
		ft_cub(argv[1], &gm);
	else
		write(1, "Error\nArguments invalides\n", 30);
}
