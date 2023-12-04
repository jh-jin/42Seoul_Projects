/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:34:04 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/12 23:07:14 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	first_line_check(t_data *data, int x, int y)
{
	while (ft_isspace(data->map_arr[y][x]) == 1)
		x++;
	while (data->map_arr[y][x] != '\0')
	{
		if (data->map_arr[y][x] != '1' && data->map_arr[y][x] != ' ')
			print_err("Map is not walled");
		x++;
	}
	y = 1;
}

void	last_line_check(t_data *data, int x, int y)
{
	x = 0;
	while (ft_isspace(data->map_arr[y][x]) == 1)
		x++;
	while (data->map_arr[y][x] != '\0')
	{
		if (data->map_arr[y][x] != '1' && data->map_arr[y][x] != ' ')
			print_err("Map is not walled");
		x++;
	}
}

void	coord_check(t_data *data, int x, int y)
{
	if (x - 1 >= 0 && data->map_arr[y][x - 1] == ' ')
		print_err("Map is not walled");
	if ((data->map_arr[y][x + 1] == ' ' || data->map_arr[y][x + 1] == '\0'))
		print_err("Map is not walled");
	if (y - 1 >= 0 && \
		(data->map_arr[y - 1][x] == ' ' || data->map_arr[y - 1][x] == '\0'))
		print_err("Map is not walled");
	if (data->map_arr[y + 1][x] && \
		(data->map_arr[y + 1][x] == ' ' || data->map_arr[y + 1][x] == '\0'))
		print_err("Map is not walled");
}

void	char_valid(t_data *data, int x, int y)
{
	if (data->map_arr[y][x] == 'N' || data->map_arr[y][x] == 'S')
	{
		coord_side_set(data, x, y);
		data->vec.dir_x = 0;
		data->vec.pln_y = 0;
		data->map_arr[y][x] = '0';
		if (data->map_arr[y][x] == 'N')
			data->vec.dir_y *= -1;
		else
			data->vec.pln_x *= -1;
	}
	if (data->map_arr[y][x] == 'E' || data->map_arr[y][x] == 'W')
	{
		coord_side_set(data, x, y);
		data->vec.dir_y = 0;
		data->vec.pln_x = 0;
		data->map_arr[y][x] = '0';
		if (data->map_arr[y][x] == 'W')
		{
			data->vec.dir_x *= -1;
			data->vec.pln_y *= -1;
		}
	}
	if (x == 0 && data->map_arr[y][x] != '1')
		print_err("Map is not walled7");
}

void	map_valid_test(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->vec.man_cnt = 0;
	first_line_check(data, x, y);
	while (++y < data->box_height - 1)
	{
		x = 0;
		while (ft_isspace(data->map_arr[y][x]) == 1)
			x++;
		while (data->map_arr[y][x] != '\0')
		{
			char_valid(data, x, y);
			if (data->map_arr[y][x] != '1' && data->map_arr[y][x] != ' ')
				coord_check(data, x, y);
			x++;
		}
	}
	if (data->vec.man_cnt != 1)
		print_err("too low or many character");
	last_line_check(data, x, y);
}
