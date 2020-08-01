/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:36:35 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 17:01:35 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_file/cub3d.h"

int	main(int argc, char **argv)
{
	int		screen;
	char	**card;
	t_txt	*txt;
	t_param	*param;
	int		fd;

	screen = 0;
	if (argc == 1 || !(ft_dot(argv[1])) || (fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error('a'));
	if (argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save\0", 7) != 0))
		return (argc > 3 ? ft_error('g') : ft_error('f'));
	if (argc == 3 && ft_strncmp(argv[2], "--save\0", 7) == 0)
		screen = 1;
	if (!(txt = ft_init()) || !(param = ft_init_param()))
		return (ft_error('b'));
	if (ft_conf(fd, txt, param) < 0)
		return (ft_error('c'));
	if (!(card = ft_map(fd)))
		return (ft_error('d'));
	close(fd);
	ft_graphic(txt, param, card, screen);
	return (0);
}
