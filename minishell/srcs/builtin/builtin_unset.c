/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:21:04 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_valid_env(char *str);
void		remove_node_in_envp(t_env_node *node);

/* ************************************************************************** */

void	builtin_unset_one_cmd(t_cmd_node *head)
{
	t_cmd_node	*curr_node;
	t_env_node	*node_in_envp;

	curr_node = head->next;
	while (curr_node != NULL)
	{
		if (is_valid_env(curr_node->cmd) == true)
		{
			node_in_envp = is_in_envp(curr_node->cmd);
			if (node_in_envp != NULL)
				remove_node_in_envp(node_in_envp);
		}
		else if (is_right_form(curr_node->cmd) == false)
			unset_error_single(curr_node->cmd);
		curr_node = curr_node->next;
	}
}

/* ************************************************************************** */

void	builtin_unset(t_cmd_node *head)
{
	int			flag;
	t_cmd_node	*curr_node;

	curr_node = head->next;
	while (curr_node != NULL)
	{
		if (is_right_form(curr_node->cmd) == false)
			flag = unset_error(curr_node->cmd);
		curr_node = curr_node->next;
	}
	if (flag == true)
		exit(1);
}

/* ************************************************************************** */

static int	is_valid_env(char *str)
{
	int	i;

	i = -1;
	if (ft_isalpha(str[0]) == false && str[0] != '_')
		return (false);
	while (str[++i])
	{
		if (ft_isalnum(str[i]) == false && str[i] != '_')
			return (false);
	}
	return (true);
}

/* ************************************************************************** */

void	remove_node_in_envp(t_env_node *node)
{
	t_env_node	*prev;

	if (node == NULL)
		return ;
	if (node == g_state.env_head)
		prev = NULL;
	else
	{
		prev = g_state.env_head;
		while (prev->next != node)
			prev = prev->next;
	}
	if (prev == NULL)
		g_state.env_head = node->next;
	else
		prev->next = node->next;
	free(node->key);
	free(node->value);
	free(node);
}

/* ************************************************************************** */
