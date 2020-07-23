/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:34:30 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 12:29:11 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int	ft_window(t_mlx *vars)
{
	mlx_hook(vars->base->win, 2, 1L << 0, ft_key, vars);
	return (0);
}

void	ft_create_mlx(t_mlx *mlx)
{
	mlx->base->mlx = mlx_init();
	mlx->base->win = mlx_new_window(mlx->base->mlx, mlx->base->x,
											mlx->base->y, "CUB3D");
	mlx->base->img = mlx_new_image(mlx->base->mlx, mlx->base->x,
											mlx->base->y);
	mlx->base->addr = mlx_get_data_addr(mlx->base->img,
											&mlx->base->bits_per_pixel,
											&mlx->base->line_length,
											&mlx->base->endian);
}

t_mlx	*ft_init_go(t_map *m, char **map)
{
	t_mlx	*mlx;

	if (!(mlx->sprite = ft_init_sprit(mlx)))
	{
		free(mlx->base);
		free(mlx->play);
		free(mlx);
		ft_exit(m, map, 'b');
	}
	if (!(mlx->base = ft_init_bade(*m)))
	{
		free(mlx);
		ft_exit(m, map, 'b');
	}
	if (!(mlx = ft_init_mlx(map, *m)))
		ft_exit(m, map, 'b');
	if (!(mlx->play = ft_init_play(map)))
	{
		free(mlx->base);
		free(mlx);
		ft_exit(m, map, 'b');
	}
	return (mlx);
}

int	ft_graphic(t_map *m, char **map, int scren)
{
	t_mlx	*mlx;

	mlx = ft_init_go(m, map);
	ft_create_mlx(mlx);
	if (!(ft_init_txt(mlx, m)))
	{
		free(mlx->play);
		ft_free_img2(mlx);
		free(mlx->sprite);
		free(mlx);
		ft_exit(m, map, 0);
	}
	ft_line(mlx);
	ft_free_txt(m);
	free(m);
	if (scren)
		ft_scren(mlx);
	mlx_hook(mlx->base->win, 17, 1L << 17, ft_end_window, mlx);
	mlx_loop_hook(mlx->base->mlx, ft_window, mlx);
	mlx_loop(mlx->base->mlx);
	return (2);
}