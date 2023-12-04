/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:21:51 by jjin              #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

void	add_quote_cmd(t_cmd_node **cmd_head, t_token_node **token_head, \
		char *line)
{
	t_token_node	*curr;

	curr = *token_head;
	if (need_join(curr, line, 1))
	{
		if (curr->type == QUOTE)
			join_cmd(cmd_head, curr->token);
		else
			join_dquote(cmd_head, &curr);
	}
	else
	{
		if (curr->type == QUOTE)
			new_quote(cmd_head, &curr);
		else
			new_dquote(cmd_head, &curr);
	}
	return ;
}

/* ************************************************************************** */

void	add_dollar_cmd(t_cmd_node **cmd_head, \
		t_token_node **token_head, char *line)
{
	t_token_node	*curr;
	t_cmd_node		*new_cmd;
	char			*converted_token;

	curr = *token_head;
	if (curr->next == NULL)
		converted_token = ft_strdup("$");
	else
		converted_token = transform_dollar_token(curr->next->token, \
			curr->next->idx, line);
	if (need_join(curr, line, 2))
	{
		join_cmd(cmd_head, converted_token);
		if (curr->next != NULL)
			*token_head = curr->next;
		free(converted_token);
		return ;
	}
	new_cmd = create_command_node(converted_token, COMMON);
	cmd_lstadd_back(cmd_head, new_cmd);
	if (line[curr->idx + 1] == ' ')
		;
	else if (curr->next != NULL && curr->next->type != PIPE)
		curr = curr->next;
	*token_head = curr;
}

/* ************************************************************************** */

void	add_common_cmd(t_cmd_node **cmd_head, t_token_node **token_head, \
		char *line)
{
	t_token_node	*curr;
	t_cmd_node		*new_cmd;

	curr = *token_head;
	if (need_join(curr, line, 3))
	{
		join_cmd(cmd_head, curr->token);
		return ;
	}
	new_cmd = create_command_node(ft_strdup(curr->token), \
		(enum e_cmd_type)curr->type);
	cmd_lstadd_back(cmd_head, new_cmd);
}

/* ************************************************************************** */

void	convert_token_to_command(t_cmd_node **cmd_head, \
		t_token_node **token_head, char *line)
{
	t_token_node	*curr;

	curr = *token_head;
	while (curr != NULL && curr->type != PIPE)
	{
		if (curr->type == DQUOTE || curr->type == QUOTE)
			add_quote_cmd(cmd_head, &curr, line);
		else if (curr->token[0] == '$')
			add_dollar_cmd(cmd_head, &curr, line);
		else
			add_common_cmd(cmd_head, &curr, line);
		curr = curr->next;
	}
	if (curr != NULL)
		curr = curr->next;
	*token_head = curr;
	return ;
}

/* ************************************************************************** */

int	transformation(t_cmd_list *cmd_list, t_token_node *token_head, char *line)
{
	int				i;
	t_token_node	*curr_token;

	i = 0;
	curr_token = token_head;
	init_cmd_size(cmd_list, token_head);
	while (i < cmd_list->size)
	{
		convert_token_to_command(&(cmd_list->cmd_heads[i]), &curr_token, line);
		i++;
		if (i < cmd_list->size && (curr_token == NULL || \
			cmd_list->cmd_heads[i - 1] == NULL))
			return (parse_error(PERR_PIPE));
	}
	return (command_validator(cmd_list));
}

/* ************************************************************************** */
