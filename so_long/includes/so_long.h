/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:09:56 by jjin              #+#    #+#             */
/*   Updated: 2022/11/02 18:23:34 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 	1000
# define IMG_SIZE		64

# define BTN_X			17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void		*land;
	void		*wall;
	void		*p;
	void		*c;
	void		*e;
}	t_img;

typedef struct s_location {
	int			h;
	int			w;
}	t_location;

typedef struct s_game {
	t_img		*img;
	t_location	*location;
	void		*mlx;
	void		*win;
	char		**str;
	int			h;
	int			w;
	int			steps;
	int			p;
	int			c;
	int			e;
}	t_game;

enum e_tiles {
	LAND = '0',
	WALL = '1',
	PLAYER = 'P',
	COLLECTABLE = 'C',
	EXIT = 'E'
};

/* init.c */
void	init_img(t_img *img, void *mlx);
void	init_game(t_game *game, t_img *img, t_location *location);

/* map_io.c */
void	check_newline(char *line);
void	read_map(char *file, t_game *game);
void	render_map(t_game *game);
void	render_img(t_game *game, int w, int h);
void	print_steps(t_game *game);

/* map_check.c */
void	check_map(t_game *game);
void	check_map_size(t_game *game);
void	check_map_wall(t_game *game);
void	check_map_elements(t_game *game);
void	check_element_error(t_game *game);

/* hooks.c */
int		click_x(void);
void	print_n_exit(char *msg);
int		press_key(int key, t_game *game);
void	change_map(t_game *game, t_location *cur, t_location *next);

/* utils.c */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_putstr(char *str);
int		nb_len(long nb);
char	*ft_itoa(int n);

/* ft_split.c */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		word_count(char const *s, char c);
int		word_len(char const *s, char c);
char	**ft_split(char const *s, char c);

/* get_next_line_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

/* get_next_line.c */
char	*get_next_line(int fd);
int		gnl_find_newline(char *read_line);
char	*gnl_read_line(int fd);
char	*gnl_expand_backup(char *backup, int fd);
char	*gnl_cut_backup(char *backup, char *return_line);

#endif
