/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:05:28 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:56:59 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_lowhex(int length, unsigned int nbr, char *base, int *count)
{
	char	*result;
	int		i;
	int		range;

	range = length;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return ;
	i = 0;
	result[length] = '\0';
	length--;
	while (length >= 0)
	{
		result[length] = nbr % 16;
		nbr /= 16;
		*count += 1;
		length--;
	}
	while (i < range)
		write(1, &base[(int)result[i++]], 1);
	free(result);
}

int	ft_low_x(unsigned int nbr)
{
	unsigned long long	temp;
	int					i;
	int					count;

	count = 0;
	temp = nbr;
	i = 1;
	while (temp / 16 != 0)
	{
		i++;
		temp /= 16;
	}
	print_lowhex(i, nbr, "0123456789abcdef", &count);
	return (count);
}
