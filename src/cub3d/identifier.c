/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:31 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/24 17:11:55 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_str_empty(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i++;
	if (str[i])
		res = 1;
	return (res);
}

void	ft_get_id_texture(t_map *map, char *id, char *str)
{
	if (!ft_strncmp(id, "NO", 2))
	{
		if (map->tex.n)
			ft_error("Duplicated id");
		map->tex.n = ft_get_texture_by_id("NO", str);
	}
	if (!ft_strncmp(id, "SO", 2))
	{
		if (map->tex.s)
			ft_error("Duplicated id");
		map->tex.s = ft_get_texture_by_id("SO", str);
	}
	if (!ft_strncmp(id, "WE", 2))
	{
		if (map->tex.w)
			ft_error("Duplicated id");
		map->tex.w = ft_get_texture_by_id("WE", str);
	}
	if (!ft_strncmp(id, "EA", 2))
	{
		if (map->tex.e)
			ft_error("Duplicated id");
		map->tex.e = ft_get_texture_by_id("EA", str);
	}
}

void	ft_get_identifier(t_map *map, char *id, char *str)
{
	if (ft_strlen(id) != 2 && ft_strlen(id) != 1)
		ft_error("File is not well structured");
	if (ft_strlen(id) == 2 && ft_strncmp(id, "NO", 2) && \
	ft_strncmp(id, "SO", 2) && ft_strncmp(id, "WE", 2) && \
	ft_strncmp(id, "EA", 2))
		ft_error("File is not well structured");
	if (ft_strlen(id) == 1 && id[0] != 'F' && id[0] != 'C')
		ft_error("File is not well structured");
	ft_get_id_texture(map, id, str);
	if (id[0] == 'F')
	{
		if (map->colours.floor)
			ft_error("Duplicated id");
		map->colours.floor = ft_get_colours_by_id("F", str);
	}
	if (id[0] == 'C')
	{
		if (map->colours.ceiling)
			ft_error("Duplicated id");
		map->colours.ceiling = ft_get_colours_by_id("C", str);
	}
}

void	ft_get_all(t_map *map, char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (ft_count_split(split) > 2 && split[2][0] != '\n')
	{
		ft_free_matrix(split);
		ft_error_line("Line is not correct", str);
	}
	ft_get_identifier(map, split[0], str);
	ft_free_matrix(split);
}

void	ft_get_identifiers(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->file[i] != NULL && j < 6)
	{
		if (ft_str_empty(map->file[i]))
		{
			ft_get_all(map, map->file[i]);
			j++;
		}
		i++;
	}
	while (map->file[i] != NULL && !ft_str_empty(map->file[i]))
		i++;
	map->start = i;
	ft_check_map_spaces(map, i);
}
