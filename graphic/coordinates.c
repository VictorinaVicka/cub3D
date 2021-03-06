/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:54:17 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 17:21:14 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int	ft_coordinat(char **map, char *s, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_choice(map[i][j], s) == 1)
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
