/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:09:44 by jjin              #+#    #+#             */
/*   Updated: 2022/11/02 17:39:43 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_img		img;
	t_game		game;
	t_location	location;

	if (argc != 2 || ft_strlen(argv[1]) < 4)
		print_n_exit("Error\n invalid argument\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		print_n_exit("Error\n invalid map file extention\n");
	game.mlx = mlx_init();
	init_img(&img, game.mlx);
	init_game(&game, &img, &location);
	read_map(argv[1], &game);
	game.win = mlx_new_window(
			game.mlx, game.w * IMG_SIZE, game.h * IMG_SIZE, "jjin");
	render_map(&game);
	mlx_key_hook(game.win, &press_key, &game);
	mlx_hook(game.win, BTN_X, 0, &click_x, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	return (0);
}
