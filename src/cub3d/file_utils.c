#include "cub3d.h"

int	ft_open_fd(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		perror(str);
		exit(1);
	}
	return (fd);
}

int	ft_size_file(int fd)
{
	int		cont;
	char	*line;

	line = get_next_line(fd);
	cont = 0;
	while (line)
	{
		cont++;
		line = get_next_line(fd);
	}
	return (cont);
}

int	ft_get_size_file(char *str)
{
	int	max;
	int	fd;

	max = 0;
	fd = ft_open_fd(str);
	max = ft_size_file(fd);
	close(fd);
	return (max);
}

char	**ft_read_file(char *str, int max)
{
	char	**file;
	int		fd;
	int		i;

	file = (char **) malloc(sizeof(char *) * max);
	if (!file)
		return (NULL);
	fd = ft_open_fd(str);
	i = 0;
	file[i] = get_next_line(fd);
	while (file[i])
	{
		i++;
		file[i] = get_next_line(fd);
	}
	close(fd);
	return (file);
}

char	**ft_get_file(char *str)
{
	char	**file;
	int		max;

	max = ft_get_size_file(str);
	if (max == 0)
	{
		printf("Error\nFichero Vacio\n");
		exit (1);
	}
	file = ft_read_file(str, max);
	return (file);
}