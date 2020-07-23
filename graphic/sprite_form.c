/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_form.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:22:01 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 12:37:31 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

void		ft_sprite_form(t_mlx *mlx, t_sprite *spr, int i)
{
	float	sin;

	spr->dist_conf = mlx->sprite[mlx->order_s[i]].dist;
	spr->x_pos = (-mlx->play->x + mlx->sprite[mlx->order_s[i]].s_x);
	spr->y_pos = (-mlx->play->y + mlx->sprite[mlx->order_s[i]].s_y);
	spr->cos = (spr->x_pos / spr->dist_conf) * mlx->play->cos +
					(spr->y_pos / spr->dist_conf) * mlx->play->sin;
	sin = (spr->y_pos / spr->dist_conf) * mlx->play->cos -
			(spr->x_pos / spr->dist_conf) * mlx->play->sin;
	spr->y_pos = spr->cos * spr->dist_conf;
	spr->screen = mlx->base->x / 2 + mlx->p * tan(asin(sin));
	spr->height = abs((int)(mlx->p * 32 / spr->y_pos));
	spr->y_str = (int)(mlx->base->y / 2 - spr->height / 2);
	spr->y_str = spr->y_str < 0 ? 0 : spr->y_str;
	spr->y_end = (int)(mlx->base->y / 2 + spr->height / 2);
	spr->y_end = spr->y_end >= mlx->base->y ? mlx->base->y - 1 : spr->y_end;
	spr->width = spr->height;
	spr->x_str = (int)(spr->screen - spr->width / 2);
	spr->x_end = (int)(spr->screen + spr->width / 2);
	spr->x_end = spr->x_end > mlx->base->x ? mlx->base->x - 1 : spr->x_end;
}

void	ft_print_spr(t_mlx *mlx, t_sprite spr, int y, int spr_n)
{
	int		col;

	col = 0;
	spr.y_pxl = (spr.height - mlx->base->y) / 2 + y;
	spr.y_pos = spr.y_pxl / spr.height * mlx->img[4]->height;
	col = ft_color_txt(mlx, 4, spr.x_pxl, (int)spr.y_pxl);
	if ((col & 0x00FFFFFF) != 0)
		ft_pixel_print(mlx, spr_n, y, col);
}
