#include "../includes/cub3d.h"



char worldMap[mapWidth][mapHeight] = {
  {"111111111111111111111111"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000000001"},
  {"100000000000000000100001"},
  {"100000000000000000100001"},
  {"100000000000000000100001"},
  {"111111111111111111111111"}
};



int main()
{
	t_player p;

	//Se deben inicializar en el parseo
	//inicializar mapa
	for (int i = 0; i < mapWidth; i++)
		for (int j = 0; j < mapHeight; j++)
		{
			p.map[i][j] = worldMap[i][j];
		}
	//Pos del jugador
	p.posX = 5;
	p.posY = 5;
	//Direciones respecto hacia donde se mira
	p.dirX = -1;
	p.dirY = 0;
	p.planeX = 0;
	p.planeY = 0.66;

	//Para la funcion init
	p.mlx = mlx_init(screenWidth, screenHeight, "CUB3D", false);
	p.bg = mlx_new_image(p.mlx, screenWidth, screenHeight);

	//Paint BackGround
	int i = -1;
	while (++i < WIDTH)
	{
		int j = -1;
		while (++j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				mlx_put_pixel(p.bg, i, j, 0x00CCCCFF);
			else
				mlx_put_pixel(p.bg, i, j, 0xC0C0C0FF);
		}
	}
	mlx_image_to_window(p.mlx, p.bg, 0, 0);
	//
	//Creo el lienzo para los muros (ft_init)
	p.walls = mlx_new_image(p.mlx, screenWidth, screenHeight);
	//Pinto los primeros muros
	ft_paint(&p);
	mlx_image_to_window(p.mlx, p.walls, 0, 0);
	//loops
	mlx_loop_hook(p.mlx, ft_hook, &p);
	mlx_loop(p.mlx);
	//Falta frees
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

		//sacar a funcion
		ft_deltas(p);
		//
		p->hit = 0;
		//sacar a funcion
		ft_steps(p);
		//
		//PERFORM DDA
		ft_performDda(p);
		//Calculate distance Walls
		ft_distanceWalls(p);
		//Color aqui hay que usar texturas 
		p->color = p->side ? 0xFBAED2FF : 0xfc030bff;
		//printf("X:%f Y:%f = %c\n",p->posX, p->posY, p->map[p->mapX][p->mapY]);
		ft_paintWalls(x, p);
		x++;
	}
	mlx_image_to_window(p->mlx, p->walls, 0, 0);
}
