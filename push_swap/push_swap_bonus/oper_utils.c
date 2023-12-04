/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:35:22 by jjin              #+#    #+#             */
/*   Updated: 2022/11/15 23:45:02 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
