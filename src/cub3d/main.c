#include "cub3d.h"

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

int main(int ac, char **av)
{
	t_player	p;

	ac = 0;
	p.mapa = ft_get_map(av[1]);
	//Pos del jugador
	p.map = p.mapa.map_fill;
	p.p_x = p.mapa.pos_h + 0.5;
	p.p_y = p.mapa.pos_w + 0.5;
	//Direciones respecto hacia donde se mira problemas aqui.
	p.d_x = 0;
	p.d_y = -1;
	p.plan_x = 0.66;
	p.plan_y = 0;
	//Para la funcion init
	p.mlx = mlx_init(SCREEN_W, SCREEN_H, "CUB3D", false);
	p.bg = mlx_new_image(p.mlx, SCREEN_W, SCREEN_H);
	//Paint BackGround
	ft_paint_bg(&p);
	mlx_image_to_window(p.mlx, p.bg, 0, 0);
	//Creo el lienzo para los muros (ft_init)
	p.walls = mlx_new_image(p.mlx, SCREEN_W, SCREEN_H);
	//Pinto los primeros muros
	ft_paint(&p);
	mlx_image_to_window(p.mlx, p.walls, 0, 0);
	//loops
	mlx_loop_hook(p.mlx, ft_hook, &p);
	mlx_loop(p.mlx);
	//Falta frees
	ft_free_map(&p.mapa);
	return (0);
}
