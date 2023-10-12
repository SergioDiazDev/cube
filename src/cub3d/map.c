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
			if (map->file[i][k] == ' ' ||  map->file[i][k] == '\n')
				map->map_fill[j][k] = 'X';
			else if(map->file[i][k] == '0' || map->file[i][k] == '1')
				map->map_fill[j][k] = map->file[i][k];
			else if(map->file[i][k] == 'N' || map->file[i][k] == 'S' || map->file[i][k] == 'W' || map->file[i][k] == 'E')
				map->map_fill[j][k] = '0';
			else
			{
				printf("ERROR = %c\n", map->file[i][k]);
				printf("ERROR = %d\n", map->file[i][k]);
				perror("ERROR CON EL MAPA TENGO QUE LIBERAR COSITAS HACER MAS ADELANTE");
				exit (1);
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
		perror("ERROR AL CREAR MALLOC DE RELLENO DE MAPA");
		exit(1);
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
			perror("ERROR AL CREAR MALLOC DE RELLENO DE MAPA");
			exit(1);
		}
		i++;
	}
}

t_map	ft_get_map(char *str)
{
	t_map	map;
	int		i;

	map.file = ft_get_file(str);
	ft_get_textures(map);
	ft_get_colours(map);
	ft_get_length_map(&map);
	ft_create_map(&map);
	ft_parse_map(&map);
	i = 0;
	while (map.map_fill[i])
	{
		printf("%s\n", map.map_fill[i]);
		i++;
	}
	return (map);
}
