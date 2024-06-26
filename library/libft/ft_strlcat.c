/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:28:15 by pbengoec          #+#    #+#             */
/*   Updated: 2022/09/29 17:47:55 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(dst);
	i = 0;
	if (dstsize <= size)
		return (ft_strlen(src) + dstsize);
	while (src[i] && (size + i) < dstsize - 1)
	{
		dst[size + i] = src[i];
		i++;
	}
	dst[size + i] = '\0';
	return (size + ft_strlen(src));
}
