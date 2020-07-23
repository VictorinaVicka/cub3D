# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 11:15:37 by tfarenga          #+#    #+#              #
#    Updated: 2020/07/21 14:48:43 by tfarenga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CLANG = gcc

FLAG = -Wall -Wextra -Werror

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = main.c

OBJ = $(srcs:.c=.o)

HEADER = header_file/cub3d.h

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(MAKE) -C libft
			$(MAKE) -C minilibx
			$(CLANG) $(FLAG) -o $(NAME) $(OBJ) -I $(HEADER) -L libft -lft -L minilibx -lmlx $(FRAMEWORKS)

%.o : %.c
			$(CLANG) $(FLAG) -I. -c $< -o $(<:.c=.o)

clean:
			$(MAKE) clean -C libft
			rm -rf $(OBJ)

fclean: clean
			rm -rf $(NAME)
			rm -rf screnshot.bmp
			$(MAKE) fclean -C libft
			$(MAKE) clean -C minilibx

re: fclean all

