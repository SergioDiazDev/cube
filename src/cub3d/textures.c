#include "cub3d.h"

char	*ft_separate_by_id(char *id, char *str)
{
	int				i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if (str[i++] != id[0])
		exit (1);
	if (str[i++] != id[1])
		exit (1);
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
		ft_error("Fallo al abrir textura");
	}
	map->tex.s = ft_get_texture_by_id("SO", map->file[1]);
	if (!map->tex.s)
	{
		ft_free_map(map);
		ft_error("Fallo al abrir textura");
	}
	map->tex.w = ft_get_texture_by_id("WE", map->file[2]);
	if (!map->tex.w)
	{
		ft_free_map(map);
		ft_error("Fallo al abrir textura");
	}
	map->tex.e = ft_get_texture_by_id("EA", map->file[3]);
	if (!map->tex.e)
	{
		ft_free_map(map);
		ft_error("Fallo al abrir textura");
	}
}

void	ft_get_tex_x(t_player *p)
{
	double	wallx;

	if (p->side == 0 || p->side == 2)
		wallx = p->p_y + p->perp_wall_dist * p->ray_d_y;
	else
		wallx = p->p_x + p->perp_wall_dist * p->ray_d_x;
	wallx = wallx - (int)wallx;
	p->tex_x = (int)(wallx * (double)p->mapa.tex.n->width);
	if ((p->side == 2 || p->side == 1))
		p->tex_x = p->mapa.tex.n->width - p->tex_x - 1;
}

mlx_texture_t	*ft_get_texture(t_player *p)
{
	if (p->side == 0)
		return (p->mapa.tex.n);
	else if (p->side == 1)
		return (p->mapa.tex.e);
	else if (p->side == 2)
		return (p->mapa.tex.s);
	else
		return (p->mapa.tex.w);
}
