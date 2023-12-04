/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:37:42 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/12 23:06:30 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_loop(int i1, t_data *data, char *line, char *temp)
{
	while (line)
	{
		free(line);
		line = get_next_line(i1);
		if (line == NULL)
			break ;
		temp = data->map;
		if (line != NULL)
			data->map = ft_strjoin(temp, line);
		free(temp);
	}
	free(line);
}

char	**map_read(char *filename, t_data *data, char *line, char *temp)
{
	char	**ber;
	int		i[2];

	i[1] = open(filename, O_RDONLY);
	line = get_next_line(i[1]);
	if (!line)
		print_err("Argument Error");
	data->map = ft_strdup(line);
	read_loop(i[1], data, line, temp);
	close(i[1]);
	i[1] = 0;
	i[0] = 0;
	while (data->map[i[0]])
	{
		if (data->map[i[0]] == '1')
			i[1] = 1;
		if (i[1] == 1 && data->map[i[0]] == '\n' && data->map[i[0] + 1] == '\n')
			print_err("Argument Error");
		i[0]++;
	}
	ber = ft_split(data->map, '\n');
	return (ber);
}

void	check_count(t_data *data, char *tmp)
{
	if (tmp[0] == '\0')
		return ;
	if (data->no_cnt != 1)
		print_err("Argument Error");
	if (data->so_cnt != 1)
		print_err("Argument Error");
	if (data->we_cnt != 1)
		print_err("Argument Error");
	if (data->ea_cnt != 1)
		print_err("Argument Error");
	if (data->floor_cnt != 1)
		print_err("Argument Error");
	if (data->ceiling_cnt != 1)
		print_err("Argument Error");
}

void	map_check(t_data *data)
{
	int		i;
	char	*tmp;

	i = -1;
	data_init(data);
	while (data->whole_arr[++i])
	{
		tmp = ft_strtrim(data->whole_arr[i], data->isspace);
		if (tmp[0] == 'N')
			check_north(data, tmp);
		else if (tmp[0] == 'S')
			check_south(data, tmp);
		else if (tmp[0] == 'W')
			check_west(data, tmp);
		else if (tmp[0] == 'E')
			check_east(data, tmp);
		else if (tmp[0] == 'F')
			check_floor(data, tmp);
		else if (tmp[0] == 'C')
			check_ceiling(data, tmp);
		else
			check_count(data, tmp);
		free(tmp);
	}
}

void	devide_map(t_data *data)
{
	int	i;
	int	j;

	map_check(data);
	i = 5;
	j = 0;
	data->box_height = 0;
	while (data->whole_arr[++i])
	{
		data->box_height++;
		j++;
	}
	data->map_arr = malloc(sizeof(char *) * (j + 1));
	if (!data->map_arr)
		print_err("Memory allocation failed");
	i = 5;
	j = -1;
	while (data->whole_arr[++i])
		data->map_arr[++j] = ft_strdup(data->whole_arr[i]);
	data->map_arr[++j] = NULL;
	i = -1;
	while (data->whole_arr[++i])
		free(data->whole_arr[i]);
	free(data->whole_arr);
}
