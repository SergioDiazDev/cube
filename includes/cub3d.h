
#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h> 
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../library/MLX42/include/MLX42/MLX42.h"
# include "../library/libft/libft.h"

#define speedRotate 0.05
#define speed 0.1
#define screenWidth 1024
#define screenHeight 1024

typedef struct textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}t_textures;

typedef struct colours
{
	uint32_t	ceiling;
	uint32_t	floor;
}t_colours;

typedef struct s_map
{
	int			width;
	int			height;
	int			pos_w;
	int			pos_h;
	char		dir;
	char		**map_fill;
	char		**file;
	t_textures	textures;
	t_colours	colours;
}	t_map;

typedef struct s_player
{
	char		**map;
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
	t_map		mapa;
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
////////////////////////////////////////////////////////
//MAP PARSE
t_map	ft_get_map(char *str);
////////////////////////////////////////////////////////
//GNL
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
////////////////////////////////////////////////////////
//FILE UTILS
char	**ft_get_file(char *str);
////////////////////////////////////////////////////////
//TEXTURES
void	ft_get_textures(t_map map);
////////////////////////////////////////////////////////
//COLOURS
char	*ft_strim_final(char *s);
void	ft_get_colours(t_map *map);

#endif
