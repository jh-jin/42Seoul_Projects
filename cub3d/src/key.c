/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:26:31 by jjin              #+#    #+#             */
/*   Updated: 2023/05/12 21:47:13 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	on_key_press(int keycode, t_data *data)
{
	if (keycode == W)
		move_ap_dui(data, 1);
	if (keycode == S)
		move_ap_dui(data, -1);
	if (keycode == A)
		move_left_right(data, -1);
	if (keycode == D)
		move_left_right(data, 1);
	if (keycode == LEFT)
		change_direction(data, -1);
	if (keycode == RIGHT)
		change_direction(data, 1);
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	on_x_btn_click(void)
{
	exit(0);
	return (0);
}

void	run_cub3d(t_data *data)
{
	mlx_loop_hook(data->mlx, &draw_cub3d, data);
	mlx_hook(data->win, KEY_PRESS, 0, on_key_press, data);
	mlx_hook(data->win, KEY_EXIT, 0, on_x_btn_click, NULL);
	mlx_loop(data->mlx);
}
