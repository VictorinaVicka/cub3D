# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 11:15:37 by tfarenga          #+#    #+#              #
#    Updated: 2020/07/23 16:38:18 by tfarenga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CLANG = clang

FLAG = -Wall -Wextra -Werror

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = main.c src/choice.c src/start_map.c src/parametr.c src/init_color_dot.c \
src/get_next_line.c src/texture.c src/free_arror.c graphic/sprite_form.c \
graphic/sprite.c graphic/ray.c graphic/print_next.c graphic/paint.c graphic/map.c \
graphic/key_motion.c graphic/init.c graphic/graphic.c graphic/exit_free.c \
graphic/exit.c graphic/coordinates.c graphic/scren.c

OBJ = $(SRC:.c=.o)

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
			rm -rf screen.bmp
			$(MAKE) fclean -C libft
			$(MAKE) clean -C minilibx

re: fclean all

