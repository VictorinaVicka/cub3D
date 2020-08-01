/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:28:28 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 17:14:41 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

void		ft_count_sprite(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	mlx->count_s = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == '2')
			{
				mlx->count_s++;
			}
			j++;
		}
		i++;
	}
}

void		ft_select_spr_next(t_mlx *vars, float *str)
{
	float	dst;
	int		ordr;
	int		i;

	i = -1;
	while (++i < vars->count_s - 1)
	{
		if (str[i] < str[i + 1])
		{
			dst = str[i];
			str[i] = str[i + 1];
			str[i + 1] = dst;
			ordr = vars->order_s[i];
			vars->order_s[i] = vars->order_s[i + 1];
			vars->order_s[i + 1] = ordr;
			i = -1;
		}
	}
}

void		ft_select_spr(t_mlx *vars)
{
	float	str[vars->count_s];
	int		i;

	i = 0;
	if (!(vars->order_s = malloc(sizeof(int) * vars->count_s)))
	{
		ft_error('b');
		ft_game_end(vars);
	}
	while (i < vars->count_s)
	{
		str[i] = ((vars->play->x - vars->sprite2[i].s_x) *
				(vars->play->x - vars->sprite2[i].s_x)) +
				((vars->play->y - vars->sprite2[i].s_y) *
				(vars->play->y - vars->sprite2[i].s_y));
		vars->order_s[i] = i;
		vars->sprite2[i].dist = sqrtf(str[i]);
		i++;
	}
	ft_select_spr_next(vars, str);
}


t_sprite2	*ft_init_sprit(t_mlx *mlx)
{
	t_sprite2	*sprite;
	int			count;
	int			i;
	int			j;

	ft_count_sprite(mlx);
	if (!(sprite = malloc(sizeof(t_sprite2) * mlx->count_s)))
		return (NULL);
	i = -1;
	count = 0;
	while (mlx->map[++i] != NULL)
	{
		j = -1;
		while (mlx->map[i][++j] != '\0')
			if (mlx->map[i][j] == '2')
			{
				sprite[count].x = j;
				sprite[count].s_x = j * 32 + 16;
				sprite[count].y = i;
				sprite[count++].s_y = i * 32 + 16;
			}
	}
	return (sprite);
}

void		ft_show_spr(t_mlx *mlx)
{
	int			spr_n;
	t_sprite	spr;
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (++i < mlx->count_s)
	{
		ft_sprite_form(mlx, &spr, i);
		spr_n = spr.x_str;
		while (spr_n < spr.x_end)
		{
			if (spr.cos >= 0 && spr_n > 0 &&
				spr_n < mlx->base->x && spr.dist_conf < mlx->length[spr_n])
			{
				spr.x_pxl = (spr_n - spr.x_str) *
									mlx->img[4]->width / spr.width;
				j = spr.y_str;
				while (j < spr.y_end)
					ft_print_spr(mlx, spr, j++, spr_n);
			}
			spr_n++;
		}
	}
}
