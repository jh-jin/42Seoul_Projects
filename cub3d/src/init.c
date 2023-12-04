/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:37:50 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/12 20:39:20 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	data_init(t_data *data)
{
	data->no_cnt = 0;
	data->so_cnt = 0;
	data->we_cnt = 0;
	data->ea_cnt = 0;
	data->floor_cnt = 0;
	data->ceiling_cnt = 0;
}

void	init_ray(t_vec vec, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double)WINDOW_X - 1;
	ray->raydir_x = vec.dir_x + vec.pln_x * ray->cam_x;
	ray->raydir_y = vec.dir_y + vec.pln_y * ray->cam_x;
	ray->map_x = (int) vec.pos_x;
	ray->map_y = (int) vec.pos_y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}

void	init_temp(t_data *data)
{
	int	i;

	data->window.temp = malloc(sizeof(int *) * WINDOW_Y);
	if (!data->window.temp)
		print_err("Memory allocation failed");
	i = 0;
	while (i < WINDOW_Y)
	{
		data->window.temp[i] = malloc(sizeof(int) * WINDOW_X);
		if (!data->window.temp[i])
			print_err("Memory allocation failed");
		ft_memset(data->window.temp[i], 0, sizeof(int) * WINDOW_X);
		i++;
	}
}

void	init_texture(t_data *data)
{
	int	dir;

	data->window.path[0] = ft_strdup(data->ea);
	data->window.path[1] = ft_strdup(data->we);
	data->window.path[2] = ft_strdup(data->so);
	data->window.path[3] = ft_strdup(data->no);
	dir = -1;
	while (++dir < 4)
	{
		data->window.texture[dir] = malloc(sizeof(int) * TEX_SIZE * TEX_SIZE);
		if (!data->window.texture[dir])
			print_err("Memory allocation failed");
		ft_memset(data->window.texture[dir], 0, \
			sizeof(int) * TEX_SIZE * TEX_SIZE);
		save_image_as_xpm(data, data->window.path[dir], dir);
	}
}

void	init_cub3d(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_X, WINDOW_Y, "my_mlx");
	init_temp(data);
	init_texture(data);
	data->img.img_ptr = mlx_new_image(data->mlx, \
		WINDOW_X, WINDOW_Y);
	data->img.dt = (unsigned int *)mlx_get_data_addr(data->img.img_ptr, \
		&data->img.bpp, &data->img.size_l, &data->img.endian);
}
