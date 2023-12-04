/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:06:48 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/12 22:36:34 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define WINDOW_X 1920
# define WINDOW_Y 1080
# define TEX_SIZE 32
# define MOVE_SPEED 1
# define EAST 0
# define WEST 1
# define SOUTH 2
# define NORTH 3
# define WALL 49

# define KEY_PRESS 2
# define KEY_EXIT 17

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define X 17

typedef struct s_vec{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	pln_x;
	double	pln_y;
	int		man_cnt;
}	t_vec;

typedef struct s_ray {
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_wall {
	int	side;
	int	tex_x;
	int	line_h;
	int	draw_start;
	int	draw_end;
}	t_wall;

typedef struct s_win{
	int		**temp;
	int		*texture[4];
	char	*path[4];
}	t_win;

typedef struct s_img{
	void			*img_ptr;
	int				bpp;
	int				size_l;
	int				endian;
	unsigned int	*dt;
}	t_img;

typedef struct s_data{
	char	*isspace;
	char	**whole_arr;
	char	**map_arr;
	char	*no;
	int		no_cnt;
	char	*so;
	int		so_cnt;
	char	*ea;
	int		ea_cnt;
	char	*we;
	int		we_cnt;
	char	*floor;
	int		flo_red;
	int		flo_green;
	int		flo_blue;
	int		floor_cnt;
	char	*floor_tmp;
	char	**comma;
	int		comma_cnt;
	char	*ceiling;
	int		cei_red;
	int		cei_green;
	int		cei_blue;
	char	*ceiling_tmp;
	int		ceiling_cnt;
	void	*mlx;
	void	*win;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	char	*map;
	int		tile_size;
	int		box_height;
	int		box_width;
	int		img_height;
	int		img_width;
	t_vec	vec;
	t_win	window;
	t_img	img;
}	t_data;

// check_news.c
void	check_north(t_data *data, char *tmp);
void	check_south(t_data *data, char *tmp);
void	check_west(t_data *data, char *tmp);
void	check_east(t_data *data, char *tmp);

// draw.c
void	save_image_as_xpm(t_data *data, char *path, int dir);
void	draw_floor_ceiling(t_data *data);
void	draw_buffer_one(t_data *data, t_wall wall, t_ray *ray, int x);
void	draw_window(t_data *data);
int		draw_cub3d(t_data *data);

// ceiling.c
void	ceiling_connecting_all(t_data *data);
void	put_ceiling_rgb(t_data *data);
void	ceiling_for_25(t_data *data);
void	check_ceiling(t_data *data, char *tmp);

// floor.c
void	floor_connecting_all(t_data *data);
void	put_floor_rgb(t_data *data);
void	floor_for_25(t_data *data);
void	check_floor(t_data *data, char *tmp);

// get_next_line.c
char	*make_backup(char *line);
char	*make_line(int fd, char *backup, char *buf);
char	*get_next_line(int fd);

// init.c
void	data_init(t_data *data);
void	init_ray(t_vec vec, t_ray *ray, int x);
void	init_temp(t_data *data);
void	init_texture(t_data *data);
void	init_cub3d(t_data *data);

// key.c
int		on_key_press(int keycode, t_data *data);
int		on_x_btn_click(void);
void	run_cub3d(t_data *data);

// move.c
void	move_ap_dui(t_data *data, double direction);
void	move_left_right(t_data *data, double direction);
void	change_direction(t_data *data, double direction);

// parsing.c
void	read_loop(int i1, t_data *data, char *line, char *temp);
char	**map_read(char *filename, t_data *data, char *line, char *temp);
void	check_count(t_data *data, char *tmp);
void	map_check(t_data *data);
void	devide_map(t_data *data);

// utility.c
void	map_value_check(t_data *data);
void	isspace_char(t_data *data);
void	print_err(char *str);
int		ft_isspace(char c);

// utility2.c
void	coord_side_set(t_data *data, int x, int y);
void	remove_space(t_data *data);
void	add_comma(t_data *data);

// valid_map.c
void	first_line_check(t_data *data, int x, int y);
void	last_line_check(t_data *data, int x, int y);
void	coord_check(t_data *data, int x, int y);
void	char_valid(t_data *data, int x, int y);
void	map_valid_test(t_data *data);

// vec.c
void	get_ray_distance(t_vec vec, t_ray *ray, int x);
void	do_dda(t_data *data, t_ray *ray);
double	get_wall_x(t_vec vec, t_ray *ray);
void	get_draw_start_end_point(t_vec vec, t_ray *ray, t_wall *wall);

#endif