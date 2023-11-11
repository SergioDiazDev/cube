/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:35 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/11 13:56:26 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_direction(t_player *p)
{
	p->d_x = 0;
	p->d_y = 0;
	p->plan_x = 0;
	p->plan_y = 0;
	if (p->mapa.dir == 'W')
	{
		p->d_y = -1.1;
		p->plan_x = -0.66;
	}
	else if (p->mapa.dir == 'E')
	{
		p->d_y = 1.1;
		p->plan_x = 0.66;
	}
	else if (p->mapa.dir == 'N')
	{
		p->d_x = -1.1;
		p->plan_y = 0.66;
	}
	else if (p->mapa.dir == 'S')
	{
		p->d_x = 1.1;
		p->plan_y = -0.66;
	}
}

void	ft_init_cub3d(t_player *p)
{
	p->map = p->mapa.map_f;
	p->p_x = p->mapa.pos_h + 0.5;
	p->p_y = p->mapa.pos_w + 0.5;
	ft_direction(p);
	p->mlx = mlx_init(SCREEN_W, SCREEN_H, "CUB3D", false);
	p->bg = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H);
	ft_paint_bg(p);
	mlx_image_to_window(p->mlx, p->bg, 0, 0);
	p->walls = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H);
	ft_paint(p);
}
