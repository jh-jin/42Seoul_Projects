/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:54:03 by jjin              #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

char	*get_env_value_via_key(char *key)
{
	t_env_node	*curr;

	if (*key == '\0')
		return (NULL);
	curr = g_state.env_head;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}

/* ************************************************************************** */

t_env_node	*get_env_node_via_key(char *key)
{
	t_env_node	*curr;

	if (*key == '\0')
		return (NULL);
	curr = g_state.env_head;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

/* ************************************************************************** */

char	*extract_env_key(char *env_str)
{
	size_t	len_key;
	char	*key;

	len_key = 0;
	while (env_str[len_key] != 0 && env_str[len_key] != '=')
		len_key++;
	key = ft_substr(env_str, 0, len_key);
	return (key);
}

/* ************************************************************************** */

char	*extract_env_value(char *env_str)
{
	size_t	len_key;
	char	*value;

	len_key = 0;
	while (env_str[len_key] != 0 && env_str[len_key] != '=')
		len_key++;
	if (env_str[len_key] == '\0')
		return (NULL);
	value = ft_substr(env_str, len_key + 1, ft_strlen(env_str));
	return (value);
}

/* ************************************************************************** */

t_env_node	*create_env_node(char *key, char *value)
{
	t_env_node	*node;

	node = (t_env_node *)ft_malloc(sizeof(t_env_node), 1);
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

/* ************************************************************************** */