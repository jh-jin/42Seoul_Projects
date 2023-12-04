/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:50:31 by jjin              #+#    #+#             */
/*   Updated: 2022/07/06 16:14:43 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_put_dec(unsigned int n)
{
	if (n >= 10)
	{
		ft_put_dec(n / 10);
		ft_put_dec(n % 10);
	}
	else
		ft_print_char('0' + n);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (!n)
		len += write(1, "0", 1);
	else
	{
		ft_put_dec(n);
		len += ft_dec_len(n);
	}
	return (len);
}
