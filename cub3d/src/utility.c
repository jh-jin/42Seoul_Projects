/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:12:44 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/12 23:08:34 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_value_check(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_arr[++i])
	{
		j = -1;
		while (data->map_arr[i][++j])
		{
			if (data->map_arr[i][j] == '1' || data->map_arr[i][j] == '0' \
				|| data->map_arr[i][j] == 'N' || data->map_arr[i][j] == 'S' \
				|| data->map_arr[i][j] == 'E' || data->map_arr[i][j] == 'W' \
				|| ft_isspace(data->map_arr[i][j]) == 1)
				continue ;
			else
				print_err("Argument Error");
		}
	}
}

void	isspace_char(t_data *data)
{
	data->tile_size = 32;
	data->isspace = malloc(sizeof(char) * 7);
	if (!data->isspace)
		print_err("Memory allocation failed");
	data->isspace[0] = 9;
	data->isspace[1] = 10;
	data->isspace[2] = 11;
	data->isspace[3] = 12;
	data->isspace[4] = 13;
	data->isspace[5] = 32;
	data->isspace[6] = '\0';
}

void	print_err(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(1);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
