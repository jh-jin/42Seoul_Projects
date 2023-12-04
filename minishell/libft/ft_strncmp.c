/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:34:54 by jjin              #+#    #+#             */
/*   Updated: 2023/01/11 16:46:29 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_temp;
	const unsigned char	*s2_temp;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	s1_temp = (const unsigned char *)s1;
	s2_temp = (const unsigned char *)s2;
	while (*s1_temp != '\0' && *s2_temp != '\0' && i < n)
	{
		if (*s1_temp != *s2_temp)
			return (*s1_temp - *s2_temp);
		s1_temp++;
		s2_temp++;
		i++;
	}
	if (i == n)
	{
		s1_temp--;
		s2_temp--;
	}
	return (*s1_temp - *s2_temp);
}
