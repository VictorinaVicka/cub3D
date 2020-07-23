/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:20:46 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 18:08:48 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

void	ft_free_base(t_mlx *mlx)
{
	mlx_destroy_image(mlx->base->mlx, mlx->base->img);
	mlx_destroy_window(mlx->base->mlx, mlx->base->win);
	free(mlx->base->mlx);
	free(mlx->base);
}

void	ft_free_img(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < 5)
	{
		free(mlx->img[i]->img_b);
		free(mlx->img[i]->img_a);
		free(mlx->img[i]);
		i++;
	}
	free(mlx->img);
}


void	ft_exit(t_txt *txt, t_param *param, char **map, char excode)
{
	ft_free_txt(txt);
	free(param);
	ft_free(map);
	ft_error(excode);
	exit(0);
}

void	ft_game_end(t_mlx *mlx)
{
	free(mlx->play);
	ft_free_base(mlx);
	ft_free_img(mlx);
	ft_free(mlx->map);
	free(mlx->sprite);
	free(mlx);
	exit(0);
}
