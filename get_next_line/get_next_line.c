/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:18:45 by jjin              #+#    #+#             */
/*   Updated: 2022/08/24 20:48:36 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_contain_newline(int fd, char *buf, char *backup)
{
	int		readcnt;
	char	*tmp;

	readcnt = 1;
	while (readcnt)
	{
		readcnt = read(fd, buf, BUFFER_SIZE);
		if (readcnt == -1)
			return (NULL);
		if (readcnt == 0)
			break ;
		buf[readcnt] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		if (!backup)
			return (NULL);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*ft_cut_backup(char *ret)
{
	int		i;
	char	*newbackup;

	i = 0;
	while (ret[i] != '\n' && ret[i] != '\0')
		i++;
	if (ret[i] == '\0')
		return (NULL);
	newbackup = ft_substr(ret, i + 1, ft_strlen(ret) - i);
	if (!newbackup)
		return (NULL);
	if (newbackup[0] == '\0')
	{
		free(newbackup);
		return (NULL);
	}
	ret[i + 1] = '\0';
	return (newbackup);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = ft_contain_newline(fd, buf, backup);
	free(buf);
	if (!ret)
		return (NULL);
	backup = ft_cut_backup(ret);
	return (ret);
}
