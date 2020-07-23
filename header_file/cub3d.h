/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:12:44 by tfarenga          #+#    #+#             */
/*   Updated: 2020/07/23 18:18:01 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define FD 1024
# define BUFFER_SIZE 1024
# define PI 3.1415926
# define MONITOR_WIDTH 4096
# define MONITOR_HEIGHT 2306
# define MIN_WNW 50
# define MAX_COL 255

typedef struct	s_base {
	void		*img;
	void		*mlx;
	void		*win;
	char 		*addr;
	void		*bmp;
	int			fd;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_base;

typedef struct	s_img {
	void		*img_a;
	char		*img_b;
	int			b;
	int			line;
	int			ed;
	int			height;
	int			width;
}				t_img;

typedef struct	s_play {
	float		x;
	float		y;
	float		px;
	float		py;
	long double	angle;
	float		sin;
	float		cos;
}				t_play;

typedef struct	s_sprite {
	int			x;
	int			y;
	int			s_x;
	int			s_y;
	float		dist;
	float		height;
	float		width;
	int			y_str;
	int			y_end;
	int			x_str;
	int			x_end;
	int			screen;
	float		x_pos;
	float		y_pos;
	float		angle;
	float		x_pxl;
	float		y_pxl;
	float		dist_conf;
	float		cos;
}				t_sprite;

typedef struct	s_ray {
	float		x;
	float		y;
	float		x_off;
	float		y_off;
	int			map_x;
	int			map_y;
	float		length;
	float		angle;
	float		v_len;
	float		h_len;
	float		length_param;
	float		wall_now;
	float		wall_he;
	float		off;
	int			ray;
}				t_ray;

typedef struct	s_mlx {
	t_img		**img;
	t_base		*base;
	t_play		*play;
	t_sprite	*sprite;
	char		**map;
	int			floor;
	float		p;
	float		*length;
	float		v_ray[3];
	int			*order_s;
	int			count_s;
	int			txt_index;
	int			ceilling;
	float		h_ray[3];
}				t_mlx;

typedef struct	s_txt {
	char		*west;
	char		*east;
	char		*north;
	char		*south;
	char		*str;
}				t_txt;

typedef struct s_param {
	int			res[3];
	int			floor[2];
	int			ceilling[2];
}				t_param;;


int			get_next_line(int fd, char **line);
int			ft_last_line(char **quantity_fd, int size, char **line, char **buffer);
int			ft_next_line(char **quantity_fd, int test_line, char **line, char **buffer);
int			ft_test_line(char *quantity_fd);
int			ft_dot(char *file);
t_txt    	*ft_init(void);
t_param 	*ft_init_param(void);

char		**ft_map(int fd);
char		**ft_real_arr(char *line, char **map);
int			ft_full_map(char **map);
int			ft_len_m(char **mass);
int			ft_pos(char **map);
int			ft_choice_mass(char *set, char **map);
int			ft_choice(char *str, char c);
int        	ft_conf(int fd, t_txt *txt, t_param *param);
int			ft_textur(char **list, t_txt *textur, char *flag);
int			ft_param(char **list, t_param *param, char *flag);
int			ft_resol(char **list, t_param *param, int len);
int			ft_floor(char **list, t_param *param, int len);
int			ft_ceilling(char **list, t_param *param, int len);
int			ft_number(char **list);
int			ft_create_colors(int green, int blue, int red);
int			ft_len(char **list);
int    		ft_free_conf(t_txt *txt, t_param *param, char *line, char **pars);
void		ft_free_txt(t_txt *texture);
void		ft_free(char **arr);
int			ft_error(char type);


int			ft_graphic(t_txt *txt, t_param *param, char **map, int scren);
t_mlx		*ft_init_go(t_txt *txt, t_param *param, char **map);

void		ft_free_base(t_mlx *mlx);
void		ft_free_img(t_mlx *mlx);
void		ft_free_img2(t_mlx *mlx);

void		ft_exit(t_txt *txt, t_param *param, char **map, char excode);
void		ft_game_end(t_mlx *mlx);
t_mlx		*ft_init_mlx(char **map, t_param par);
t_play		*ft_init_play(char **map);
t_base		*ft_init_base(t_param param);
t_sprite	*ft_init_sprit(t_mlx *mlx);
int			ft_init_txt(t_mlx *mlx, t_txt *txt);
t_img		*ft_init_txt_next(t_mlx *mlx, char *txt);


void		ft_count_sprite(t_mlx *mlx);
void		ft_select_spr(t_mlx *vars);
void		ft_select_spr_next(t_mlx *vars, float *str);

int			ft_coordinat(char **map, char *s, int *x, int *y);
void		ft_create_mlx(t_mlx *mlx);
int			ft_window(t_mlx *vars);
int			ft_end_window(void *p);
void		ft_move_r_l(t_mlx *vars, char line);
void		ft_rotate(t_mlx *vars, char line);
void		ft_move_d_u(t_mlx *vars, char line);
int			ft_key(int keycode, t_mlx *vars);
void		ft_vertical(t_mlx *vars, float angle);
void		ft_vertical_wall(t_mlx *var, t_ray *ray);
float		ft_direct_ray(int x_start, int y_start, float x_end, float y_end);
void		ft_horizontal(t_mlx *vars, float angle);
void		ft_horizontal_wall(t_mlx *var, t_ray *ray);
void		ft_paint_f_c(t_ray ray, t_mlx *vars);
void		ft_column_print(t_mlx *vars, float *param, int color);
void		ft_column(t_mlx *vars, float angle, int c);
void		ft_pixel_print(t_mlx *vars, int x_start, int y_start, int col);
void		ft_paint_walls(t_ray ray, t_mlx *vars, float *print);
void		ft_walls_print(t_mlx *var, float *print, float cot);
int			ft_color_txt(t_mlx *vars, int number, int x, int y);
void		ft_show_spr(t_mlx *mlx);
void		ft_sprite_form(t_mlx *mlx, t_sprite *spr, int i);
void		ft_print_spr(t_mlx *mlx, t_sprite spr, int y, int spr_n);
float		ft_fish_cor(float length, float play_angle, float ray_angle);
void		ft_line(t_mlx *vars);

int			ft_scren(t_mlx *mlx);
int			ft_bmp(int p_size, int fd, int height, int width);
void		ft_trans(unsigned char *str, int i);
int			ft_paint_screen(int p_size, int fd, t_mlx *mlx);
int			ft_col_screen(t_mlx *mlx, int x, int y);

#endif
