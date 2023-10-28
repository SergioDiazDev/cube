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
	if (map->tex.e)
		mlx_delete_texture(map->tex.e);
	if (map->tex.s)
		mlx_delete_texture(map->tex.s);
	if (map->tex.w)
		mlx_delete_texture(map->tex.w);
	if (map->tex.n)
		mlx_delete_texture(map->tex.n);
}
