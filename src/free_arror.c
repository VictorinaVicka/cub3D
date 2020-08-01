/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:12:36 by tfarenga          #+#    #+#             */
/*   Updated: 2020/08/01 18:24:38 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int		ft_error(char type)
{
	if (type == 'a')
		ft_putstr_fd("File not found.\n", 1);
	if (type == 'b')
		ft_putstr_fd("Allocation problem!\n", 1);
	if (type == 'c')
		ft_putstr_fd("Incorrect file sequenc.\n", 1);
	if (type == 'd')
		ft_putstr_fd("Bad map format.\n", 1);
	if (type == 'e')
		ft_putstr_fd("Textures not found\n", 1);
	if (type == 'f')
		ft_putstr_fd("Unable to make a screenshot!\n", 1);
	if (type == 'g')
		ft_putstr_fd("Check the number of arguments\n", 1);
	return (0);
}

void	ft_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

void	ft_free_txt(t_txt *texture)
{
	free(texture->north);
	free(texture->south);
	free(texture->west);
	free(texture->east);
	free(texture->spr);
	free(texture);
}

int		ft_free_conf(char *line, char **pars, t_txt *txt, t_param *param)
{
	free(line);
	ft_free(pars);
	ft_free_txt(txt);
	free(param);
	return (-1);
}
