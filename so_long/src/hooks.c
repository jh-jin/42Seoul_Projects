/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:53:04 by jjin              #+#    #+#             */
/*   Updated: 2022/11/02 18:22:36 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	click_x(void)
{
	print_n_exit("GG: See you next time!\n");
	return (0);
}

void	print_steps(t_game *game)
{
	char	*steps;

	ft_putstr("steps : ");
	game->steps++;
	steps = ft_itoa(game->steps);
	ft_putstr(steps);
	ft_putstr("\n");
	free(steps);
}

int	press_key(int key, t_game *game)
{
	t_location	cur;
	t_location	next;

	cur = *(game->location);
	next = cur;
	if (key == KEY_D)
		next.w++;
	else if (key == KEY_S)
		next.h++;
	else if (key == KEY_A)
		next.w--;
	else if (key == KEY_W)
		next.h--;
	else if (key == KEY_ESC)
		print_n_exit("GG: See you next time!\n");
	else
		return (0);
	change_map(game, &cur, &next);
	return (0);
}

void	change_map(t_game *game, t_location *cur, t_location *next)
{
	char	*c;
	char	*n;

	c = &(game->str[cur->h][cur->w]);
	n = &(game->str[next->h][next->w]);
	if (*n != '1' && *n != 'E')
	{
		if (*n == 'C')
			game->c--;
		*c = '0';
		*n = 'P';
		render_map(game);
		print_steps(game);
		game->location->h = next->h;
		game->location->w = next->w;
	}
	if (*n == 'E' && game->c == 0)
	{
		print_steps(game);
		print_n_exit("Game Clear!\n");
	}
}
