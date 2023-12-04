/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:07:54 by jjin              #+#    #+#             */
/*   Updated: 2022/11/02 18:21:53 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_newline(char *line)
{
	if (line[0] == '\n')
		print_n_exit("Error\n map contains invalid newline\n");
}

void	read_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*str;
	char	*tmp;

	str = NULL;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		print_n_exit("Error\n falied to open file\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		check_newline(line);
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
	}
	if (str == NULL)
		print_n_exit("Error\n empty map file\n");
	game->str = ft_split(str, '\n');
	free(str);
	check_map(game);
}

void	render_map(t_game *game)
{
	int		h;
	int		w;

	h = -1;
	while (++h < game->h)
	{
		w = -1;
		while (++w < game->w)
			render_img(game, w, h);
	}
}

void	render_img(t_game *game, int w, int h)
{
	mlx_put_image_to_window(
		game->mlx, game->win, game->img->land, w * IMG_SIZE, h * IMG_SIZE);
	if (game->str[h][w] == '1')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img->wall, w * IMG_SIZE, h * IMG_SIZE);
	else if (game->str[h][w] == 'P')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img->p, w * IMG_SIZE, h * IMG_SIZE);
	else if (game->str[h][w] == 'C')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img->c, w * IMG_SIZE, h * IMG_SIZE);
	else if (game->str[h][w] == 'E')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img->e, w * IMG_SIZE, h * IMG_SIZE);
}

void	print_n_exit(char *msg)
{
	ft_putstr(msg);
	exit(0);
}
