#include "cub3d.h"

int main(int ac, char **av)
{
	t_player	p;

	ac = 0;
	p.mapa = ft_get_map(av[1]);
	// // Pos del jugador
	p.map = p.mapa.map_fill;
	p.posX = p.mapa.pos_h + 0.5;
	p.posY = p.mapa.pos_w + 0.5;
	//Direciones respecto hacia donde se mira problemas aqui.
	p.dirX = 0;
	p.dirY = -1;
	p.planeX = 0.66;
	p.planeY = 0;
	//Para la funcion init
	printf("%x\n", p.mapa.colours.ceiling);
	p.mlx = mlx_init(screenWidth, screenHeight, "CUB3D", false);
	p.bg = mlx_new_image(p.mlx, screenWidth, screenHeight);

	//Paint BackGround
	ft_paint_bg(&p);
	mlx_image_to_window(p.mlx, p.bg, 0, 0);
	//Creo el lienzo para los muros (ft_init)
	p.walls = mlx_new_image(p.mlx, screenWidth, screenHeight);
	//Pinto los primeros muros
	ft_paint(&p);
	mlx_image_to_window(p.mlx, p.walls, 0, 0);
	//loops
	mlx_loop_hook(p.mlx, ft_hook, &p);
	mlx_loop(p.mlx);
	// // Falta frees
}
