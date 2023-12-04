/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:42 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/21 15:53:13 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ret_idx(long number, char num[], int *count)
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

int	ft_putnbr(int n)
{
	int		i;
	long	number;
	char	num[15];
	int		count;

	i = 0;
	count = 0;
	number = (long)n;
	if (n < 0)
	{
		write(1, "-", 1);
		number = (long)n * -1;
		count = 1;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = ret_idx(number, num, &count);
	while (--i >= 0)
		write(1, &num[i], 1);
	return (count);
}
