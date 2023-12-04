/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:49:20 by jjin              #+#    #+#             */
/*   Updated: 2022/11/15 21:42:02 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *a, t_stack *b, int argc, char **argv)
{
	init_s(a);
	init_s(b);
	push_all_to_a(a, argc, argv);
}

long long	ft_atoll(char *str)
{
	long long	num;
	int			neg;

	neg = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		if ((num > INT_MAX) && (neg == 1))
			ft_exit("Error\n");
		if ((num > (long long)INT_MAX + (long long)1) && (neg == -1))
			ft_exit("Error\n");
	}
	return (num * neg);
}

void	init_s(t_stack *s)
{
	s->head = NULL;
	s->tail = NULL;
	s->len = 0;
}

void	push_all_to_a(t_stack *a, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
		push_new(a, ft_atoll(argv[i++]));
}

void	push_new(t_stack *a, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_exit("Error\n");
	new->rank = 0;
	new->val = num;
	new->prev = NULL;
	new->next = NULL;
	push_rear(a, new);
}
