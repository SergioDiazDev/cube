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

	cont = 0;
	line = get_next_line(fd);
	if (line[0] != '\n')
			cont++;
	while (line)
	{
		if (line[0] != '\n')
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

void	ft_introduce_line(char **file, int max, int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	if (s[0] != '\n')
		file[i++] = s;
	while (i < max && s)
	{
		s = get_next_line(fd);
		if (!s)
			file[i++] = s;
		else
		{
			if (s[0] != '\n')
				file[i++] = s;
			else
				free(s);
		}
	}
}

char	**ft_read_file(char *str, int max)
{
	char	**file;
	int		fd;

	file = (char **) malloc(sizeof(char *) * max);
	if (!file)
		return (NULL);
	fd = ft_open_fd(str);
	ft_introduce_line(file, max, fd);
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