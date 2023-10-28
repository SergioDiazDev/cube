#include "cub3d.h"

static void	ft_move_w_s(t_player *p)
{
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
	{
		if (p->map[(int)(p->p_x)][(int)(p->p_y + p->d_y * SPEED)] != '1')
			p->p_y += p->d_y * SPEED;
		if (p->map[(int)(p->p_x + p->d_x * SPEED)][(int)(p->p_y)] != '1')
			p->p_x += p->d_x * SPEED;
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
	{
		if (p->map[(int)(p->p_x)][(int)(p->p_y - p->d_y * SPEED)] != '1')
			p->p_y -= p->d_y * SPEED;
		if (p->map[(int)(p->p_x - p->d_x * SPEED)][(int)(p->p_y)] != '1')
			p->p_x -= p->d_x * SPEED;
	}
}

static void	ft_move_a_d(t_player *p)
{
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
	{
		if (p->map[(int)(p->p_x)][(int)(p->p_y - p->plan_y * SPEED)] != '1')
			p->p_y -= p->plan_y * SPEED;
		if (p->map[(int)(p->p_x - p->plan_x * SPEED)][(int)(p->p_y)] != '1')
			p->p_x -= p->plan_x * SPEED;
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
	{
		if (p->map[(int)(p->p_x)][(int)(p->p_y + p->plan_y * SPEED)] != '1')
			p->p_y += p->plan_y * SPEED;
		if (p->map[(int)(p->p_x + p->plan_x * SPEED)][(int)(p->p_y)] != '1')
			p->p_x += p->plan_x * SPEED;
	}
}

static void	ft_rotate(t_player *p)
{
	double	old_dirx;
	double	oplanx;

	old_dirx = p->d_x;
	oplanx = p->plan_x;
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
	{
		p->d_x = p->d_x * cos(SPEED_R) - p->d_y * sin(SPEED_R);
		p->d_y = old_dirx * sin(SPEED_R) + p->d_y * cos(SPEED_R);
		p->plan_x = p->plan_x * cos(SPEED_R) - p->plan_y * sin(SPEED_R);
		p->plan_y = oplanx * sin(SPEED_R) + p->plan_y * cos(SPEED_R);
	}
	old_dirx = p->d_x;
	oplanx = p->plan_x;
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
	{
		p->d_x = p->d_x * cos(-SPEED_R) - p->d_y * sin(-SPEED_R);
		p->d_y = old_dirx * sin(-SPEED_R) + p->d_y * cos(-SPEED_R);
		p->plan_x = p->plan_x * cos(-SPEED_R) - p->plan_y * sin(-SPEED_R);
		p->plan_y = oplanx * sin(-SPEED_R) + p->plan_y * cos(-SPEED_R);
	}
}

void	ft_hook(void *param)
{
	t_player			*p;

	p = (t_player *) param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		exit(-33);
	ft_move_w_s(p);
	ft_move_a_d(p);
	ft_rotate(p);
	ft_paint(p);
}
