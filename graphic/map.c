/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:48:40 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 18:35:18 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

void	ft_vertical_wall(t_mlx *vars, t_ray *ray)
{
	ray->map_x = (int)((ray->x < 0 ? 0 : ray->x) / 32);
	ray->map_y = (int)((ray->y < 0 ? 0 : ray->y) / 32);
	while (ray->x > 0 && ray->y > 0 && ray->y < ft_len(vars->map) * 32)
	{
		ray->map_x = (int)(ray->x / 32);
		ray->map_y = (int)(ray->y / 32);
		if (vars->map[ray->map_y][ray->map_x] == '1')
			break ;
		ray->x += ray->x_off;
		ray->y += ray->y_off;
	}
	ray->length = ft_direct_ray(vars->play->x, vars->play->y, ray->x, ray->y);
	vars->v_ray[0] = ray->length;
	vars->v_ray[1] = ray->x;
	vars->v_ray[2] = ray->y;
}

void	ft_vertical(t_mlx *vars, float angle)
{
	t_ray	ray;

	if (angle == PI / 2 || angle == 3 * PI / 2)
	{
		ray.y = vars->play->y;
		ray.x = vars->play->x;
	}
	if (angle > PI / 2 && angle < 3 * PI / 2)
	{
		ray.x = (int)(vars->play->x / 32) * 32 - 0.001;
		ray.y = vars->play->y + (ray.x - vars->play->x) * tan(angle);
		ray.x_off = -32;
		ray.y_off = ray.x_off * tan(angle);
	}
	if (angle < PI / 2 || angle > 3 * PI / 2)
	{
		ray.x = (int)(vars->play->x / 32) * 32 + 32;
		ray.y = vars->play->y + (ray.x - vars->play->x) * tan(angle);
		ray.x_off = 32;
		ray.y_off = ray.x_off * tan(angle);
	}
	ft_vertical_wall(vars, &ray);
}

void	ft_horizontal_wall(t_mlx *vars, t_ray *ray)
{
	ray->map_x = (int)(ray->x / 32);
	ray->map_y = (int)(ray->y / 32);
	while (ray->x >= 0 && ray->y >= 0 && ray->x <
			ft_strlen(vars->map[ray->map_y]) * 32 &&
			ray->y < ft_len(vars->map) * 32)
	{
		ray->map_x = (int)(ray->x / 32);
		ray->map_y = (int)(ray->y / 32);
		if (vars->map[ray->map_y][ray->map_x] == '1')
			break ;
		ray->x += ray->x_off;
		ray->y += ray->y_off;
	}
	ray->length = ft_direct_ray(vars->play->x, vars->play->y, ray->x, ray->y);
	vars->h_ray[0] = ray->length;
	vars->h_ray[1] = ray->x;
	vars->h_ray[2] = ray->y;
}

void	ft_horizontal(t_mlx *vars, float angle)
{
	t_ray	ray;

	if (angle == 0 || angle == PI)
	{
		ray.x = vars->play->x;
		ray.y = vars->play->y;
	}
	if (angle < PI)
	{
		ray.y = (int)(vars->play->y / 32) * 32 + 32;
		ray.x = vars->play->x + (ray.y - vars->play->y) / tan(angle);
		ray.y_off = 32;
		ray.x_off = ray.y_off / tan(angle);
	}
	if (angle > PI)
	{
		ray.y = (int)(vars->play->y / 32) * 32 - 0.001;
		ray.x = vars->play->x + (ray.y - vars->play->y) / tan(angle);
		ray.y_off = -32;
		ray.x_off = ray.y_off / tan(angle);
	}
	ft_horizontal_wall(vars, &ray);
}

void	ft_column(t_mlx *vars, float angle, int c)
{
	t_ray	ray;
	float	print[3];

	ray.ray = c;
	ray.angle = angle;
	ft_vertical(vars, angle);
	ray.v_len = vars->v_ray[0];
	ft_horizontal(vars, angle);
	ray.h_len = vars->h_ray[0];
	ray.length_param = ray.v_len > ray.h_len ? sqrtf(ray.h_len) :
				sqrtf(ray.v_len);
	vars->length[c] = ray.length_param;
	ray.length_param = ft_fish_cor(ray.length_param, vars->play->angle, angle);
	ray.wall_now = (32 * vars->p) / ray.length_param;
	ray.wall_he = ray.wall_now >= vars->base->y ?
					vars->base->y - 1 : ray.wall_now;
	ray.off = (vars->base->y - ray.wall_he) / 2;
	ft_paint_f_c(ray, vars);
	print[0] = ray.ray;
	print[1] = ray.off;
	print[2] = ray.wall_now;
	ft_paint_walls(ray, vars, print);
}
