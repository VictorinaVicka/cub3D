/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:12:24 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 13:12:27 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int    ft_choice(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (c == str[i])
            return (1);
        i++;
    }
    return (0);
}

int    ft_choice_mass(char *set, char **map)
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
            if (ft_choice(set, map[i][j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
