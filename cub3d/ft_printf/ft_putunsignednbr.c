/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigendnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:22:27 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:12:54 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ret_unsignedidx(unsigned long number, char num[], int *count)
{
	int	i;

	i = 0;
	while (number)
	{
		num[i++] = (number % 10) + '0';
		number /= 10;
		*count += 1;
	}
	return (i);
}

int	ft_putunsignednbr(unsigned int n)
{
	int				i;
	unsigned long	number;
	char			num[15];
	int				count;

	i = 0;
	count = 0;
	number = (unsigned long)n;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = ret_unsignedidx(number, num, &count);
	while (--i >= 0)
		write(1, &num[i], 1);
	return (count);
}
