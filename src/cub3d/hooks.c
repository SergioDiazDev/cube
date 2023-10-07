
#include "cub3d.h"

void	ft_hook(void *param)
{
	t_player			*p;

	p = (t_player *) param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		exit(-33);
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
	{
		if ((p->posY + p->dirY * 0.2 > 0) && (p->posX - p->dirX * 0.2 > 0)
			&& p->posY + p->dirY * 0.2 < mapHeight && p->posX - p->dirX * 0.2 < mapWidth)
		{
			if (p->map[(int)(p->posX - 0.5)][(int)(p->posY - 0.5)] == '0')
			{
				p->posY -= p->dirY * 0.2;
				p->posX -= p->dirX * 0.2;
			}
			else
			{
				p->posY += p->dirY * 0.2;
				p->posX += p->dirX * 0.2;
			}
		}
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
	{
		if ((p->posY - p->dirY * 0.2 > 0) && (p->posX + p->dirX * 0.2 > 0)
			&& p->posY + p->dirY  * 0.2 < mapHeight && p->posX - p->dirX  * 0.2 < mapWidth)
		{
			if (p->map[(int)(p->posX + 0.5)][(int)(p->posY + 0.5)] == '0')
			{
				p->posY += p->dirY * 0.2;
				p->posX += p->dirX * 0.2;
			}
			else
			{
				p->posY -= p->dirY * 0.2;
				p->posX -= p->dirX * 0.2;
			}
		}
	}
	printf("X:%f\tY:%f\t= %c\n", p->posX, p->posY, p->map[(int)p->posX][(int)p->posY]);
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT) || mlx_is_key_down(p->mlx, MLX_KEY_A))
	{
		double oldDirX = p->dirX;
		p->dirX = p->dirX * cos(0.2) - p->dirY * sin(0.2);
		p->dirY = oldDirX * sin(0.2) + p->dirY * cos(0.2);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(0.2) - p->planeY * sin(0.2);
		p->planeY = oldPlaneX * sin(0.2) + p->planeY * cos(0.2);
	}
	else if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(p->mlx, MLX_KEY_D))
	{
		double oldDir = p->dirX;
		p->dirX = p->dirX * cos(-0.2) - p->dirY * sin(-0.2);
		p->dirY = oldDir * sin(-0.2) + p->dirY * cos(-0.2);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(-0.2) - p->planeY * sin(-0.2);
		p->planeY = oldPlaneX * sin(-0.2) + p->planeY * cos(-0.2);
	}
	ft_paint(p);
}
