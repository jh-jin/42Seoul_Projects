/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:16:24 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/12 23:06:31 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	char	*file_name;
	int		fd;

	if (ac != 2)
		print_err("Argument Error");
	file_name = ft_substr(av[1], ft_strlen(av[1]) - 4, ft_strlen(av[1]));
	if (ft_strncmp(file_name, ".cub", ft_strlen(file_name)) != 0)
		print_err("Extension error");
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		print_err("File open fail.");
	isspace_char(&data);
	data.whole_arr = map_read(av[1], &data, NULL, NULL);
	devide_map(&data);
	map_valid_test(&data);
	map_value_check(&data);
	init_cub3d(&data);
	run_cub3d(&data);
	return (0);
}
