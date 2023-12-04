/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:22:08 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

void	wait_child(void)
{
	int		status;
	int		signo;

	while (wait(&status) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT)
				ft_putstr_fd("\n", STDERR_FILENO);
			if (signo == SIGQUIT)
				ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
			g_state.exit_status = 128 + signo;
		}
		else
			g_state.exit_status = WEXITSTATUS(status);
	}
}

/* ************************************************************************** */

void	wait_childs(pid_t **pid, int size)
{
	int		status;
	int		signo;
	int		i;

	i = 0;
	while (i < size)
	{
		if (i + 1 == size)
			waitpid((*pid)[i], &status, 0);
		else
			waitpid((*pid)[i], NULL, 0);
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT)
				ft_putstr_fd("\n", STDERR_FILENO);
			if (signo == SIGQUIT)
				ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
			g_state.exit_status = 128 + signo;
		}
		else
			g_state.exit_status = WEXITSTATUS(status);
		i++;
	}
}

/* ************************************************************************** */
