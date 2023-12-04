/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:34:56 by jjin              #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

void	new_quote(t_cmd_node **cmd_head, t_token_node **token_head)
{
	char			*new_str;
	t_cmd_node		*new_cmd;
	t_token_node	*curr;

	curr = *token_head;
	new_str = ft_strdup(curr->token);
	new_cmd = create_command_node(new_str, COMMON);
	cmd_lstadd_back(cmd_head, new_cmd);
}

/* ************************************************************************** */