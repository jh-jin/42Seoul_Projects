/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:49:45 by jjin              #+#    #+#             */
/*   Updated: 2022/12/16 23:14:19 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cnt_from_top(t_stack *a, int max_rank)
{
	t_node	*stack;
	int		cnt;
	int		half_len;

	stack = a->head;
	half_len = a->len / 2;
	cnt = 0;
	while (stack && cnt <= half_len)
	{
		if (stack->rank == max_rank)
			return (cnt);
		cnt++;
		stack = stack->next;
	}
	return (cnt);
}

int	cnt_from_bot(t_stack *a, int max_rank)
{
	t_node	*stack;
	int		cnt;
	int		half_len;

	stack = a->tail;
	half_len = a->len / 2;
	cnt = 0;
	while (stack && cnt < half_len)
	{
		if (stack->rank == max_rank)
			return (cnt + 1);
		cnt++;
		stack = stack->prev;
	}
	return (cnt + 1);
}

void	rotate_max_rank_to_top(t_stack *s, int max_rank, int command)
{
	while (s->head->rank != max_rank)
		operation(s, s, command);
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
