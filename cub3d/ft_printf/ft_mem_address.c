/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:23:14 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/21 17:00:05 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_print(unsigned long long nbr, char *base, int length, int *count)
{
	unsigned long long	*div;
	int					i;
	unsigned long long	notation;

	div = (unsigned long long *)malloc(sizeof(unsigned long long) * length);
	notation = 16;
	i = 0;
	while (nbr / notation != 0)
	{
		div[i++] = nbr % notation;
		nbr /= notation;
		*count += 1;
	}
	i--;
	*count += 1;
	write(1, &base[nbr], 1);
	while (i >= 0)
		write(1, &base[div[i--]], 1);
	free(div);
}

int	ft_mem_address(void *n)
{
	unsigned long long	tmp;
	int					i;
	int					count;

	i = 1;
	count = 0;
	tmp = (unsigned long long)n;
	while (tmp / 16 != 0)
	{
		tmp /= 16;
		i++;
	}
	write(1, "0x", 2);
	count += 2;
	hex_print((unsigned long long)n, "0123456789abcdef", i, &count);
	return (count);
}
