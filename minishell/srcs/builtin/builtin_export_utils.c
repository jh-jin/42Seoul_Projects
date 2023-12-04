/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:20:59 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

t_env_node	*is_in_envp(char *str)
{
	t_env_node	*node;
	char		*key;

	key = extract_env_key(str);
	if (key == NULL)
		key = ft_strdup(str);
	node = get_env_node_via_key(key);
	free(key);
	return (node);
}

/* ************************************************************************** */

void	append_new_env_node(t_env_node *new_node)
{
	t_env_node	*curr;

	curr = g_state.env_head;
	if (curr == NULL)
	{
		g_state.env_head = new_node;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

/* ************************************************************************** */

void	new_export(char *str)
{
	t_env_node	*new_node;

	new_node = create_env_node(extract_env_key(str), extract_env_value(str));
	append_new_env_node(new_node);
}

/* ************************************************************************** */

int	is_right_form(char *str)
{
	int	i;

	i = 0;
	if (ft_isalpha(str[0]) == false && str[0] != '_')
		return (false);
	if (has_equal_sign(str) == true)
	{
		while (str[i] != '=')
		{
			if (ft_isalnum(str[i]) == false && str[i] != '_')
				return (false);
			i++;
		}
		return (true);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == false && str[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

/* ************************************************************************** */