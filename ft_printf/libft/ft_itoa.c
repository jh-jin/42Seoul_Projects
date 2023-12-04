/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:01:49 by jjin              #+#    #+#             */
/*   Updated: 2022/05/21 19:19:07 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int2char(char *tmp, int n)
{
	int	i;

	i = 0;
	while (n / 10)
	{
		if (n < 0)
			tmp[i++] = ((n % 10) * (-1)) + '0';
		else
			tmp[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (n < 0)
	{
		tmp[i++] = -n + '0';
		tmp[i] = '-';
	}
	else
		tmp[i] = n + '0';
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		j;
	char	tmp[100];

	j = 0;
	i = int2char(tmp, n);
	ret = (char *)malloc(i + 2);
	if (!ret)
		return (0);
	while (i >= 0)
		ret[j++] = tmp[i--];
	ret[j] = '\0';
	return (ret);
}
