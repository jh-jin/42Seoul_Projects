/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/01/15 15:19:03 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_banner(void);
static void	clear_cmd(t_cmd_list *cmd_line_list);
static void	set_old_pwd(void);

/* ************************************************************************** */

int	main(int argc, char **argv, char **envp)
{
	t_cmd_list	*cmd_list;

	if (argc != 1)
		exit_with_err("No arguments allowed for JSH 🤫", NULL, 1);
	(void)argv;
	print_banner();
	init_env(envp);
	set_old_pwd();
	set_signal(CUSTOM, CUSTOM);
	while (1)
	{
		disable_echoctl();
		cmd_list = init_cmd();
		if (parse(cmd_list) == false)
		{
			clear_cmd(cmd_list);
			continue ;
		}
		enable_echoctl();
		execute_cmd(cmd_list);
		clear_cmd(cmd_list);
		remove_temp_file();
	}
	return (0);
}

/* ************************************************************************** */

static void	print_banner(void)
{
	char	*str;
	char	*author;
	size_t	i;
	int		color_i;

	str = BANNER_ASCII_STR;
	author = "\033[0;90m jjin & seoyoo\033[0m";
	i = 0;
	color_i = 0;
	while (str[i] != '\0')
	{
		printf("\033[0;9%dm", color_i++ % 8);
		printf("%c", str[i++]);
		printf("\033[0m");
		if (str[i] == '\n')
			color_i = 0;
	}
	i = 0;
	while (i < 80 - ft_strlen(author))
	{
		printf(" ");
		i++;
	}
	printf("%s\n", author);
}

/* ************************************************************************** */

static void	clear_cmd(t_cmd_list *cmd_line_list)
{
	t_cmd_node	*curr;
	t_cmd_node	*temp;
	int			idx;

	idx = 0;
	while (idx < cmd_line_list->size)
	{
		if (cmd_line_list->cmd_heads == NULL)
			break ;
		curr = cmd_line_list->cmd_heads[idx];
		while (curr != NULL)
		{
			temp = curr;
			if (curr->cmd != 0)
				free(curr->cmd);
			curr = curr->next;
			free(temp);
		}
		idx++;
	}
	free(cmd_line_list->cmd_heads);
	free(cmd_line_list);
	cmd_line_list = NULL;
}

/* ************************************************************************** */

static void	set_old_pwd(void)
{
	char		*old_pwd_value;

	old_pwd_value = get_env_value_via_key("OLDPWD");
	if (old_pwd_value == NULL)
		new_export(ft_strjoin_with_free_srcs(ft_strdup("OLDPWD="), get_pwd()));
}

/* ************************************************************************** */