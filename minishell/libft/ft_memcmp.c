/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:10 by jjin              #+#    #+#             */
/*   Updated: 2023/01/11 16:46:29 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s1_ptr;
	const unsigned char		*s2_ptr;

	if (n == 0)
		return (0);
	s1_ptr = (const unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	while (n)
	{
		if (*s1_ptr != *s2_ptr)
			return ((int)(*s1_ptr - *s2_ptr));
		s1_ptr++;
		s2_ptr++;
		n--;
	}
	return (0);
}
