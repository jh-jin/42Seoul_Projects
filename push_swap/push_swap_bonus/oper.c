/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:27:12 by jjin              #+#    #+#             */
/*   Updated: 2022/11/16 10:31:54 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (from->len == 0)
		return ;
	tmp = pop_front(from);
	push_front(to, tmp);
}

void	swap(t_stack *s)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (s->len < 2)
		return ;
	tmp1 = pop_front(s);
	tmp2 = pop_front(s);
	push_front(s, tmp1);
	push_front(s, tmp2);
}

void	rotate(t_stack *s)
{
	t_node	*tmp;

	if (s->len < 2)
		return ;
	tmp = pop_front(s);
	push_rear(s, tmp);
}

void	reverse_rotate(t_stack *s)
{
	t_node	*tmp;

	if (s->len < 2)
		return ;
	tmp = pop_rear(s);
	push_front(s, tmp);
}
