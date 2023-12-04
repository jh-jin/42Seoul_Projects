/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:33:40 by wonljeon          #+#    #+#             */
/*   Updated: 2023/05/09 22:12:03 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*make_backup(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	temp = ft_strdup(line + i + 1);
	if (temp == NULL)
		return (NULL);
	line[i + 1] = '\0';
	return (temp);
}

char	*make_line(int fd, char *backup, char *buf)
{
	char	*temp;
	int		n;

	n = 1;
	while (n)
	{
		n = read(fd, buf, 42);
		if (n == -1)
			return (NULL);
		if (n == 0)
			break ;
		buf[n] = '\0';
		if (backup == NULL)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (backup == NULL)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;

	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (43));
	if (!buf)
		print_err("Memory allocation error");
	line = make_line(fd, backup, buf);
	free(buf);
	buf = NULL;
	if (line == NULL || *line == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = make_backup(line);
	return (line);
}
