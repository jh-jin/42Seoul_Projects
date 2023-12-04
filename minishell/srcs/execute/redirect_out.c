/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:22:11 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_cmd_node	*have_redirect_out(t_cmd_node *node);
static void			do_redir_out(char *cmd);
static void			do_redir_append(char *cmd);

/* ************************************************************************** */

void	redir_out(t_cmd_node *node)
{
	t_cmd_node	*redir_out_node;
	int			fd;

	redir_out_node = have_redirect_out(node);
	if (redir_out_node != NULL)
	{
		if (redir_out_node->type == REDIROUT)
			fd = open(redir_out_node->next->cmd, O_RDWR, 0644);
		else
			fd = open(redir_out_node->next->cmd, O_RDWR | O_APPEND, 0644);
		if (fd < 0)
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

/* ************************************************************************** */

static t_cmd_node	*have_redirect_out(t_cmd_node *node)
{
	t_cmd_node	*redirect_out;

	redirect_out = NULL;
	while (node != NULL)
	{
		if (node->type == REDIROUT)
		{
			do_redir_out(node->next->cmd);
			redirect_out = node;
		}
		else if (node->type == APPEND)
		{
			do_redir_append(node->next->cmd);
			redirect_out = node;
		}
		node = node->next;
	}
	if (redirect_out)
		return (redirect_out);
	return (NULL);
}

/* ************************************************************************** */

static void	do_redir_out(char *cmd)
{
	int			fd;
	struct stat	s;

	if (stat(cmd, &s) == 0)
	{
		fd = open(cmd, O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			exit(1);
		}
		close(fd);
	}
	else
	{
		fd = open(cmd, O_RDWR | O_CREAT, 0644);
		if (fd < 0)
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			exit(1);
		}
		close(fd);
	}
}

/* ************************************************************************** */

static void	do_redir_append(char *cmd)
{
	int			fd;
	struct stat	s;

	if (stat(cmd, &s) != 0)
	{
		fd = open(cmd, O_RDWR | O_CREAT, 0644);
		if (fd < 0)
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			exit(1);
		}
		close(fd);
	}
}

/* ************************************************************************** */