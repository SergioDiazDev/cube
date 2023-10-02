#include "../includes/cub3d.h"



int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,2,1,2,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main()
{
	t_player p;

	//Se deben inicializar en el parseo
	//Pos del jugador
	p.posX = 10;
	p.posY = 10;
	//Direciones respecto hacia donde se mira
	p.dirX = -1;
	p.dirY = 0;
	p.planeX = 0;
	p.planeY = 0.66;

	p.mlx = mlx_init(screenWidth, screenHeight, "CUB3D", false);
	p.walls = mlx_new_image(p.mlx, screenWidth, screenHeight);
	ft_paint(&p);
	mlx_image_to_window(p.mlx, p.walls, 0, 0);
	
	mlx_loop_hook(p.mlx, ft_hook, &p);
	mlx_loop(p.mlx);
}

void	ft_paint(t_player *p)
{
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

		if (!p->rayDirX)
			p->deltaDistX = 1e30;
		else
			p->deltaDistX = fabs(1 / p->rayDirX);
		if (!p->rayDirY)
			p->deltaDistY = 1e30;
		else
			p->deltaDistY = fabs(1 /p->rayDirY);
		
		p->hit = 0;

		if (p->rayDirX < 0)
		{
			p->stepX = -1;
			p->sideDistX = (p->posX - p->mapX) * p->deltaDistX;
		}
		else
		{
			p->stepX = 1;
			p->sideDistX = (p->mapX + 1.0 - p->posX) * p->deltaDistX;
		}
		if (p->rayDirY < 0)
		{
			p->stepY = -1;
			p->sideDistY = (p->posY - p->mapY) * p->deltaDistY;
		}
		else
		{
			p->stepY = 1;
			p->sideDistY = (p->mapY + 1.0 - p->posY) * p->deltaDistY;
		}
		//PERFORM DDA
		while(p->hit == 0)
		{
			if (p->sideDistX < p->sideDistY)
			{
				p->sideDistX += p->deltaDistX;
				p->mapX += p->stepX;
				p->side = 0;
			}
			else
			{
				p->sideDistY += p->deltaDistY;
				p->mapY += p->stepY;
				p->side = 1;
			}
			//Cambiar mapa de int a char
			if (worldMap[p->mapX][p->mapY] > 0)
				p->hit = 1;
		}
		//

		//Calculate distance Walls
		if (!p->side)
			p->perpWallDist = p->sideDistX - p->deltaDistX;
		else
			p->perpWallDist = p->sideDistY - p->deltaDistY;
		//Calulate height Walls
		p->lineHeight = (int)(screenWidth / p->perpWallDist);
		p->drawStart = -p->lineHeight / 2 + screenHeight / 2;
		if (p->drawStart < 0)
			p->drawStart = 0;
		p->drawEnd = p->lineHeight / 2 + screenHeight / 2;
		if (p->drawEnd >= screenHeight)
			p->drawEnd = screenHeight - 1;
		
		//COlor
		p->color = p->side ? 0xFBAED2FF : 0xfc030bff;
		printf("S:%d E:%d\n",p->drawStart, p->drawEnd);
		ft_verLine(x, p);
		x++;
	}
	mlx_image_to_window(p->mlx, p->walls, 0, 0);
}

void	ft_verLine(int x, t_player *p)
{
	int y;
	y = p->drawStart;
	while (y < p->drawEnd)
	{
		mlx_put_pixel(p->walls, x, y ,p->color);
		y++;
	}

}