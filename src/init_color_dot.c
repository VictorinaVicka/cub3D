/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:12:48 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 13:46:07 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int    ft_create_colors(int green, int blue, int red)
{
    if (green > MAX_COL || green < 0 || blue > MAX_COL
                || blue < 0 || red > MAX_COL || red < 0)
        return (-1);
    return (red << 16 | green << 8 | blue);
}


t_map    *ft_init(void)
{
    t_map    *map;

    if (!(map = malloc(sizeof(t_map))))
        return (NULL);
    map->west = NULL;
    map->east = NULL;
    map->north = NULL;
    map->south = NULL;
    map->str = NULL;
    map->res[0] = 0;
    map->floor[0] = 0;
    map->ceilling[0] = 0;
    return (map);
}

int        ft_dot(char *file)
{
    int len;

    len = ft_strlen(file) - 1;
    if (file[len] == 'h' && file[len - 1] == 'u'
        && file[len - 2] == 'i' && file[len - 3] == '.')
        return (1);
    return (0);
}
