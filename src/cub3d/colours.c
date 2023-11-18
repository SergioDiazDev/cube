/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:16 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/18 11:35:27 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strim_final(char *s)
{
	char	*dst;
	int		i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\n')
		i++;
	dst = malloc(sizeof(char *) * i + 1);
	dst[i--] = '\0';
	while (i >= 0)
	{
		dst[i] = s[i];
		i--;
	}
	return (dst);
}

char	*ft_separate_by_id_colours(char *id, char *str)
{
	int				i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if (str[i++] != id[0])
		ft_error("File not in order");
	while (str[i] == ' ' && str[i])
		i++;
	return (&str[i]);
}

int	ft_count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

uint32_t	ft_get_colours_by_id(char *id, char *str, t_map *map)
{
	uint32_t		colour;
	char			**split;
	char			*s_colour;

	s_colour = ft_strim_final(ft_separate_by_id_colours(id, str));
	split = ft_split(s_colour, ',');
	free(s_colour);
	if (ft_count_split(split) != 3)
	{
		ft_free_matrix(split);
		ft_free_map(map);
		ft_error("Wrong RGB");
	}
	if (ft_strlen(split[0]) > 3 || ft_strlen(split[1]) > 3 || \
	ft_strlen(split[2]) > 3)
	{
		ft_free_matrix(split);
		ft_free_map(map);
		ft_error("Wrong RGB");
	}
	colour = 255;
	colour += ft_atoi(split[0]) << 24;
	colour += ft_atoi(split[1]) << 16;
	colour += ft_atoi(split[2]) << 8;
	return (ft_free_matrix(split), colour);
}

void	ft_get_colours(t_map *map)
{
	map->colours.floor = ft_get_colours_by_id("F", map->file[4], map);
	map->colours.ceiling = ft_get_colours_by_id("C", map->file[5], map);
}
