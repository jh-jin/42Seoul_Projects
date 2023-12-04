/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:20:59 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	export_wihtout_arg(t_cmd_node *head);

/* ************************************************************************** */

void	builtin_export(t_cmd_node *node)
{
	int			flag;

	flag = false;
	export_wihtout_arg(node);
	node = node->next;
	while (node != NULL)
	{
		if (is_right_form(node->cmd) == false)
		{
			flag = true;
			ft_putstr_fd("JSH: export : ", STDERR_FILENO);
			ft_putstr_fd(node->cmd, STDERR_FILENO);
			ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
		}
		node = node->next;
	}
	if (flag == true)
		exit(1);
}

/* ************************************************************************** */

static void	export_wihtout_arg(t_cmd_node *head)
{
	t_env_node	*node;

	if (head->next == NULL)
	{
		node = g_state.env_head;
		while (node)
		{
			if (node->value == NULL)
				printf("declare -x %s\n", node->key);
			else
				printf("declare -x %s=\"%s\"\n", node->key, node->value);
			node = node->next;
		}
	}
}

/* ************************************************************************** */

int	has_equal_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (true);
		i++;
	}
	return (false);
}

/* ************************************************************************** */

int	modify_envp(char *str, char *key)
{
	t_env_node	*curr;
	char		*temp;

	curr = g_state.env_head;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			temp = ft_strchr(str, '=');
			if (!temp)
				return (true);
			temp++;
			free(curr->value);
			curr->value = ft_substr(temp, 0, ft_strlen(temp));
			return (true);
		}
		curr = curr->next;
	}
	return (false);
}

/* ************************************************************************** */

void	builtin_export_one_cmd(t_cmd_node *node)
{
	t_env_node	*node_in_envp;

	export_wihtout_arg(node);
	node = node->next;
	while (node != NULL)
	{
		if (is_right_form(node->cmd) == false)
		{
			ft_putstr_fd("JSH: export : ", STDERR_FILENO);
			ft_putstr_fd(node->cmd, STDERR_FILENO);
			ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
			g_state.exit_status = 1;
		}
		else
		{
			node_in_envp = is_in_envp(node->cmd);
			if (node_in_envp != NULL)
				modify_envp(node->cmd, node_in_envp->key);
			else
				new_export(node->cmd);
		}
		node = node->next;
	}
}

/* ************************************************************************** */