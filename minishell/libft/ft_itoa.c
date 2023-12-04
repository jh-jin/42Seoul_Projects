/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:43:09 by jjin              #+#    #+#             */
/*   Updated: 2023/01/11 16:46:29 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_size(int n)
{
	if (n == 0)
		return (0);
	return (1 + calc_size(n / 10));
}

static char	*put_data(char *result, unsigned int n, int index)
{
	if (n > 0)
	{
		result[index] = (n % 10) + '0';
		put_data(result, n / 10, index - 1);
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;

	len = calc_size(n);
	if (n <= 0)
		len++;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		put_data(result, -n, len - 1);
	}
	else if (n == 0)
		result[0] = '0';
	else
		put_data(result, n, len - 1);
	result[len] = '\0';
	return (result);
}
