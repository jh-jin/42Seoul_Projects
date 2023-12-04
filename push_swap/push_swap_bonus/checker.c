/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:29:51 by jjin              #+#    #+#             */
/*   Updated: 2022/11/16 10:38:48 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker(t_stack *a, t_stack *b)
{
	char	*s;

	if (a->len == 0)
		return ;
	while (1)
	{
		s = get_next_line(0);
		if (s == NULL)
			break ;
		parse_operation(a, b, s);
		free(s);
	}
	if (is_sorted_two(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	parse_operation(t_stack *a, t_stack *b, char *s)
{
	if (ft_strcmp(s, "pa\n"))
		push(b, a);
	else if (ft_strcmp(s, "pb\n"))
		push(a, b);
	else if (ft_strcmp(s, "sa\n"))
		swap(a);
	else if (ft_strcmp(s, "sb\n"))
		swap(b);
	else if (ft_strcmp(s, "ra\n"))
		rotate(a);
	else if (ft_strcmp(s, "rb\n"))
		rotate(b);
	else if (ft_strcmp(s, "rra\n"))
		reverse_rotate(a);
	else if (ft_strcmp(s, "rrb\n"))
		reverse_rotate(b);
	else if (ft_strcmp(s, "ss\n"))
		swap_double(a, b);
	else if (ft_strcmp(s, "rr\n"))
		rotate_double(a, b);
	else if (ft_strcmp(s, "rrr\n"))
		reverse_rotate_double(a, b);
	else
		ft_exit("Error\n");
}

int	ft_strcmp(char *s, char *com)
{
	while (*s && *com)
	{
		if (*s != *com)
			return (0);
		s++;
		com++;
	}
	if (*s == 0 && *com == 0)
		return (1);
	else
		return (0);
}

int	is_sorted_two(t_stack *a, t_stack *b)
{
	if (b->len != 0 || a->len == 0)
		return (0);
	if (a->len == 1)
		return (1);
	return (is_sorted(a));
}

int	is_sorted(t_stack *s)
{
	t_node	*i;
	t_node	*j;

	i = s->head;
	while (i->next)
	{
		j = i->next;
		if (i->rank > j->rank)
			return (0);
		i = i->next;
	}
	return (1);
}
