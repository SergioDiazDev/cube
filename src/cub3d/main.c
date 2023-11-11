/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:40 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/11 13:46:56 by pbengoec         ###   ########.fr       */
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

	if (ac == 2)
	{
		p.mapa = ft_get_map(av[1]);
		ft_init_cub3d(&p);
		mlx_image_to_window(p.mlx, p.walls, 0, 0);
		mlx_loop_hook(p.mlx, ft_hook, &p);
		mlx_loop(p.mlx);
	}
	ft_error("Bad arguments");
	return (0);
}
