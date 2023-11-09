/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:40 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/09 19:10:42 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

int	main(int ac, char **av)
{
	t_player	p;

	ac = 0;
	p.mapa = ft_get_map(av[1]);
	ft_init_cub3d(&p);
	mlx_image_to_window(p.mlx, p.walls, 0, 0);
	mlx_loop_hook(p.mlx, ft_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}
