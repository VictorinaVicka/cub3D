/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:42:45 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 12:27:57 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int		ft_end_window(void *p)
{
	ft_game_end(p);
	return (0);
}

void	ft_free_img2(t_mlx *mlx)
{
	mlx_destroy_image(mlx->base->mlx, mlx->base->img);
	mlx_destroy_window(mlx->base->mlx, mlx->base->win);
	free(mlx->base->mlx);
	free(mlx->base);
}