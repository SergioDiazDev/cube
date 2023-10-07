#include "cub3d.h"

char worldMap[mapWidth][mapHeight] = {
  {"111111111111111111111111"},
  {"100000000000000000000001"},
  {"100011111111100000000001"},
  {"100000000000000000000001"},
  {"100000111000000000000001"},
  {"100000000000000000000001"},
  {"100000001111000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000001111101011011"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000011111110000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000001111100000010001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000100001"},
  {"100000000000000000111111"},
  {"100000000000000000100001"},
  {"111111111111111111111111"}
};

int main(int ac, char **av)
{
	t_player p;

	if (ac == 1)
	{
		for (int i = 0; i < mapWidth; i++)
			for (int j = 0; j < mapHeight; j++)
			{
				p.map[i][j] = worldMap[i][j];
			}
	}
	else
		p.mapa = ft_get_map(av[1]);
	// // Pos del jugador
	// p.posX = 5.5;
	// p.posY = 5.5;
	// //Direciones respecto hacia donde se mira problemas aqui.
	// p.dirX = 0;
	// p.dirY = -1;
	// p.planeX = 0.66;
	// p.planeY = 0;
	// //Para la funcion init
	// p.mlx = mlx_init(screenWidth, screenHeight, "CUB3D", false);
	// p.bg = mlx_new_image(p.mlx, screenWidth, screenHeight);

	// //Paint BackGround
	// ft_paint_bg(&p);
	// mlx_image_to_window(p.mlx, p.bg, 0, 0);
	// //Creo el lienzo para los muros (ft_init)
	// p.walls = mlx_new_image(p.mlx, screenWidth, screenHeight);
	// //Pinto los primeros muros
	// ft_paint(&p);
	// mlx_image_to_window(p.mlx, p.walls, 0, 0);
	// //loops
	// mlx_loop_hook(p.mlx, ft_hook, &p);
	// mlx_loop(p.mlx);
	// // Falta frees
}
