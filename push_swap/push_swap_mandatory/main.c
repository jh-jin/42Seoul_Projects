/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:27:14 by jjin              #+#    #+#             */
/*   Updated: 2022/11/15 21:16:23 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

void	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0)
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(argv[i][j]))
				ft_exit("Error\n");
			j++;
		}
		i++;
		j = 0;
	}
}

void	normalize(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	i = a->head;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->val > j->val)
				i->rank++;
			else if (i->val < j->val)
				j->rank++;
			else
				ft_exit("Error\n");
			j = j->next;
		}
		i = i->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	check_input(argc, argv);
	init(&a, &b, argc, argv);
	normalize(&a);
	if (is_sorted(&a))
		ft_exit("");
	do_algorithm(&a, &b);
	exit(0);
}
