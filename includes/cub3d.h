
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH	1024
# define HEIGHT	1024
#define mapWidth 24
#define mapHeight 24
#define screenWidth 1024
#define screenHeight 1024

typedef struct s_map
{
	int			width;
	int			height;
	int			start_map;
	char		**map_fill;
	char		**file_fill;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*c;
	char		*f;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
}	t_map;

typedef struct s_player
{
	char		map[100][100];
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	double		perpWallDist;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	uint32_t	color;
	mlx_t		*mlx;
	mlx_image_t	*walls;
	mlx_image_t	*bg;
}	t_player;

//init_cub3d

////////////////////////////////////////////////////////
//hooks
void	ft_hook(void *param);


////////////////////////////////////////////////////////
//RayCaster
void	ft_perform_dda(t_player *p);
void	ft_distance_wall(t_player *p);
void	ft_deltas(t_player *p);
void	ft_steps(t_player *p);
////////////////////////////////////////////////////////
//Paint
void	ft_paint_bg(t_player *p);
void	ft_paint_wall(int x, t_player *p);
void	ft_paint(t_player *p);
#endif
