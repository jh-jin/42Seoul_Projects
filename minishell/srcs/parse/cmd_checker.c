/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:36:53 by jjin              #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_valid_redirect_arg(t_cmd_node **curr_cmd);
static int	is_common_cmd(t_cmd_node *cmd);
static int	is_echo_option(t_cmd_node *node);
static int	is_builtin(t_cmd_node **curr);

/* ************************************************************************** */

int	command_validator(t_cmd_list *cmd_list)
{
	int			i;
	int			flag;
	t_cmd_node	*curr;

	i = 0;
	while (i < cmd_list->size)
	{
		flag = 0;
		curr = cmd_list->cmd_heads[i];
		while (curr != NULL)
		{
			if (!is_valid_redirect_arg(&curr))
				return (false);
			if (!flag && curr->type == COMMON && is_builtin(&curr))
				tolower_str(curr->cmd);
			if (!flag && (curr->type == COMMON || curr->type == BUILTIN))
				flag = 1;
			curr = curr->next;
		}
		i++;
	}
	return (true);
}

/* ************************************************************************** */

static int	is_valid_redirect_arg(t_cmd_node **curr_cmd)
{
	enum e_cmd_type	type;

	type = (*curr_cmd)->type;
	if (!is_common_cmd(*curr_cmd))
	{
		if (is_common_cmd((*curr_cmd)->next))
		{
			*curr_cmd = (*curr_cmd)->next;
			(*curr_cmd)->type = REDIRARG;
		}
		else
			return (parse_error(PERR_STX));
	}
	if (type == HEREDOC)
	{
		if (do_heredoc(curr_cmd) == false)
		{
			remove_temp_file();
			return (false);
		}		
	}
	return (1);
}

/* ************************************************************************** */

static int	is_common_cmd(t_cmd_node *cmd)
{
	enum e_cmd_type	type;

	if (cmd == NULL)
		return (false);
	type = cmd->type;
	if (type == REDIRIN || type == REDIROUT || type == HEREDOC || \
		type == APPEND)
		return (false);
	return (1);
}

/* ************************************************************************** */

static int	is_echo_option(t_cmd_node *node)
{
	int	i;

	i = 0;
	if (node != NULL && node->cmd[i++] == '-')
	{
		while (node->cmd[i] == 'n')
			i++;
		if (node->cmd[i] == '\0')
			return (true);
	}
	return (false);
}

/* ************************************************************************** */

static int	is_builtin(t_cmd_node **curr)
{
	int		ret;
	char	*temp;

	temp = get_lower_str((*curr)->cmd);
	ret = 0;
	if (!ft_strcmp(temp, "echo"))
	{
		(*curr)->type = BUILTIN;
		while (is_echo_option((*curr)->next))
		{
			*curr = (*curr)->next;
			(*curr)->type = OPTION;
		}
		ret = 1;
	}
	else if (!ft_strcmp(temp, "cd") || !ft_strcmp(temp, "pwd") || \
		!ft_strcmp(temp, "export") || !ft_strcmp(temp, "unset") || \
		!ft_strcmp(temp, "env") || !ft_strcmp(temp, "exit"))
	{
		(*curr)->type = BUILTIN;
		ret = 1;
	}
	free(temp);
	return (ret);
}

/* ************************************************************************** */