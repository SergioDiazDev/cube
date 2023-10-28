#include "cub3d.h"

void	ft_paint_bg(t_player *p)
{
	int	i;

	i = -1;
	while (++i < SCREEN_W)
	{
		int j = -1;
		while (++j < SCREEN_H)
		{
			if (j < SCREEN_H / 2)
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

	y = p->draw_start;
	step = (double) p->mapa.textures.north->height / p->line_height;
	tex_pos = (p->draw_start - SCREEN_H / 2 + p->line_height / 2) * step;
	while (y < p->draw_end)
	{
		u = ft_get_uin32(p->mapa.textures.north->pixels, p->mapa.textures.north->width * tex_pos * 4 + x * 4);
		mlx_put_pixel(p->walls, x, y, u);
		tex_pos += step;
		y++;
	}
}

void	ft_paint(t_player *p)
{
	//Elimino los muros antiguos
	if (p->walls)
	{
		mlx_delete_image(p->mlx, p->walls);
		p->walls = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H);
	}
	//Realizamos los calculos
	int x = 0;
	while (x < SCREEN_W)
	{
		p->cam = 2 * x / (double)SCREEN_W -1;
		p->ray_d_x = p->d_x + p->plan_x * p->cam;
		p->ray_d_y = p->d_y + p->plan_y * p->cam;
		p->map_x = (int)p->p_x;
		p->map_y = (int)p->p_y;
		ft_deltas(p);
		p->hit = 0;
		ft_steps(p);
		ft_perform_dda(p);
		ft_distance_wall(p);
		//Color aqui hay que usar texturas 
		//p->color = p->side ? 0x00000FF : 0xec8b00ff;
		if (p->side)
		{
			p->color = 0x00000FF;
		}
		else
		{
			p->color = 0xec8b00ff;
		}
		//printf("X:%f Y:%f = %c\n",p->posX, p->posY, p->map[p->mapX][p->mapY]);
		ft_paint_wall(x, p);
		x++;
	}
	mlx_image_to_window(p->mlx, p->walls, 0, 0);
}