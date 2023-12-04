/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:13:02 by jjin              #+#    #+#             */
/*   Updated: 2022/05/21 18:25:49 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void				*ret;

	if (n / SIZE_MAX * size > 1)
		return (NULL);
	ret = (void *)malloc(n * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, n * size);
	return (ret);
}
