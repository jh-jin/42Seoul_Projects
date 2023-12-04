/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:35:22 by jjin              #+#    #+#             */
/*   Updated: 2022/11/14 20:49:55 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *s, t_node *new)
{
	if (!s || !new)
		return ;
	if (s->len == 0)
	{
		s->head = new;
		s->tail = new;
	}
	else
	{
		s->head->prev = new;
		new->next = s->head;
		s->head = new;
	}
	s->len++;
}

void	push_rear(t_stack *s, t_node *new)
{
	if (!s || !new)
		return ;
	if (s->len == 0)
	{
		s->head = new;
		s->tail = new;
	}
	else
	{
		s->tail->next = new;
		new->next = NULL;
		new->prev = s->tail;
		s->tail = new;
	}
	s->len++;
}

t_node	*pop_front(t_stack *s)
{
	t_node	*tmp;

	if (!s || s->len == 0)
		return (0);
	tmp = s->head;
	s->head = s->head->next;
	tmp->next = 0;
	tmp->prev = 0;
	if (s->len == 1)
		s->tail = 0;
	else
		s->head->prev = 0;
	s->len--;
	return (tmp);
}

t_node	*pop_rear(t_stack *s)
{
	t_node	*tmp;

	if (!s || s->len == 0)
		return (0);
	tmp = s->tail;
	s->tail = s->tail->prev;
	tmp->prev = 0;
	tmp->next = 0;
	if (s->len == 1)
	{
		s->head = 0;
		s->tail = 0;
	}
	else
		s->tail->next = 0;
	s->len--;
	return (tmp);
}

void	printf_command(int command)
{
	if (command == SA)
		write(1, "sa\n", 3);
	if (command == SB)
		write(1, "sb\n", 3);
	if (command == PA)
		write(1, "pa\n", 3);
	if (command == PB)
		write(1, "pb\n", 3);
	if (command == RA)
		write(1, "ra\n", 3);
	if (command == RB)
		write(1, "rb\n", 3);
	if (command == RRA)
		write(1, "rra\n", 4);
	if (command == RRB)
		write(1, "rrb\n", 4);
}
