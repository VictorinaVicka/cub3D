/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:36:35 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 13:23:53 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int main(int argc, char **argv)
{
	int		scren;
	t_conf	conf;
	t_map	*map;

	scren = 0;
	if (argc == 1 || !(ft_dot(argv[1])) || (conf.fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error('a'));
	if (argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save\0", 7) != 0))
		return (argc > 3 ? ft_error('g') : ft_error('f'));
	if (argc == 3 && ft_strncmp(argv[2], "--save\0", 7) == 0)
		scren = 1;
	map = ft_init();
	ft_conf(conf.fd, map);
	conf.map = ft_map(conf.fd);
	close(conf.fd);
	ft_graphic(map, conf.map, scren);
	return (0);
}
