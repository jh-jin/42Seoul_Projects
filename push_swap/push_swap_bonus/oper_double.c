/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:47:58 by jjin              #+#    #+#             */
/*   Updated: 2022/11/15 22:51:15 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_double(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate_double(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate_double(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
