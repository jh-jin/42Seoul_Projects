/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:00:43 by jjin              #+#    #+#             */
/*   Updated: 2022/05/21 19:20:05 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcnt(char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}

char	**ft_free_dptr(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
		free(ret[i]);
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	*wordstart;
	char	**ret;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (ft_wordcnt((char *)s, c) + 1));
	if (!ret)
		return (NULL);
	ret[ft_wordcnt((char *)s, c)] = NULL;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		wordstart = (char *)s;
		while (*s && *s != c)
			s++;
		ret[i] = ft_substr(wordstart, 0, s - wordstart);
		if (!ret[i++])
			return (ft_free_dptr(ret));
	}
	return (ret);
}
