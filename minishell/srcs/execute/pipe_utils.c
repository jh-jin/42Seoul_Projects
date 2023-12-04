/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:22:08 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_variables(int size, int ***fd, pid_t **pid, int **status);

/* ************************************************************************** */

void	pipe_process(int size, int ***fd)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (pipe((*fd)[i]) == -1)
			exit(1);
		i++;
	}
}

/* ************************************************************************** */

void	close_wait(int ***fd, pid_t **pid, int **status, int size)
{
	int	i;

	set_signal(CUSTOM, CUSTOM);
	i = 0;
	while (i < size - 1)
	{
		close((*fd)[i][0]);
		close((*fd)[i][1]);
		i++;
	}
	set_signal(IGNORE, IGNORE);
	wait_childs(pid, size);
	set_signal(CUSTOM, CUSTOM);
	free_variables(size, fd, pid, status);
}

/* ************************************************************************** */

static void	free_variables(int size, int ***fd, pid_t **pid, int **status)
{
	free_array(*fd, size - 1);
	free(*pid);
	pid = NULL;
	free(*status);
	status = NULL;
}

/* ************************************************************************** */

void	close_fd(int ***fd, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close((*fd)[i][0]);
		close((*fd)[i][1]);
		i++;
	}
}

/* ************************************************************************** */