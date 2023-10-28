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
	map->textures.north = ft_get_texture_by_id("NO", map->file[0]);
	if (!map->textures.north)
	{
		ft_free_map(map);
		ft_error("Fallo al abrir textura");
	}
	map->textures.south = ft_get_texture_by_id("SO", map->file[1]);
	if (!map->textures.south)
	{
		ft_free_map(map);
		ft_error("Fallo al abrir textura");
	}
	map->textures.west = ft_get_texture_by_id("WE", map->file[2]);
	if (!map->textures.west)
	{
		ft_free_map(map);
		ft_error("Fallo al abrir textura");
	}
	map->textures.east = ft_get_texture_by_id("EA", map->file[3]);
	if (!map->textures.east)
	{
		ft_free_map(map);
		ft_error("Fallo al abrir textura");
	}
}
