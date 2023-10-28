#include "cub3d.h"

void	ft_paint_bg(t_player *p)
{
	int	i;

	i = -1;
	while (++i < screenWidth)
	{
		int j = -1;
		while (++j < screenHeight)
		{
			if (j < screenHeight / 2)
				mlx_put_pixel(p->bg, i, j, p->mapa.colours.ceiling);
			else
				mlx_put_pixel(p->bg, i, j, p->mapa.colours.floor);
		}
	}
}

uint32_t	ft_get_uin32(uint8_t *conv, int n)
{
	uint32_t	u;

	u = conv[n] << 24;
	u += conv[n + 1] << 16;
	u += conv[n + 2] << 8;
	u += conv[n + 3];
	return (u);
}

void	ft_paint_wall(int x, t_player *p)
{
	int			y;
	double		step;
	double		tex_pos;
	uint32_t	u;

	y = p->drawStart;
	step = (double) p->mapa.textures.north->height / p->lineHeight;
	tex_pos = (p->drawStart - screenHeight / 2 + p->lineHeight / 2) * step;
	while (y < p->drawEnd)
	{
		u = ft_get_uin32(p->mapa.textures.north->pixels, p->mapa.textures.north->width * y * 4 + x * 4);
		mlx_put_pixel(p->walls, x, y, u); 
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
		p->color = p->side ? 0x00000FF : 0xec8b00ff;
		//printf("X:%f Y:%f = %c\n",p->posX, p->posY, p->map[p->mapX][p->mapY]);
		ft_paint_wall(x, p);
		x++;
	}
	mlx_image_to_window(p->mlx, p->walls, 0, 0);
}