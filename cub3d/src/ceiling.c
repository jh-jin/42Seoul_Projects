/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:16:46 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/12 23:07:19 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ceiling_connecting_all(t_data *data)
{
	char	*temp;
	int		i;

	i = -1;
	free(data->ceiling_tmp);
	data->ceiling_tmp = ft_strdup("");
	i = -1;
	while (data->comma[++i])
	{
		temp = ft_strdup(data->ceiling_tmp);
		free(data->ceiling_tmp);
		data->ceiling_tmp = ft_strjoin(temp, data->comma[i]);
		free(temp);
		free(data->comma[i]);
	}
	free(data->comma);
}

void	put_ceiling_rgb(t_data *data)
{
	data->cei_red = ft_atoi(data->comma[0]);
	data->cei_green = ft_atoi(data->comma[1]);
	data->cei_blue = ft_atoi(data->comma[2]);
}

void	ceiling_for_25(t_data *data)
{
	data->ceiling_cnt++;
	data->ceiling = ft_strdup(data->ceiling_tmp);
	free(data->ceiling_tmp);
}

void	check_ceiling(t_data *data, char *tmp)
{
	int		i;
	char	*temp;

	data->comma_cnt = 0;
	if (!tmp[1] || tmp[1] != ' ')
		print_err("Argument Error");
	data->ceiling_tmp = ft_substr(tmp, 2, ft_strlen(tmp));
	temp = ft_strdup(data->ceiling_tmp);
	free(data->ceiling_tmp);
	data->ceiling_tmp = ft_strtrim(temp, data->isspace);
	free(temp);
	data->comma = ft_split(data->ceiling_tmp, ',');
	remove_space(data);
	if (data->comma_cnt != 3)
		print_err("Argument Error");
	put_ceiling_rgb(data);
	add_comma(data);
	ceiling_connecting_all(data);
	i = -1;
	while (data->ceiling_tmp[++i])
		if (ft_isdigit(data->ceiling_tmp[i]) == 0 && \
		data->ceiling_tmp[i] != ',')
			print_err("Argument Error");
	ceiling_for_25(data);
}
