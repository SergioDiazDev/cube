/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:52 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/11 13:55:56 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_separate_by_id(char *id, char *str)
{
	int				i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if (str[i++] != id[0])
		ft_error("File not in order");
	if (str[i++] != id[1])
		ft_error("File not in order");
	while (str[i] == ' ' && str[i])
		i++;
	return (&str[i]);
}

mlx_texture_t	*ft_get_texture_by_id(char *id, char *str)
{
	mlx_texture_t	*texture;
	char			*s_texture;

	s_texture = ft_strim_final(ft_separate_by_id(id, str));
	texture = mlx_load_png(s_texture);
	free(s_texture);
	return (texture);
}

void	ft_get_textures(t_map *map)
{
	map->tex.n = ft_get_texture_by_id("NO", map->file[0]);
	if (!map->tex.n)
	{
		ft_free_map(map);
		ft_error("Cannot open texture");
	}
	map->tex.s = ft_get_texture_by_id("SO", map->file[1]);
	if (!map->tex.s)
	{
		ft_free_map(map);
		ft_error("Cannot open texture");
	}
	map->tex.w = ft_get_texture_by_id("WE", map->file[2]);
	if (!map->tex.w)
	{
		ft_free_map(map);
		ft_error("Cannot open texture");
	}
	map->tex.e = ft_get_texture_by_id("EA", map->file[3]);
	if (!map->tex.e)
	{
		ft_free_map(map);
		ft_error("Cannot open texture");
	}
}

void	ft_get_tex_x(t_player *p, mlx_texture_t *tex)
{
	double	wallx;

	if (p->side == 0 || p->side == 2)
		wallx = p->p_y + p->perp_wall_dist * p->ray_d_y;
	else
		wallx = p->p_x + p->perp_wall_dist * p->ray_d_x;
	wallx = wallx - (int)wallx;
	p->tex_x = (int)(wallx * (double)tex->width);
	if ((p->side == 2 || p->side == 1))
		p->tex_x = tex->width - p->tex_x - 1;
}

mlx_texture_t	*ft_get_texture(t_player *p)
{
	if (p->side == 0)
		return (p->mapa.tex.n);
	if (p->side == 2)
		return (p->mapa.tex.s);
	if (p->side == 3)
		return (p->mapa.tex.w);
	if (p->side == 1)
		return (p->mapa.tex.e);
	return (p->mapa.tex.e);
}
