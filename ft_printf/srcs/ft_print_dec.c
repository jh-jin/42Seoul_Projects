/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:51:55 by jjin              #+#    #+#             */
/*   Updated: 2022/07/06 16:28:13 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(int d)
{
	int		len;
	char	*nptr;

	len = 0;
	nptr = ft_itoa(d);
	len = ft_print_str(nptr);
	free(nptr);
	return (len);
}
