/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:21:01 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

/**
 * @brief pwd command. 
 * 
 */
void	builtin_pwd(void)
{
	char	*curr_dir;

	curr_dir = getcwd(NULL, 0);
	if (curr_dir == NULL)
	{
		printf("getcwd() cannot execute in fun_pwd\n");
		g_state.exit_status = 1;
	}
	else
	{
		printf("%s\n", curr_dir);
		free(curr_dir);
		g_state.exit_status = 0;
	}
}

/* ************************************************************************** */