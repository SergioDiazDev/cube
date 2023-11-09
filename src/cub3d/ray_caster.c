/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:59 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/09 19:11:00 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_perform_dda(t_player *p)
{
	while (p->hit == 0)
	{
		if (p->side_d_x < p->side_d_y)
		{
			p->side_d_x += p->delta_d_x;
			p->map_x += p->step_x;
			if ((p->map_x - p->p_x) >= 0)
				p->side = 2;
			else
				p->side = 0;
		}
		else
		{
			p->side_d_y += p->delta_d_y;
			p->map_y += p->step_y;
			if ((p->map_y - p->p_y) >= 0)
				p->side = 1;
			else
				p->side = 3;
		}
		if (p->map[p->map_x][p->map_y] == '1')
			p->hit = 1;
	}
	ft_distance_wall(p);
}

void	ft_distance_wall(t_player *p)
{
	if (p->side == 0 || p->side == 2)
		p->perp_wall_dist = p->side_d_x - p->delta_d_x;
	else
		p->perp_wall_dist = p->side_d_y - p->delta_d_y;
	p->line_height = (int)(SCREEN_H / p->perp_wall_dist);
	p->draw_start = -p->line_height / 2 + SCREEN_H / 2;
	if (p->draw_start < 0)
		p->draw_start = 0;
	p->draw_end = p->line_height / 2 + SCREEN_H / 2;
	if (p->draw_end >= SCREEN_H)
		p->draw_end = SCREEN_H - 1;
}

void	ft_deltas(t_player *p)
{
	if (!p->ray_d_x)
		p->delta_d_x = 1e30;
	else
		p->delta_d_x = fabs(1 / p->ray_d_x);
	if (!p->ray_d_y)
		p->delta_d_y = 1e30;
	else
		p->delta_d_y = fabs(1 / p->ray_d_y);
}

void	ft_steps(t_player *p)
{
	if (p->ray_d_x < 0)
	{
		p->step_x = -1;
		p->side_d_x = (p->p_x - p->map_x) * p->delta_d_x;
	}
	else
	{
		p->step_x = 1;
		p->side_d_x = (p->map_x + 1.0 - p->p_x) * p->delta_d_x;
	}
	if (p->ray_d_y < 0)
	{
		p->step_y = -1;
		p->side_d_y = (p->p_y - p->map_y) * p->delta_d_y;
	}
	else
	{
		p->step_y = 1;
		p->side_d_y = (p->map_y + 1.0 - p->p_y) * p->delta_d_y;
	}
}
