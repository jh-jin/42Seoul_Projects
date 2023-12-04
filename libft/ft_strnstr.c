/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:50:23 by jjin              #+#    #+#             */
/*   Updated: 2022/05/21 19:27:36 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	len_small;

	len_small = ft_strlen(small);
	if (!*small)
		return ((char *)big);
	while (*big && n-- >= len_small)
	{
		if (*big == *small && ft_memcmp(big, small, len_small) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
