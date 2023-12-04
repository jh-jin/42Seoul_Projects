/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:22:06 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/15 14:31:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */

static int	malloc_fd(int size, int ***fd)
{
	int	i;

	*fd = (int **)malloc(sizeof(int *) * size);
	if (*fd == NULL)
		return (false);
	ft_memset(*fd, 0, sizeof(*fd));
	i = 0;
	while (i < size)
	{
		(*fd)[i] = (int *)malloc(sizeof(int) * 2);
		if ((*fd)[i] == NULL)
		{
			free_array((*fd), i);
			return (false);
		}
		ft_memset((*fd)[i], 0, sizeof((*fd)[i]));
		i++;
	}
	return (true);
}

/* ************************************************************************** */

static int	malloc_pid(int size, pid_t **pid)
{
	*pid = (pid_t *)malloc(sizeof(pid_t) * size);
	if (*pid == NULL)
		return (false);
	ft_memset(*pid, 0, sizeof(*pid));
	return (true);
}

/* ************************************************************************** */

static int	malloc_status(int size, int **status)
{
	*status = (int *)malloc(sizeof(int) * size);
	if (*status == NULL)
		return (false);
	ft_memset(*status, 0, sizeof(*status));
	return (true);
}

/* ************************************************************************** */

/**
 * @brief Malloc variables. fd arrays for pipe, pid array to save pid of child 
 * process which will be created and array of the exit status of each child 
 * process will be malloced. 
 * 
 * @param size 
 * @param fd 
 * @param pid 
 * @param status 
 */
void	malloc_variables(int size, int ***fd, pid_t **pid, int **status)
{
	if (malloc_fd(size - 1, fd) != true || malloc_pid \
	(size, pid) != true || malloc_status(size, status) != true)
	{
		g_state.exit_status = 1;
		exit(1);
	}
}

/* ************************************************************************** */

/**
 * @brief 
 * 
 * @param src_node 
 * @return t_cmd_node* 
 */
t_cmd_node	*cmd_dup(t_cmd_node *src_node)
{
	t_cmd_node	*new_node;

	new_node = (t_cmd_node *)ft_malloc(sizeof(t_cmd_node), 1);
	new_node->cmd = ft_strdup(src_node->cmd);
	if (new_node->cmd == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->type = src_node->type;
	return (new_node);
}

/* ************************************************************************** */