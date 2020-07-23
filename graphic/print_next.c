/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:34:22 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/22 17:38:17 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int		ft_color_txt(t_mlx *vars, int number, int x, int y)
{
	char	*str;

	y = y < 0 ? 0 : y;
	str = vars->img[number]->img_a + (y * vars->img[number]->line
										+ x * (vars->img[number]->b / 8));
	return (*(unsigned int *)str);
}
