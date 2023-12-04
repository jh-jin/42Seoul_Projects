/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:22:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exe_one_cmd_with_pipe(t_cmd_node *node, int ***fd, int size);

/* ************************************************************************** */

void	execute_with_pipe(t_cmd_list *list)
{
	int		idx;
	int		**fd;
	pid_t	*pid;
	int		*status;

	malloc_variables(list->size, &fd, &pid, &status);
	pipe_process(list->size, &fd);
	idx = -1;
	set_signal(DEFAULT, DEFAULT);
	while (++idx < list->size)
	{
		pid[idx] = fork();
		if (pid[idx] < 0)
			exit(1);
		else if (pid[idx] == 0)
		{
			if (idx > 0)
				dup2(fd[idx - 1][0], STDIN_FILENO);
			if (idx < list->size - 1)
				dup2(fd[idx][1], STDOUT_FILENO);
			exe_one_cmd_with_pipe(list->cmd_heads[idx], &fd, list->size);
		}
	}
	close_wait(&fd, &pid, &status, list->size);
}

/* ************************************************************************** */

static void	exe_one_cmd_with_pipe(t_cmd_node *node, int ***fd, int size)
{
	t_cmd_node	*cmd_node;
	char		*path;
	char		**args;
	char		**envp_for_execve;

	redir_in(node);
	redir_out(node);
	cmd_node = remove_redirection_in_cmd(node);
	if (cmd_node == NULL)
		exit(0);
	close_fd(fd, size - 1);
	if (cmd_node->type == BUILTIN)
		execute_builtin(cmd_node);
	path = is_valid_cmd(cmd_node->cmd);
	args = cmd_change_to_array(cmd_node);
	envp_for_execve = set_envp();
	if (execve(path, args, envp_for_execve) == -1)
	{
		free_split(envp_for_execve);
		execve_error(strerror(errno), cmd_node);
	}
	free_split(envp_for_execve);
}

/* ************************************************************************** */