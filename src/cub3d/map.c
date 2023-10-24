#include "cub3d.h"

void	ft_parse_map(t_map *map)
{
	int	j;
	int	k;
	int	i;

	i = 6;
	j = 0;
	while (map->file[i])
	{
		k = 0;
		while (map->file[i][k])
		{	
			if (map->file[i][k] == ' ' || map->file[i][k] == '\n')
				map->map_fill[j][k] = 'X';
			else if (map->file[i][k] == '0' || map->file[i][k] == '1')
				map->map_fill[j][k] = map->file[i][k];
			else if (map->file[i][k] == 'N' || map->file[i][k] == 'S' ||\
			map->file[i][k] == 'W' || map->file[i][k] == 'E')
			{
				map->dir = map->file[i][k];
				map->pos_h = j;
				map->pos_w = k;
				map->map_fill[j][k] = '0';
			}
			else
			{
				ft_free_map(map);
				ft_error("Carácteres erróneos en el mapa");
			}
			k++;
		}
		i++;
		j++;
	}
}

void	ft_get_length_map(t_map *map)
{
	int	i;
	int	width;

	i = 6;
	width = ft_strlen(map->file[i]);
	i++;
	while (map->file[i])
	{
		if ((int) ft_strlen(map->file[i]) > width)
			width = ft_strlen(map->file[i]);
		i++;
	}
	map->height = i - 6;
	map->width = width;
}

void	ft_create_map(t_map *map)
{
	int	i;
	int	j;

	map->map_fill = (char **) ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map_fill)
	{
		ft_free_map(map);
		ft_error("Malloc allocation problem");
	}
	i = 0;
	while (i < map->height)
	{
		map->map_fill[i] = malloc(map->width + 1 * sizeof(char));
		map->map_fill[i][map->width] = '\0';
		j = 0;
		while (j < map->width)
		{
			map->map_fill[i][j] = 'X';
			j++;
		}
		if (!map->map_fill[i])
		{
			ft_free_map(map);
			ft_error("Malloc allocation problem");
		}
		i++;
	}
}

void	ft_control_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_fill[i])
	{
		j = 0;
		while (map->map_fill[i][j])
		{
			if (map->map_fill[i][j] == '0')
			{
				if (i == 0 || j == 0 || \
				i == map->height - 1 || j == map->width - 1)
				{
					ft_free_map(map);
					ft_error("El mapa no esta rodeado de muros");
				}
				if (map->map_fill[i + 1][j] == 'X' || \
				map->map_fill[i - 1][j] == 'X' || \
				map->map_fill[i][j + 1] == 'X' || \
				map->map_fill[i][j - 1] == 'X')
				{
					ft_free_map(map);
					ft_error("El mapa no esta rodeado de muros");
				}
			}
			j++;
		}
		i++;
	}
}

void	ft_initialize_map(t_map *map)
{
	map->textures.east = NULL;
	map->textures.west = NULL;
	map->textures.north = NULL;
	map->textures.south = NULL;
}

t_map	ft_get_map(char *str)
{
	t_map	map;

	ft_initialize_map(&map);
	map.file = ft_get_file(str);
	ft_get_length_map(&map);
	ft_create_map(&map);
	ft_parse_map(&map);
	ft_control_map(&map);
	ft_get_textures(&map);
	ft_get_colours(&map);
	return (map);
}
