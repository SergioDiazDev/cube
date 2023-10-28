#include "cub3d.h"

void	ft_paint_bg(t_player *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_W)
	{
		j = -1;
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

void	ft_paint_wall(int x, t_player *p, mlx_texture_t	*tex)
{
	int			y;
	double		step;
	double		tex_pos;
	uint32_t	u;

	y = p->draw_start;
	step = (double) tex->height / p->line_height;
	tex_pos = (p->draw_start - SCREEN_H / 2 + p->line_height / 2) * step;
	while (y < p->draw_end)
	{
		u = ft_get_uin32(tex->pixels, tex->width * (int) tex_pos * 4 + (int) p->tex_x * 4);
		mlx_put_pixel(p->walls, x, y, u);
		tex_pos += step;
		y++;
	}
}

void	ft_get_tex_x(t_player *p)
{
	double	wallx;

	if (p->side == 0 || p->side == 2)
		wallx = p->p_y + p->perp_wall_dist * p->ray_d_y;
	else
		wallx = p->p_x + p->perp_wall_dist * p->ray_d_x;
	wallx = wallx - (int)wallx;
	p->tex_x = (int)(wallx * (double)p->mapa.tex.n->width);
	if ((p->side == 2 || p->side == 1))
		p->tex_x = p->mapa.tex.n->width - p->tex_x - 1;
}

mlx_texture_t	*ft_get_texture(t_player *p)
{
	if (p->side == 0)
		return (p->mapa.tex.n);
	else if (p->side == 1)
		return (p->mapa.tex.e);
	else if (p->side == 2)
		return (p->mapa.tex.s);
	else
		return (p->mapa.tex.w);
}

void	ft_paint(t_player *p)
{
	int				x;
	mlx_texture_t	*tex;

	if (p->walls)
	{
		mlx_delete_image(p->mlx, p->walls);
		p->walls = mlx_new_image(p->mlx, SCREEN_W, SCREEN_H);
	}
	x = 0;
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
		tex = ft_get_texture(p);
		ft_get_tex_x(p);
		ft_paint_wall(x, p, tex);
		x++;
	}
	mlx_image_to_window(p->mlx, p->walls, 0, 0);
}
