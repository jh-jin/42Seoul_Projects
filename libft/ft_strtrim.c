/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:02:32 by jjin              #+#    #+#             */
/*   Updated: 2022/05/21 18:56:13 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		front;
	int		end;

	ret = NULL;
	if (s1 && set)
	{
		front = 0;
		end = ft_strlen((char *)s1);
		while (ft_strchr((char *)set, s1[front]) && front < end)
			front++;
		while (ft_strchr((char *)set, s1[end - 1]) && front < end)
			end--;
		ret = (char *)malloc(sizeof(char) * (end - front + 1));
		if (ret)
			ft_strlcpy(ret, (char *)&s1[front], end - front + 1);
	}
	return (ret);
}
