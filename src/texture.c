/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:13:15 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 18:23:38 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int		ft_len(char **list)
{
	int i;

	i = 0;
	while (list[i] != NULL)
		i++;
	return (i);
}

int		ft_number(char **list)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (list[i][j])
		{
			if (list[i][j] != ',' && ft_isdigit(list[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_ceilling(char **list, t_param *param, int len)
{
	char		**color;
	size_t		green;
	size_t		blue;
	size_t		red;

	if ((len != 4 && len != 2) || param->ceilling[0]
		|| ft_strncmp(list[0], "C\0", 2))
		return (-2);
	color = (len == 2 ? ft_split(list[1], ',') : NULL);
	if (color != NULL && ft_len(color) != 3)
	{
		ft_free(color);
		return (-2);
	}
	if (ft_number(len == 2 ? color : list + 1) == -1)
		return (-2);
	green = ft_atoi(len == 2 ? color[0] : list[1]);
	blue = ft_atoi(len == 2 ? color[1] : list[2]);
	red = ft_atoi(len == 2 ? color[2] : list[3]);
	if (color)
		ft_free(color);
	param->ceilling[0] = 1;
	param->ceilling[1] = ft_create_colors(green, blue, red);
	return (param->ceilling[1] != -1 ? 1 : -2);
}

int		ft_floor(char **list, t_param *param, int len)
{
	char		**color;
	size_t		green;
	size_t		blue;
	size_t		red;

	if ((len != 4 && len != 2) || ft_strncmp(list[0], "F\0", 2)
		|| param->floor[0])
		return (-2);
	color = (len == 2 ? ft_split(list[1], ',') : NULL);
	if (color != NULL && ft_len(color) != 3)
	{
		ft_free(color);
		return (-2);
	}
	if (ft_number(len == 2 ? color : list + 1) == -1)
		return (-2);
	green = ft_atoi(len == 2 ? color[0] : list[1]);
	blue = ft_atoi(len == 2 ? color[1] : list[2]);
	red = ft_atoi(len == 2 ? color[2] : list[3]);
	if (color)
		ft_free(color);
	param->floor[0] = 1;
	param->floor[1] = ft_create_colors(green, blue, red);
	return (param->floor[1] != -1 ? 1 : -2);
}

int		ft_textur(char **list, t_txt *textur, char *flag)
{
	if (ft_len(list) == 2 && *flag != 'e' && *flag != 'b')
	{
		if (!(ft_strncmp(list[0], "NO\0", 3)) && !(textur->north))
			textur->north = ft_strdup(list[1]);
		else if (!(ft_strncmp(list[0], "SO\0", 3)) && !(textur->south))
			textur->south = ft_strdup(list[1]);
		else if (!(ft_strncmp(list[0], "WE\0", 3)) && !(textur->west))
			textur->west = ft_strdup(list[1]);
		else if (!(ft_strncmp(list[0], "EA\0", 3)) && !(textur->east))
			textur->east = ft_strdup(list[1]);
		else if (!(ft_strncmp(list[0], "S\0", 2)) && !(textur->spr))
			textur->spr = ft_strdup(list[1]);
		else
			return (-1);
	}
	else
		return (-1);
	if (textur->north && textur->south && textur->west
		&& textur->east && textur->spr)
		*flag = (*flag == 'p' ? 'b' : 'e');
	return (1);
}
