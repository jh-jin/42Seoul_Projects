/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:35:51 by jjin              #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

void	move_heredoc_curser(int fd)
{
	close(fd);
	ft_putstr_fd("\x1b[1A", 1);
	ft_putstr_fd("\033[2C", 1);
	exit(0);
}

/* ************************************************************************** */

static int	write_dollar_heredoc(char *line, int start, int len, int fd)
{
	char	*name;
	char	*value;

	name = ft_substr(line, start, len);
	if (name == NULL)
	{
		write(fd, "\n", 1);
		return (false);
	}
	value = get_env_value_via_key(name);
	if (value == NULL)
	{
		free(name);
		write(fd, "\n", 1);
		return (false);
	}
	ft_putstr_fd(value, fd);
	free(name);
	return (true);
}

/* ************************************************************************** */

void	finish_heredoc(char **line, int fd, int end_status)
{
	if (*line != NULL)
		free(*line);
	if (fd >= 0)
		close(fd);
	exit(end_status);
}

/* ************************************************************************** */

int	write_heredoc(int fd, char *line)
{
	int		idx;
	int		temp;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '$' && line[idx + 1] != '\0' && \
		line[idx + 1] != ' ')
		{
			temp = ++idx;
			while (line[idx] != '\0' && !(ft_isspace(line[idx])) && \
			line[idx] != '$')
				idx++;
			if (write_dollar_heredoc(line, temp, idx - temp, fd) == false)
				return (false);
		}
		else
		{
			ft_putchar_fd(line[idx], fd);
			idx++;
		}
	}
	write(fd, "\n", 1);
	return (true);
}

/* ************************************************************************** */