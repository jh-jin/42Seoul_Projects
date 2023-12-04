/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:20 by jjin              #+#    #+#             */
/*   Updated: 2023/01/15 15:18:36 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		g_state.exit_status = 130;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signo == SIGQUIT)
	{
		g_state.exit_status = 131;
		rl_on_new_line();
		rl_redisplay();
	}
}

/* ************************************************************************** */

void	set_signal(enum e_sig_type sig_int, enum e_sig_type sig_quit)
{
	if (sig_int == IGNORE)
		signal(SIGINT, SIG_IGN);
	else if (sig_int == DEFAULT)
		signal(SIGINT, SIG_DFL);
	else if (sig_int == CUSTOM)
		signal(SIGINT, signal_handler);
	if (sig_quit == IGNORE)
		signal(SIGQUIT, SIG_IGN);
	else if (sig_quit == DEFAULT)
		signal(SIGQUIT, SIG_DFL);
	else if (sig_quit == CUSTOM)
		signal(SIGQUIT, signal_handler);
}

/* ************************************************************************** */