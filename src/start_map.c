/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:13:05 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 18:27:13 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int		ft_pos(char **map)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_choice(map[i][j], "SWNE\0") == 1)
				pos++;
			j++;
		}
		i++;
	}
	return (pos == 1 ? 1 : 0);
}

char	**ft_real_arr(char **map, char *line)
{
	char	**resu;
	int		i;

	i = 0;
	if (!(resu = (char **)malloc(sizeof(char *) * (ft_len(map) + 2))))
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

char	**ft_map(int fd)
{
	char	*line;
	char	**map;
	int		resu;

	map = (char **)malloc(sizeof(char *));
	map[0] = NULL;
	while ((resu = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != '\0')
			map = ft_real_arr(map, line);
		free(line);
	}
	if (line[0] != '\0')
		map = ft_real_arr(map, line);
	free(line);
	if (ft_pos(map) == 1 && ft_full_map(map) == 1
	&& resu != -1 && ft_choice_mass(map, " 012SNWE\0") != 0)
		return (map);
	else
	{
		ft_free(map);
		return (NULL);
	}
}

int		ft_full_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '1' && map[y][x] != ' ')
			{
				if (y - 1 < 0
					|| (int)ft_strlen(map[y - 1]) <= x || map[y - 1][x] == ' '
					|| (int)ft_strlen(map[y + 1]) <= x
					|| map[y][x - 1] == ' ' || x + 1 >= (int)ft_strlen(map[y])
					|| y + 1 >= (int)ft_len(map) || map[y][x + 1] == ' '
					|| map[y + 1][x] == ' ' || x - 1 < 0)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
