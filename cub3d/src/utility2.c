/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:54:06 by jjin              #+#    #+#             */
/*   Updated: 2023/05/12 22:28:26 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	coord_side_set(t_data *data, int x, int y)
{
	data->vec.man_cnt += 1;
	data->vec.pos_y = (float)y + 0.5;
	data->vec.pos_x = (float)x + 0.5;
	data->vec.dir_x = 1;
	data->vec.dir_y = 1;
	data->vec.pln_x = 0.66;
	data->vec.pln_y = 0.66;
}

void	remove_space(t_data *data)
{
	char	*temp;
	int		i;

	i = -1;
	while (data->comma[++i])
	{
		temp = ft_strtrim(data->comma[i], data->isspace);
		free(data->comma[i]);
		data->comma[i] = ft_strdup(temp);
		free(temp);
		data->comma_cnt++;
	}
}

void	add_comma(t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	while (i != 2)
	{
		temp = ft_strdup(data->comma[i]);
		free(data->comma[i]);
		data->comma[i] = ft_strjoin(temp, ",");
		free(temp);
		i++;
	}
}
