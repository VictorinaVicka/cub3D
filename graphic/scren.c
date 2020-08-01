/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scren.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:51:58 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 18:35:46 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int		ft_col_screen(t_mlx *mlx, int x, int y)
{
	int i;
	int col;

	col = *(int *)(mlx->base->addr + (4 * (int)mlx->base->x
			* ((int)mlx->base->y - 1 - y)) + (4 * x));
	i = (col & 0xFF0000) | (col & 0x00FF00) | (col & 0x0000FF);
	return (i);
}

void	ft_trans(unsigned char *str, int i)
{
	str[0] = (unsigned char)(i);
	str[1] = (unsigned char)(i >> 8);
	str[2] = (unsigned char)(i >> 16);
	str[3] = (unsigned char)(i >> 24);
}

int		ft_bmp(int p_size, int fd, int width, int height)
{
	int				f_size;
	unsigned char	head[54];

	f_size = 54 + (p_size * height) + (width * 3 * height);
	ft_bzero(head, 54);
	head[0] = (unsigned char)('B');
	head[1] = (unsigned char)('M');
	ft_trans(head + 2, f_size);
	head[10] = (unsigned char)(54);
	head[14] = (unsigned char)(40);
	ft_trans(head + 18, width);
	ft_trans(head + 22, height);
	head[26] = (unsigned char)(1);
	head[28] = (unsigned char)(24);
	return (!(write(fd, head, 54) < 0));
}

int		ft_paint_screen(int p_size, int fd, t_mlx *mlx)
{
	int				x;
	int				y;
	unsigned char	z[3];
	int				col;

	y = 0;
	ft_bzero(z, 3);
	while (y < mlx->base->y)
	{
		x = 0;
		while (x < mlx->base->x)
		{
			col = ft_col_screen(mlx, x, y);
			if (p_size > 0 && write(fd, &z, p_size) < 0)
				return (0);
			if (write(fd, &col, 3) < 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		ft_scren(t_mlx *mlx)
{
	int p_size;
	int f_size;
	int fd;

	p_size = (4 - ((int)mlx->base->x * 3) % 4) % 4;
	f_size = 54 + (3 * ((int)mlx->base->x + p_size)
					* (int)mlx->base->y);
	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT, 0777
									| O_TRUNC | O_APPEND)) < 0)
	{
		ft_error('s');
		ft_game_end(mlx);
	}
	ft_bmp(p_size, fd, mlx->base->x, mlx->base->y);
	ft_paint_screen(p_size, fd, mlx);
	close(fd);
	ft_game_end(mlx);
	return (0);
}
