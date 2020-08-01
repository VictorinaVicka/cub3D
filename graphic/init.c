/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:30:24 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 18:34:45 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

t_base	*ft_init_base(t_param param)
{
	t_base	*base;

	if (!(base = malloc(sizeof(t_base))))
		return (NULL);
	base->x = param.res[1];
	base->y = param.res[2];
	return (base);
}

t_play	*ft_init_play(char **map)
{
	int			x;
	int			y;
	t_play		*play;

	if (!(play = malloc(sizeof(t_play))))
		return (NULL);
	if (ft_choice_mass(map, "SWNE\0") == 0)
	{
		ft_coordinat(map, "SWNE\0", &x, &y);
		play->x = x * 32 + 16;
		play->y = y * 32 + 16;
		if (map[y][x] == 'S')
			play->angle = PI / 2;
		else if (map[y][x] == 'E')
			play->angle = 0;
		else if (map[y][x] == 'W')
			play->angle = PI;
		else
			play->angle = 3 * PI / 2;
	}
	play->cos = cos(play->angle);
	play->sin = sin(play->angle);
	return (play);
}

t_mlx	*ft_init_mlx(char **map, t_param par)
{
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->map = map;
	mlx->floor = par.floor[1];
	mlx->ceilling = par.ceilling[1];
	return (mlx);
}

t_img	*ft_init_txt_next(t_mlx *mlx, char *txt)
{
	t_img		*img;

	if (!(img = malloc(sizeof(t_img))))
	{
		free(img);
		return (ft_error('b') ? NULL : NULL);
	}
	if (!(img->img_a = mlx_xpm_file_to_image(mlx->base->mlx,
		txt, &img->width, &img->height)))
	{
		free(img->img_a);
		free(img);
		return (ft_error('e') ? NULL : NULL);
	}
	img->img_b = mlx_get_data_addr(img->img_a,
						&img->b, &img->line, &img->ed);
	return (img);
}

int		ft_init_txt(t_mlx *mlx, t_txt *txt)
{
	int i;

	i = 0;
	mlx->img = malloc(sizeof(t_img *) * 5);
	while (i < 5)
		mlx->img[i++] = NULL;
	if ((mlx->img[0] = ft_init_txt_next(mlx, txt->north)) == NULL
		|| (mlx->img[1] = ft_init_txt_next(mlx, txt->south)) == NULL
		|| (mlx->img[2] = ft_init_txt_next(mlx, txt->west)) == NULL
		|| (mlx->img[3] = ft_init_txt_next(mlx, txt->east)) == NULL
		|| (mlx->img[4] = ft_init_txt_next(mlx, txt->spr)) == NULL)
	{
		i = 0;
		while (i < 5 && mlx->img[i] != NULL)
		{
			free(mlx->img[i]->img_a);
			free(mlx->img[i]->img_b);
			free(mlx->img[i++]);
		}
		free(mlx->img);
		return (0);
	}
	return (1);
}
