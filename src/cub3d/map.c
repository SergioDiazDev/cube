/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:09:59 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/11 13:38:03 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	map->h = i - 6;
	map->w = width;
}

void	ft_create_map(t_map *map)
{
	int	i;
	int	j;

	map->map_f = (char **) ft_calloc(map->h + 1, sizeof(char *));
	if (!map->map_f)
	{
		ft_free_map(map);
		ft_error("Malloc allocation problem");
	}
	i = -1;
	while (++i < map->h)
	{
		map->map_f[i] = malloc(map->w + 1 * sizeof(char));
		map->map_f[i][map->w] = '\0';
		j = -1;
		while (++j < map->w)
			map->map_f[i][j] = 'X';
		if (!map->map_f[i])
		{
			ft_free_map(map);
			ft_error("Malloc allocation problem");
		}
	}
}

void	ft_control_map(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (m->map_f[++i])
	{
		j = -1;
		while (m->map_f[i][++j])
		{
			if (m->map_f[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == m->h - 1 || j == m->w - 1)
				{
					ft_free_map(m);
					ft_error("Map is not sorround by walls");
				}
				if (m->map_f[i + 1][j] == 'X' || m->map_f[i - 1][j] == 'X'
					|| m->map_f[i][j + 1] == 'X' || m->map_f[i][j - 1] == 'X')
				{
					ft_free_map(m);
					ft_error("Map is not sorround by walls");
				}
			}
		}
	}
}

void	ft_initialize_map(t_map *map)
{
	map->tex.e = NULL;
	map->tex.w = NULL;
	map->tex.n = NULL;
	map->tex.s = NULL;
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
