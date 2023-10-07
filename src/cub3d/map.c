#include "cub3d.h"

t_map	ft_get_map(char *str)
{
	t_map	map;
	int		i;

	map.file = ft_get_file(str);
	i = 0;
	while (map.file[i])
	{
		printf("%s", map.file[i]);
		i++;
	}
	return (map);
}
