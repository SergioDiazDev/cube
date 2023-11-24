/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:10:11 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/24 16:59:36 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *err)
{
	printf("%sError\n%s%s", RED, err, NC);
	exit (1);
}

void	ft_error_line(char *err, char *str)
{
	printf("%sError\n%s: %s%s", RED, err, str, NC);
	exit (1);
}
