#include "../includes/cub3d.h"

void	ft_performDda(t_player *p)
{
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
			if (p->map[p->mapX][p->mapY] == '1')
				p->hit = 1;
		}
}

void	ft_distanceWalls(t_player *p)
{
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
}

void ft_deltas(t_player *p)
{
	if (!p->rayDirX)
			p->deltaDistX = 1e30;
	else
		p->deltaDistX = fabs(1 / p->rayDirX);
	if (!p->rayDirY)
		p->deltaDistY = 1e30;
	else
		p->deltaDistY = fabs(1 /p->rayDirY);
}

void	ft_steps(t_player *p)
{
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
}