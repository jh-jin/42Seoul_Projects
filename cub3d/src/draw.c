/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:29:14 by jjin              #+#    #+#             */
/*   Updated: 2023/05/12 22:02:48 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	save_image_as_xpm(t_data *data, char *path, int dir)
{
	t_img	img;
	int		width;
	int		height;
	int		x;
	int		y;

	img.img_ptr = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (!img.img_ptr)
		print_err("Invalid path element");
	img.dt = (unsigned int *)mlx_get_data_addr(img.img_ptr, \
		&img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			data->window.texture[dir][width * y + x] = \
				img.dt[width * y + x];
		}
	}
	mlx_destroy_image(data->mlx, img.img_ptr);
}

void	draw_floor_ceiling(t_data *data)
{
	int	ceiling_rgb;
	int	floor_rgb;
	int	x;
	int	y;

	ceiling_rgb = (data->cei_red << 16) + (data->cei_green << 8) \
		+ (data->cei_blue);
	floor_rgb = (data->flo_red << 16) + (data->flo_green << 8) \
		+ (data->flo_blue);
	x = 0;
	while (x < WINDOW_X)
	{
		y = 0;
		while (y < WINDOW_Y / 2)
		{
			data->window.temp[y][x] = ceiling_rgb;
			data->window.temp[WINDOW_Y - y - 1][x] = floor_rgb;
			y++;
		}
		x++;
	}
}

void	draw_buffer_one(t_data *data, t_wall wall, t_ray *ray, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TEX_SIZE / wall.line_h;
	tex_pos = (wall.draw_start - WINDOW_Y / 2 + wall.line_h / 2) * step;
	i = wall.draw_start;
	while (i <= wall.draw_end)
	{
		tex_y = (int)tex_pos & (TEX_SIZE - 1);
		tex_pos += step;
		color = data->window.texture[ray->side][TEX_SIZE * tex_y + wall.tex_x];
		if (ray->side == WEST || ray->side == SOUTH)
			color = (color >> 1) & 8355711;
		data->window.temp[i][x] = color;
		i++;
	}
}

void	draw_window(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			data->img.dt[y * WINDOW_X + x] = data->window.temp[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img.img_ptr, 0, 0);
}

int	draw_cub3d(t_data *data)
{
	int		x;
	t_ray	ray;
	t_wall	wall;

	draw_floor_ceiling(data);
	x = 0;
	while (x < WINDOW_X)
	{
		get_ray_distance(data->vec, &ray, x);
		do_dda(data, &ray);
		get_draw_start_end_point(data->vec, &ray, &wall);
		draw_buffer_one(data, wall, &ray, x);
		x++;
	}
	draw_window(data);
	return (0);
}
