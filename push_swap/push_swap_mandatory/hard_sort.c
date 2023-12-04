/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:23:11 by jjin              #+#    #+#             */
/*   Updated: 2022/11/14 23:47:50 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	len_three_sort(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(a))
		return ;
	top = a->head->rank;
	mid = a->head->next->rank;
	bot = a->head->next->next->rank;
	if (top < bot && top < mid)
	{
		operation(a, NULL, SA);
		operation(a, NULL, RA);
	}
	else if (mid < top && top < bot && mid < bot)
		operation(a, NULL, SA);
	else if (bot < top && top < mid && bot < mid)
		operation(a, NULL, RRA);
	else
	{
		operation(a, NULL, RA);
		if (bot < mid)
			operation(a, NULL, SA);
	}
}

void	len_four_sort(t_stack *a, t_stack *b)
{
	while (a->len > 3)
	{
		if (a->head->rank == 0)
			break ;
		else
			operation(a, b, RA);
	}
	operation(a, b, PB);
	len_three_sort(a);
	operation(a, b, PA);
}

void	len_five_sort(t_stack *a, t_stack *b)
{
	while (a->len > 3)
	{
		if (a->head->rank < 2)
			operation(a, b, PB);
		else
			operation(a, b, RA);
	}
	len_three_sort(a);
	operation(a, b, PA);
	operation(a, b, PA);
	if (a->head->rank != 0)
		operation(a, b, SA);
}
