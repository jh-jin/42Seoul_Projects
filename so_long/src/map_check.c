/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:52:39 by jjin              #+#    #+#             */
/*   Updated: 2022/11/02 17:39:43 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_game *game)
{
	check_map_size(game);
	check_map_wall(game);
	check_map_elements(game);
}

void	check_map_size(t_game *game)
{
	int		i;

	i = -1;
	game->w = ft_strlen(game->str[0]);
	while (game->str[++i])
	{
		if ((int)ft_strlen(game->str[i]) != game->w)
			print_n_exit("Error\n map must be a rectangular\n");
	}
	game->h = i;
	if (game->w > 128 || game->h > 128)
		print_n_exit("Error\n map too large.\n");
}

void	check_map_wall(t_game *game)
{
	int		h;
	int		w;

	h = -1;
	while (++h < game->h)
	{
		w = -1;
		while (++w < game->w)
		{
			if (h == 0 || h == game->h - 1)
			{
				if (game->str[h][w] != WALL)
					print_n_exit("Error\n map must be enclosed by walls\n");
			}
			else if (w == 0 || w == game->w - 1)
			{
				if (game->str[h][w] != WALL)
					print_n_exit("Error\n map must be enclosed by walls\n");
			}
		}
	}
}

void	check_map_elements(t_game *game)
{
	int		h;
	int		w;

	h = -1;
	while (++h < game->h)
	{
		w = -1;
		while (++w < game->w)
		{
			if (ft_strchr("01PCE", game->str[h][w]) == NULL)
				print_n_exit("Error\n invalid character in map\n");
			else if (game->str[h][w] == 'P')
			{
				game->p++;
				game->location->h = h;
				game->location->w = w;
			}
			else if (game->str[h][w] == 'C')
				game->c++;
			else if (game->str[h][w] == 'E')
				game->e++;
		}
	}
	check_element_error(game);
}

void	check_element_error(t_game *game)
{
	if (game->p == 0)
		print_n_exit("Error\n no player in map\n");
	if (game->p > 1)
		print_n_exit("Error\n too many player in map\n");
	if (game->c == 0)
		print_n_exit("Error\n no collection in map\n");
	if (game->e == 0)
		print_n_exit("Error\n no exit in map\n");
	if (game->e > 1)
		print_n_exit("Error\n too many exit in map\n");
}
