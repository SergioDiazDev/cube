/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:23 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/23 20:48:41 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_size_file(int fd)
{
	int		cont;
	char	*line;

	cont = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		cont++;
	}
	return (cont);
}

int	ft_get_size_file(char *str)
{
	int	max;
	int	fd;

	max = 0;
	fd = ft_open_fd(str);
	if (fd == -1)
		ft_error("Fichero no existe");
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
	if (s)
		file[i++] = s;
	while (i < max && s)
	{
		s = get_next_line(fd);
		if (s)
			file[i++] = s;
	}
	file[i] = NULL;
}

char	**ft_read_file(char *str, int max)
{
	char	**file;
	int		fd;

	fd = ft_open_fd(str);
	if (fd == -1)
		ft_error("Fichero no existe");
	file = (char **) malloc(sizeof(char *) * max + 1);
	if (!file)
	{
		close(fd);
		ft_error("FILE malloc problem");
	}
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
		ft_error("Fichero Vacio");
	file = ft_read_file(str, max);
	return (file);
}
