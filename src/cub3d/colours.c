#include "cub3d.h"

char	*ft_strim_final(char *s)
{
	char	*dst;
	int		i;

	i = 0;
	while (s[i] && s[i] != ' ')
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
		exit (1);
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

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
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
	{
		perror("Error al introducir RGB");
		free(split);
		exit (1);
	}
	colour = 0;
	colour = ft_atoi(split[0]) << 16;
	colour += ft_atoi(split[1]) << 8;
	colour += ft_atoi(split[2]);
	ft_free_split(split);
	return (colour);
}

void	ft_get_colours(t_map *map)
{
	map->colours.floor = ft_get_colours_by_id("F", map->file[4]);
	map->colours.ceiling = ft_get_colours_by_id("C", map->file[5]);
}