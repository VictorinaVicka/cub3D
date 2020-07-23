/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:12:56 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 18:21:54 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int        ft_resol(char **list, t_param *param, int len)
{
    int        x;
    int        y;

    x = 0;
    if (len == 3 && !(ft_strncmp(list[0], "R\0", 2))
                && !(param->res[0]))
    {
        while (list[1][x])
            if (ft_isdigit(list[1][x++]) == 0)
                return (-1);
        x = 0;
        while (list[2][x])
            if (ft_isdigit(list[2][x++]) == 0)
                return (-1);
        param->res[0] = 1;
        x = ft_atoi(list[1]);
        y = ft_atoi(list[2]);
        x = x > MONITOR_WIDTH ? MONITOR_WIDTH: x;
        y = y > MONITOR_HEIGHT ? MONITOR_HEIGHT : y;
        param->res[1] = x < MIN_WNW ? MIN_WNW : x;
        param->res[2] = y < MIN_WNW ? MIN_WNW : y;
        return (1);
    }
    else
        return (-2);
}

int    ft_param(char **list, t_param *param, char *flag)
{
    int floor;
    int ceilling;
    int res;
    int len;

    len = ft_len(list);
    floor = 0;
    if ((res = ft_resol(list, param, len)) == -2)
        if ((floor = ft_floor(list, param, len)) == -2)
            if ((ceilling = ft_ceilling(list, param, len)) == -2)
                return (-1);
    if (param->res[0] && param->floor[0] && param->ceilling[0])
        *flag = (*flag == 'e' ? 'b' : 'p');
    return (1);
}

int        ft_conf(int fd, t_txt *txt, t_param *param)
{
    char    *line;
    char    **pars;
    char    flag;

    flag = 0;
    while (flag != 'b' && get_next_line(fd, &line) > 0)
    {
        pars = ft_split(line, ' ');
        if (line[0] != '\0')
            if (ft_param(pars, param, &flag) < 0)
                if (ft_textur(pars, txt, &flag) < 0)
                    return (ft_free_conf(txt, param, line, pars));
        ft_free(pars);
        free(line);
    }
    if (flag != 'b')
    {
        free(param);
        ft_free_txt(txt);
        return (-1);
    }
    return (1);
}
