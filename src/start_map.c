/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:13:05 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 18:17:35 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int        ft_pos(char **map)
{
    int        i;
    int        j;
    int        pos;

    i = 0;
    pos = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (ft_choice("WENS\0", map[i][j]) == 1)
                pos++;
            j++;
        }
        i++;
    }
    return (pos == 1 ? 1 : 0);
}

int    ft_len_m(char **mass)
{
    int i;

    i = 0;
    while (mass[i] != NULL)
        i++;
    return (i);
}

char    **ft_real_arr(char *line, char **map)
{
    char    **resu;
    int        i;

    i = 0;
    if (!(resu = (char **)malloc(sizeof(char *) * (ft_len_m(map) + 2))))
        return (NULL);
    while (map[i] != NULL)
    {
        resu[i] = ft_strdup(map[i]);
        i++;
    }
    resu[i++] = ft_strdup(line);
    resu[i] = NULL;
    i = 0;
    ft_free(map);
    return (resu);
}

char    **ft_map(int fd)
{
    char    *line;
    char    **map;
    int     resu;

    if (!(map = (char **)malloc(sizeof(char *))))
        return (NULL);
    map[0] = NULL;
    while ((resu = get_next_line(fd, &line)) > 0)
    {
        if (line[0] != '\0')
            map = ft_real_arr(line, map);
        free(line);
    }
    if (line[0] != '\0')
        map = ft_real_arr(line, map);
    free(line);
    if (ft_full_map(map) == 1 && ft_pos(map) == 1
    && ft_choice_mass(" 012WENS\0", map) != 0 && resu != -1)
        return (map);
    else
    {
        ft_free(map);
        return (NULL);
    }
}

int        ft_full_map(char **map)
{
    int        x;
    int        y;

    x = 0;
    y = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (map[y][x] != ' ' && map[y][x] != '1')
            {
                if (y - 1 < 0
                    || map[y + 1][x] == ' ' || x - 1 < 0
                    || (int)ft_strlen(map[y + 1]) <= x
                    || (int)ft_strlen(map[y - 1]) <= x || map[y - 1][x] == ' '
                    || map[y][x - 1] == ' ' || x + 1 >= (int)ft_strlen(map[y])
                    || y + 1 >= (int)ft_len_m(map) || map[y][x + 1] == ' ')
                    return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}
