#include "cub3d.h"

void	ft_paint_wall(int x, t_player *p)
{
	int y;
	y = p->drawStart;
	while (y < p->drawEnd)
	{
		mlx_put_pixel(p->walls, x, y ,p->color);
		y++;
	}
}