/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_news.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:12:26 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/12 23:03:12 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_north(t_data *data, char *tmp)
{
	char	*north;
	char	*temp;
	char	*ext;

	if (!tmp[1] || tmp[1] != 'O')
		print_err("Argument Error");
	if (!tmp[2] || tmp[2] != ' ')
		print_err("Argument Error");
	north = ft_substr(tmp, 2, ft_strlen(tmp));
	temp = ft_strdup(north);
	free(north);
	north = ft_strtrim(temp, data->isspace);
	free(temp);
	ext = ft_substr(north, ft_strlen(north) - 4, ft_strlen(north));
	if (ft_strncmp(ext, ".xpm", ft_strlen(ext)) != 0)
		print_err("NO image does not have .xpm extension");
	free(ext);
	data->no_cnt++;
	data->no = ft_strdup(north);
	free(north);
}

void	check_south(t_data *data, char *tmp)
{
	char	*south;
	char	*temp;
	char	*ext;

	if (!tmp[1] || tmp[1] != 'O')
		print_err("Argument Error");
	if (!tmp[2] || tmp[2] != ' ')
		print_err("Argument Error");
	south = ft_substr(tmp, 2, ft_strlen(tmp));
	temp = ft_strdup(south);
	free(south);
	south = ft_strtrim(temp, data->isspace);
	free(temp);
	ext = ft_substr(south, ft_strlen(south) - 4, ft_strlen(south));
	if (ft_strncmp(ext, ".xpm", ft_strlen(ext)) != 0)
		print_err("SO image does not have .xpm extension");
	free(ext);
	data->so_cnt++;
	data->so = ft_strdup(south);
	free(south);
}

void	check_west(t_data *data, char *tmp)
{
	char	*west;
	char	*temp;
	char	*ext;

	if (!tmp[1] || tmp[1] != 'E')
		print_err("Argument Error");
	if (!tmp[2] || tmp[2] != ' ')
		print_err("Argument Error");
	west = ft_substr(tmp, 2, ft_strlen(tmp));
	temp = ft_strdup(west);
	free(west);
	west = ft_strtrim(temp, data->isspace);
	free(temp);
	ext = ft_substr(west, ft_strlen(west) - 4, ft_strlen(west));
	if (ft_strncmp(ext, ".xpm", ft_strlen(ext)) != 0)
		print_err("WE image does not have .xpm extension");
	free(ext);
	data->we_cnt++;
	data->we = ft_strdup(west);
	free(west);
}

void	check_east(t_data *data, char *tmp)
{
	char	*east;
	char	*temp;
	char	*ext;

	if (!tmp[1] || tmp[1] != 'A')
		print_err("Argument Error");
	if (!tmp[2] || tmp[2] != ' ')
		print_err("Argument Error");
	east = ft_substr(tmp, 2, ft_strlen(tmp));
	temp = ft_strdup(east);
	free(east);
	east = ft_strtrim(temp, data->isspace);
	free(temp);
	ext = ft_substr(east, ft_strlen(east) - 4, ft_strlen(east));
	if (ft_strncmp(ext, ".xpm", ft_strlen(ext)) != 0)
		print_err("EA image does not have .xpm extension");
	free(ext);
	data->ea_cnt++;
	data->ea = ft_strdup(east);
	free(east);
}
