/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:09:51 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/11 13:40:30 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_open_fd(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

void	ft_fill_map(t_map *map, int i, int j, int k)
{
	if (map->file[i][k] == ' ' || map->file[i][k] == '\n')
		map->map_f[j][k] = 'X';
	else if (map->file[i][k] == '0' || map->file[i][k] == '1')
		map->map_f[j][k] = map->file[i][k];
	else if (map->file[i][k] == 'N' || map->file[i][k] == 'S' || \
	map->file[i][k] == 'W' || map->file[i][k] == 'E')
	{
		if (map->flag_pos)
		{
			ft_free_map(map);
			ft_error("Can't be more than one position");
		}
		map->dir = map->file[i][k];
		map->pos_h = j;
		map->pos_w = k;
		map->flag_pos = 1;
		map->map_f[j][k] = '0';
	}
	else
	{
		ft_free_map(map);
		ft_error("Wrong character at map");
	}
}

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
			ft_fill_map(map, i, j, k);
			k++;
		}
		i++;
		j++;
	}
	if (!map->flag_pos)
	{
		ft_error("There is not any initial position in the map");
		ft_free_map(map);
	}
}
