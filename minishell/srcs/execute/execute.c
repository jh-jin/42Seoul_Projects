/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:22:05 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

void	execute_cmd(t_cmd_list *cmd_line_list)
{
	if (cmd_line_list->size == 1)
	{
		g_state.forked = false;
		execute_without_pipe(cmd_line_list);
	}
	else
	{
		g_state.forked = true;
		execute_with_pipe(cmd_line_list);
	}
}

/* ************************************************************************** */

void	execve_error(char *strerror, t_cmd_node *cmd_list)
{
	if (ft_strcmp(strerror, "Bad address") == 0)
	{
		ft_putstr_fd("JSH: ", STDERR_FILENO);
		ft_putstr_fd(cmd_list->cmd, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(127);
	}
	else if (ft_strcmp(strerror, "Permission denied") == 0)
	{
		ft_putstr_fd("JSH: ", STDERR_FILENO);
		ft_putstr_fd(cmd_list->cmd, STDERR_FILENO);
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
		exit(126);
	}
}

/* ************************************************************************** */

char	**set_envp(void)
{
	char		**env;
	int			i;
	int			size;
	t_env_node	*node;

	size = 0;
	node = g_state.env_head;
	while (node)
	{
		size++;
		node = node->next;
	}
	env = (char **)ft_malloc(sizeof(char *), (size + 1));
	node = g_state.env_head;
	i = 0;
	while (node)
	{
		env[i++] = ft_strjoin_with_free_srcs(ft_strjoin(node->key, "="), \
		ft_strdup(node->value));
		node = node->next;
	}
	env[i] = NULL;
	return (env);
}

/* ************************************************************************** */