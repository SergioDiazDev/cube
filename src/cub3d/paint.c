#include "cub3d.h"

void	ft_paint_bg(t_player *p)
{
	int	i;
	i = -1;
	while (++i < WIDTH)
	{
		int j = -1;
		while (++j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				mlx_put_pixel(p->bg, i, j, 0x00CCCCFF);
			else
				mlx_put_pixel(p->bg, i, j, 0xC0C0C0FF);
		}
	}
}

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

void	ft_paint(t_player *p)
{
	//Elimino los muros antiguos
	if (p->walls)
	{
		mlx_delete_image(p->mlx, p->walls);
		p->walls = mlx_new_image(p->mlx, screenWidth, screenHeight);
	}
	//Realizamos los calculos
	int x = 0;
	while (x < screenWidth)
	{
		p->cameraX = 2 * x / (double)screenWidth -1;
		p->rayDirX = p->dirX + p->planeX * p->cameraX;
		p->rayDirY = p->dirY + p->planeY * p->cameraX;
		p->mapX = (int)p->posX;
		p->mapY = (int)p->posY;

		ft_deltas(p);
		p->hit = 0;
		ft_steps(p);
		ft_perform_dda(p);
		ft_distance_wall(p);
		//Color aqui hay que usar texturas 
		p->color = p->side ? 0xFBAED2FF : 0xfc030bff;
		//printf("X:%f Y:%f = %c\n",p->posX, p->posY, p->map[p->mapX][p->mapY]);
		ft_paint_wall(x, p);
		x++;
	}
	mlx_image_to_window(p->mlx, p->walls, 0, 0);
}