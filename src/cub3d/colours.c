/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:16 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/24 16:31:26 by pbengoec         ###   ########.fr       */
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

int	ft_str_is_digit(char *str)
{
	int	i;
	int	digit;

	digit = 1;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (digit);
}

uint32_t	ft_get_colours_by_id(char *id, char *str)
{
	uint32_t		colour;
	char			**split;
	char			*s_colour;

	s_colour = ft_strim_final(ft_separate_by_id_colours(id, str));
	split = ft_split(s_colour, ',');
	free(s_colour);
	if (ft_count_split(split) != 3)
		ft_free_colours(split);
	if (ft_strlen(split[0]) > 3 || ft_strlen(split[1]) > 3 || \
	ft_strlen(split[2]) > 3)
		ft_free_colours(split);
	if (!ft_str_is_digit(split[0]) || \
	!ft_str_is_digit(split[1]) || !ft_str_is_digit(split[2]))
		ft_free_colours(split);
	if (ft_atoi(split[0]) > 255 || \
	ft_atoi(split[1]) > 255 || ft_atoi(split[2]) > 255)
		ft_free_colours(split);
	if (ft_atoi(split[0]) < 0 || ft_atoi(split[1]) < 0 || ft_atoi(split[2]) < 0)
		ft_free_colours(split);
	colour = 255;
	colour += ft_atoi(split[0]) << 24;
	colour += ft_atoi(split[1]) << 16;
	colour += ft_atoi(split[2]) << 8;
	return (ft_free_matrix(split), colour);
}
