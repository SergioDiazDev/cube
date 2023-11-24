/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_spaces_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:04:09 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/24 17:05:22 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_str_wrong_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && \
		str[i] != '\n' && str[i] != '\t' && str[i] != 'N' && str[i] != 'S'\
		&& str[i] != 'W' && str[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_map_spaces(t_map *map, int i)
{
	while (map->file[i] != NULL)
	{
		if (!ft_str_empty(map->file[i]))
			ft_error("Cannot be new line between content map");
		if (ft_str_wrong_map(map->file[i]))
		{
			ft_error_line("Line cannot be there", map->file[i]);
		}
		i++;
	}
}
