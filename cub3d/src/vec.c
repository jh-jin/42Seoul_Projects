/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:27:52 by jjin              #+#    #+#             */
/*   Updated: 2023/05/12 21:42:56 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_ray_distance(t_vec vec, t_ray *ray, int x)
{
	init_ray(vec, ray, x);
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (vec.pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - vec.pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (vec.pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - vec.pos_y) * ray->deltadist_y;
	}
}

void	do_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = EAST;
			else
				ray->side = WEST;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = SOUTH;
			else
				ray->side = NORTH;
		}
		if (data->map_arr[ray->map_y][ray->map_x] == WALL)
			ray->hit = 1;
	}
}

double	get_wall_x(t_vec vec, t_ray *ray)
{
	double	perp_wall_dist;

	if (ray->side == EAST || ray->side == WEST)
		perp_wall_dist = (ray->map_x - vec.pos_x + \
			(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		perp_wall_dist = (ray->map_y - vec.pos_y + \
			(1 - ray->step_y) / 2) / ray->raydir_y;
	ray->perp_wall_dist = perp_wall_dist;
	if (ray->side == EAST || ray->side == WEST)
		return (vec.pos_y + ray->perp_wall_dist * ray->raydir_y);
	else
		return (vec.pos_x + ray->perp_wall_dist * ray->raydir_x);
}

void	get_draw_start_end_point(t_vec vec, t_ray *ray, t_wall *wall)
{
	double	wall_x;

	wall_x = get_wall_x(vec, ray);
	wall_x -= floor(wall_x);
	wall->line_h = (WINDOW_Y / ray->perp_wall_dist);
	wall->side = ray->side;
	wall->tex_x = (int)(wall_x * (double)TEX_SIZE);
	if (ray->side == SOUTH)
		wall->tex_x = TEX_SIZE - wall->tex_x - 1;
	wall->draw_start = -wall->line_h / 2 + WINDOW_Y / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_h / 2 + WINDOW_Y / 2;
	if (wall->draw_end >= WINDOW_Y)
		wall->draw_end = WINDOW_Y - 1;
}
