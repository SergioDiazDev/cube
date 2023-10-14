
#include "cub3d.h"

void	ft_hook(void *param)
{
	t_player			*p;

	p = (t_player *) param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		exit(-33);
	//Separar
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
	{
		if (p->map[(int)(p->posX)][(int)(p->posY + p->dirY * speed)] != '1')
			p->posY += p->dirY * speed;
		if (p->map[(int)(p->posX + p->dirX * speed)][(int)(p->posY)] != '1')
			p->posX += p->dirX * speed;
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
	{
		if (p->map[(int)(p->posX)][(int)(p->posY - p->dirY * speed)] != '1')
			p->posY -= p->dirY * speed;
		if (p->map[(int)(p->posX - p->dirX * speed)][(int)(p->posY)] != '1')
			p->posX -= p->dirX * speed;
	}
	//Separar
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
	{
		if (p->map[(int)(p->posX)][(int)(p->posY - p->planeY * speed)] != '1')
			p->posY -= p->planeY * speed;
		if (p->map[(int)(p->posX - p->planeX * speed)][(int)(p->posY)] != '1')
			p->posX -= p->planeX * speed;
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
	{
		if (p->map[(int)(p->posX)][(int)(p->posY + p->planeY * speed)] != '1')
			p->posY += p->planeY * speed;
		if (p->map[(int)(p->posX + p->planeX * speed)][(int)(p->posY)] != '1')
			p->posX += p->planeX * speed;
	}
	//printf("X:%f\tY:%f\t= %c\n", p->posX, p->posY, p->map[(int)p->posX][(int)p->posY]);
	//Separar
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
	{
		double oldDirX = p->dirX;
		p->dirX = p->dirX * cos(speedRotate) - p->dirY * sin(speedRotate);
		p->dirY = oldDirX * sin(speedRotate) + p->dirY * cos(speedRotate);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(speedRotate) - p->planeY * sin(speedRotate);
		p->planeY = oldPlaneX * sin(speedRotate) + p->planeY * cos(speedRotate);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
	{
		double oldDir = p->dirX;
		p->dirX = p->dirX * cos(-speedRotate) - p->dirY * sin(-speedRotate);
		p->dirY = oldDir * sin(-speedRotate) + p->dirY * cos(-speedRotate);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(-speedRotate) - p->planeY * sin(-speedRotate);
		p->planeY = oldPlaneX * sin(-speedRotate) + p->planeY * cos(-speedRotate);
	}
	ft_paint(p);
}
