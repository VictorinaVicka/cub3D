/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:02:43 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 18:37:59 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

void	ft_pixel_print(t_mlx *vars, int x_str, int y_str, int col)
{
	char	*str;
	int		x;
	int		y;

	x = x_str;
	y = y_str;
	str = vars->base->addr + (y * vars->base->line_length
						+ x * (vars->base->bits_per_pixel / 8));
	*(unsigned int *)str = col;
}

void	ft_column_print(t_mlx *vars, float *param, int col)
{
	int		len;

	len = 0;
	while (len <= (int)param[2])
	{
		ft_pixel_print(vars, param[0], param[1] + len, col);
		len++;
	}
}

void	ft_paint_f_c(t_ray ray, t_mlx *vars)
{
	float	print[3];

	print[0] = ray.ray;
	print[1] = ray.off + ray.wall_he;
	print[2] = vars->base->y - 1 - ray.off - ray.wall_he;
	ft_column_print(vars, print, vars->floor);
	print[1] = 0;
	print[2] = ray.off;
	ft_column_print(vars, print, vars->ceilling);
}

void	ft_walls_print(t_mlx *vars, float *print, float cor)
{
	int		color;
	float	x_pix;
	float	y_pix;
	int		y;

	y = print[1];
	x_pix = vars->img[vars->txt_index]->width * cor;
	while (y < print[1] + print[2] && y < vars->base->y)
	{
		y_pix = (print[2] - vars->base->y) / 2 + y;
		y_pix = y_pix / print[2] * vars->img[vars->txt_index]->height;
		color = ft_color_txt(vars, vars->txt_index, (int)x_pix, (int)y_pix);
		ft_pixel_print(vars, print[0], y, color);
		y++;
	}
}

void	ft_paint_walls(t_ray ray, t_mlx *vars, float *print)
{
	float	cor;

	cor = 1 - (vars->v_ray[2] / 32 - (int)(vars->v_ray[2] / 32));
	vars->txt_index = 2;
	if (ray.v_len > ray.h_len && (ray.angle >= 0
									&& ray.angle < PI))
	{
		cor = 1 - (vars->h_ray[1] / 32 - (int)(vars->h_ray[1] / 32));
		vars->txt_index = 1;
	}
	else if (ray.v_len < ray.h_len && (ray.angle > 3 * PI / 2
										|| ray.angle < PI / 2))
	{
		cor = vars->v_ray[2] / 32 - (int)(vars->v_ray[2] / 32);
		vars->txt_index = 3;
	}
	else if (ray.v_len > ray.h_len && (ray.angle >= PI
										&& ray.angle < 2 * PI))
	{
		cor = vars->h_ray[1] / 32 - (int)(vars->h_ray[1] / 32);
		vars->txt_index = 0;
	}
	ft_walls_print(vars, print, cor);
}
