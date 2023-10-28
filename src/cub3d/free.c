#include "cub3d.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_free_map(t_map *map)
{
	if (map->file)
		ft_free_matrix(map->file);
	if (map->map_fill)
		ft_free_matrix(map->map_fill);
	if (map->textures.east)
		mlx_delete_texture(map->textures.east);
	if (map->textures.south)
		mlx_delete_texture(map->textures.south);
	if (map->textures.west)
		mlx_delete_texture(map->textures.west);
	if (map->textures.north)
		mlx_delete_texture(map->textures.north);
}
