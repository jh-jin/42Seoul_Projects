/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:52:40 by jjin              #+#    #+#             */
/*   Updated: 2023/05/12 23:06:32 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floor_connecting_all(t_data *data)
{
	char	*temp;
	int		i;

	i = -1;
	free(data->floor_tmp);
	data->floor_tmp = ft_strdup("");
	i = -1;
	while (data->comma[++i])
	{
		temp = ft_strdup(data->floor_tmp);
		free(data->floor_tmp);
		data->floor_tmp = ft_strjoin(temp, data->comma[i]);
		free(temp);
		free(data->comma[i]);
	}
	free(data->comma);
}

void	put_floor_rgb(t_data *data)
{
	data->flo_red = ft_atoi(data->comma[0]);
	data->flo_green = ft_atoi(data->comma[1]);
	data->flo_blue = ft_atoi(data->comma[2]);
}

void	floor_for_25(t_data *data)
{
	data->floor_cnt++;
	data->floor = ft_strdup(data->floor_tmp);
	free(data->floor_tmp);
}

void	check_floor(t_data *data, char *tmp)
{
	int		i;
	char	*temp;

	i = -1;
	data->comma_cnt = 0;
	if (!tmp[1] || tmp[1] != ' ')
		print_err("Argument Error");
	data->floor_tmp = ft_substr(tmp, 2, ft_strlen(tmp));
	temp = ft_strdup(data->floor_tmp);
	free(data->floor_tmp);
	data->floor_tmp = ft_strtrim(temp, data->isspace);
	free(temp);
	data->comma = ft_split(data->floor_tmp, ',');
	remove_space(data);
	if (data->comma_cnt != 3)
		print_err("Argument Error");
	put_floor_rgb(data);
	add_comma(data);
	floor_connecting_all(data);
	i = -1;
	while (data->floor_tmp[++i])
		if (ft_isdigit(data->floor_tmp[i]) == 0 && data->floor_tmp[i] != ',')
			print_err("Argument Error");
	floor_for_25(data);
}
