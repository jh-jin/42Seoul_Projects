/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:50:08 by jjin              #+#    #+#             */
/*   Updated: 2022/11/02 16:12:19 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_img *img, void *mlx)
{	
	int		w;
	int		h;

	img->land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &w, &h);
	img->p = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &w, &h);
	img->c = mlx_xpm_file_to_image(mlx, "./images/collectable.xpm", &w, &h);
	img->e = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &w, &h);
}

void	init_game(t_game *game, t_img *img, t_location *location)
{
	game->location = location;
	game->location->h = 0;
	game->location->w = 0;
	game->img = img;
	game->h = 0;
	game->w = 0;
	game->steps = 0;
	game->p = 0;
	game->c = 0;
	game->e = 0;
}
