/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:35:52 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 13:47:39 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/cub3d.h"

int	ft_test_line(char *quantity_fd)
{
	int	index;

	index = 0;
	while (quantity_fd[index] != '\0')
	{
		if (quantity_fd[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int	ft_next_line(char **quantity_fd, int test_line, char **line, char **buffer)
{
	char	*next;

	(*quantity_fd)[test_line] = '\0';
	*line = ft_strdup(*quantity_fd);
	next = ft_strdup(*quantity_fd + test_line + 1);
	free(*quantity_fd);
	free(*buffer);
	*quantity_fd = next;
	return (1);
}

int	ft_last_line(char **quantity_fd, int size, char **line, char **buffer)
{
	int	test_line;

	test_line = 0;
	if (size < 0)
		return (-1);
	if (*quantity_fd && (test_line = ft_test_line(*quantity_fd)) >= 0)
		return (ft_next_line(quantity_fd, test_line, line, buffer));
	if (*quantity_fd)
	{
		*line = *quantity_fd;
		*quantity_fd = 0;
		free(*buffer);
		return (0);
	}
	*line = ft_strdup("");
	free(*quantity_fd);
	free(*buffer);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*quantity_fd[FD];
	char		*buffer;
	int			read_files;
	int			test_line;

	if ((line == 0) || (fd < 0) || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_files = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_files] = '\0';
		if (quantity_fd[fd] == NULL)
			quantity_fd[fd] = ft_strdup("");
		quantity_fd[fd] = ft_strjoin(quantity_fd[fd], buffer);
		if ((test_line = ft_test_line(quantity_fd[fd])) >= 0)
			return (ft_next_line(&quantity_fd[fd], test_line, line, &buffer));
	}
	return (ft_last_line(&quantity_fd[fd], read_files, line, &buffer));
}
