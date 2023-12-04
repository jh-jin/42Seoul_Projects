/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:31:05 by jjin              #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

/**
 * @brief Create a new command list and returns it. 
 * 
 * @return t_cmd_list* 
 */
t_cmd_list	*init_cmd(void)
{
	t_cmd_list	*new_cmd_list;

	new_cmd_list = (t_cmd_list *)ft_malloc(sizeof(t_cmd_list), 1);
	return (new_cmd_list);
}

/* ************************************************************************** */

/**
 * @brief Count commands and malloc command array. 
 * 
 * @param cmd_list 
 * @param token_head 
 */
void	init_cmd_size(t_cmd_list *cmd_list, t_token_node *token_head)
{
	t_token_node	*curr;

	curr = token_head;
	cmd_list->size = 1;
	while (curr != NULL)
	{
		if (curr->type == PIPE)
			cmd_list->size++;
		curr = curr->next;
	}
	cmd_list->cmd_heads = ft_malloc(sizeof(t_cmd_node *), cmd_list->size);
}

/* ************************************************************************** */