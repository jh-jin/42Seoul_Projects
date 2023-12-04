/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:31:19 by jjin              #+#    #+#             */
/*   Updated: 2023/05/12 21:58:26 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_ap_dui(t_data *data, double dir)
{
	t_vec	vec;
	double	target_x;
	double	target_y;

	vec = data->vec;
	printf("%f\n", vec.pos_x);
	target_x = vec.pos_x + (vec.dir_x * (double)MOVE_SPEED / (double)10 * dir);
	target_y = vec.pos_y + (vec.dir_y * (double)MOVE_SPEED / (double)10 * dir);
	printf("%f\n", target_x);
	printf("%d\n", (int)vec.pos_y);
	printf("%d\n", (int)target_x);
	printf("%d\n", (int)target_y);
	printf("%d\n", (int)vec.pos_x);
	printf("\n");
	if (data->map_arr[(int)vec.pos_y][(int)target_x] == '0')
		data->vec.pos_x = target_x;
	if (data->map_arr[(int)target_y][(int)vec.pos_x] == '0')
		data->vec.pos_y = target_y;
}

void	move_left_right(t_data *data, double dir)
{
	t_vec	vec;
	double	target_x;
	double	target_y;

	vec = data->vec;
	target_x = vec.pos_x + (vec.pln_x * (double)MOVE_SPEED / 10 * dir);
	target_y = vec.pos_y + (vec.pln_y * (double)MOVE_SPEED / 10 * dir);
	if (data->map_arr[(int)vec.pos_y][(int)target_x] == '0')
		data->vec.pos_x = target_x;
	if (data->map_arr[(int)target_y][(int)vec.pos_x] == '0')
		data->vec.pos_y = target_y;
}

void	change_direction(t_data *data, double dir)
{
	double	dir_x;
	double	pln_x;
	double	angle;

	dir_x = data->vec.dir_x;
	pln_x = data->vec.pln_x;
	angle = (double)1 / 10 * dir;
	data->vec.dir_x = (dir_x * cos(angle)) - (data->vec.dir_y * sin(angle));
	data->vec.dir_y = (dir_x * sin(angle)) + (data->vec.dir_y * cos(angle));
	data->vec.pln_x = (pln_x * cos(angle)) - (data->vec.pln_y * sin(angle));
	data->vec.pln_y = (pln_x * sin(angle)) + (data->vec.pln_y * cos(angle));
}
