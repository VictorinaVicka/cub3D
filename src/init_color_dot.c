/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:12:48 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 17:50:53 by tfarenga         ###   ########.fr       */
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


t_txt    *ft_init(void)
{
    t_txt    *txt;

    if (!(txt = malloc(sizeof(t_txt))))
        return (NULL);
    txt->west = NULL;
    txt->east = NULL;
    txt->north = NULL;
    txt->south = NULL;
    txt->str = NULL;
    return (txt);
}

t_param *ft_init_param(void)
{
    t_param *param;

    if (!(param = malloc(sizeof(t_param))))
        return (NULL);
    param->res[0] = 0;
    param->floor[0] = 0;
    param->ceilling[0] = 0;
    return (param);
}

int        ft_dot(char *file)
{
    int len;

    len = ft_strlen(file) - 1;
    if (file[len] == 'b' && file[len - 1] == 'u'
        && file[len - 2] == 'c' && file[len - 3] == '.')
        return (1);
    return (0);
}
