/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:33:13 by pbengoec          #+#    #+#             */
/*   Updated: 2023/01/31 19:55:32 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{	
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) &*s);
		s++;
	}
	if ((char)c == *s)
		return ((char *) &*s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *str, char *buf)
{
	char	*new;
	int		i;
	int		j;

	if (str == NULL)
	{
		str = (char *) malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (buf == NULL)
		return (NULL);
	new = (char *) malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	if (new == NULL)
		return (free(str), NULL);
	i = 0;
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	i = 0;
	while (buf[i])
		new[j++] = buf[i++];
	new[j] = '\0';
	return (free(str), new);
}
