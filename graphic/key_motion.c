/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_motion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:07:49 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 18:37:29 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

void	ft_rotate(t_mlx *vars, char line)
{
	if (line == 'l')
	{
		vars->play->angle -= 0.1;
		if (vars->play->angle < 0)
			vars->play->angle += 2 * PI;
	}
	else
	{
		vars->play->angle += 0.1;
		if (vars->play->angle > 2 * PI)
			vars->play->angle -= 2 * PI;
	}
}

void	ft_move_r_l(t_mlx *vars, char line)
{
	vars->play->px = -vars->play->sin * 5;
	vars->play->py = vars->play->cos * 5;
	if (line == 'r')
	{
		if (vars->map[(int)(vars->play->y + vars->play->py) / 32]
			[(int)(vars->play->x + vars->play->px) / 32] != '1')
		{
			vars->play->x += vars->play->px;
			vars->play->y += vars->play->py;
		}
	}
	else
	{
		if (vars->map[(int)(vars->play->y - vars->play->py) / 32]
			[(int)(vars->play->x - vars->play->px) / 32] != '1')
		{
			vars->play->x -= vars->play->px;
			vars->play->y -= vars->play->py;
		}
	}
}

void	ft_move_d_u(t_mlx *vars, char line)
{
	vars->play->px = vars->play->cos * 5;
	vars->play->py = vars->play->sin * 5;
	if (line == 'u')
	{
		if (vars->map[(int)(vars->play->y + vars->play->py) / 32]
			[(int)(vars->play->x + vars->play->px) / 32] != '1')
		{
			vars->play->x += vars->play->px;
			vars->play->y += vars->play->py;
		}
	}
	else
	{
		if (vars->map[(int)(vars->play->y - vars->play->py) / 32]
			[(int)(vars->play->x - vars->play->px) / 32] != '1')
		{
			vars->play->x -= vars->play->px;
			vars->play->y -= vars->play->py;
		}
	}
}

void	ft_line(t_mlx *vars)
{
	float			angle_line;
	int				i;

	i = 0;
	vars->play->cos = cos(vars->play->angle);
	vars->play->sin = sin(vars->play->angle);
	angle_line = vars->play->angle - PI / 6;
	angle_line = (angle_line < 0 ? angle_line + 2 * PI : angle_line);
	angle_line = (angle_line > 2 * PI ? angle_line - 2 * PI : angle_line);
	vars->p = vars->base->x / 2 / tan(PI / 6);
	vars->length = malloc(sizeof(float) * vars->base->x);
	while (i < vars->base->x)
	{
		ft_column(vars, angle_line, i++);
		angle_line += PI / 3 / vars->base->x;
		angle_line = (angle_line < 0 ? angle_line + 2 * PI : angle_line);
		angle_line = (angle_line > 2 * PI ? angle_line - 2 * PI : angle_line);
	}
	ft_select_spr(vars);
	ft_show_spr(vars);
	free(vars->length);
	free(vars->order_s);
	mlx_put_image_to_window(vars->base->mlx, vars->base->win,
							vars->base->img, 0, 0);
}

int		ft_key(int keycode, t_mlx *vars)
{
	if (keycode == 53)
		ft_game_end(vars);
	if (keycode == 123)
		ft_rotate(vars, 'l');
	if (keycode == 124)
		ft_rotate(vars, 'r');
	if (keycode == 0)
		ft_move_r_l(vars, 'l');
	if (keycode == 1)
		ft_move_d_u(vars, 'd');
	if (keycode == 2)
		ft_move_r_l(vars, 'r');
	if (keycode == 13)
		ft_move_d_u(vars, 'u');
	ft_line(vars);
	return (1);
}
