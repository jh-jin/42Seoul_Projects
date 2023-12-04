/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:20:51 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	echo_print(t_cmd_node *node);

/* ************************************************************************** */

void	builtin_echo(t_cmd_node *node)
{
	int			option;

	option = false;
	node = node->next;
	if (node == NULL)
	{
		printf("\n");
		g_state.exit_status = 0;
		return ;
	}
	if (node->type == OPTION)
	{
		option = true;
		node = node->next;
	}
	g_state.exit_status = 0;
	if (node == NULL)
		return ;
	echo_print(node);
	if (option == false)
		printf("\n");
}

/* ************************************************************************** */

static void	echo_print(t_cmd_node *node)
{
	while (node->next != NULL)
	{
		if (node->type == COMMON)
			printf("%s ", node->cmd);
		node = node->next;
	}
	printf("%s", node->cmd);
}

/* ************************************************************************** */