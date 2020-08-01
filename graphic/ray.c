/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:20:01 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 17:15:46 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

float	ft_direct_ray(int x_start, int y_start, float x_end, float y_end)
{
	float	k1;
	float	k2;
	float	length;

	k1 = (-x_start + x_end) * (-x_start + x_end);
	k2 = (-y_start + y_end) * (-y_start + y_end);
	length = k1 + k2;
	return (length);
}

float	ft_fish_cor(float length, float play_angle, float ray_angle)
{
	float	cor_angle;

	cor_angle = play_angle - ray_angle;
	if (cor_angle > 2 * PI)
		cor_angle -= 2 * PI;
	if (cor_angle < 0)
		cor_angle += 2 * PI;
	return (length * cos(cor_angle));
}
