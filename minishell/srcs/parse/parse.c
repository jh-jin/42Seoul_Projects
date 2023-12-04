/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:26:09 by jjin              #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_readline(char **line);
static int	is_empty_line(char *line);
static void	release_line(char *line);
static void	release_token_list(t_token_node *token_head);

/* ************************************************************************** */

int	parse(t_cmd_list *cmd_list)
{
	char			*line;
	t_token_node	*token_head;

	ft_readline(&line);
	if (is_empty_line(line))
	{
		release_line(line);
		return (false);
	}
	add_history(line);
	if (tokenization(&token_head, line) == false || \
		transformation(cmd_list, token_head, line) == false)
	{
		release_line(line);
		release_token_list(token_head);
		return (false);
	}
	release_line(line);
	release_token_list(token_head);
	return (true);
}

/* ************************************************************************** */

static void	ft_readline(char **line)
{
	*line = readline("JSH >");
	if (!*line)
	{
		printf("exit\n");
		exit(0);
	}
}

/* ************************************************************************** */

static int	is_empty_line(char *line)
{
	while (*line != '\0')
	{
		if (!ft_isspace(*line))
			return (false);
		line++;
	}
	return (1);
}

/* ************************************************************************** */

static void	release_line(char *line)
{
	if (line != NULL)
		free(line);
}

/* ************************************************************************** */

static void	release_token_list(t_token_node *token_head)
{
	t_token_node	*curr;
	t_token_node	*temp;

	curr = token_head;
	while (curr != NULL)
	{
		temp = curr;
		free(curr->token);
		curr = curr->next;
		free(temp);
	}
}

/* ************************************************************************** */
