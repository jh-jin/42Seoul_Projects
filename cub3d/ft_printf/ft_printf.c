/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:16:51 by wonljeon          #+#    #+#             */
/*   Updated: 2022/12/12 17:14:10 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_next(const char *save, va_list ap, int *count, int i)
{
	if (save[i] == '%' && save[i + 1])
	{
		if (save[++i] == 'c')
			*count += ft_putchar((char)va_arg(ap, char *));
		else if (save[i] == 's')
			*count += ft_putstr((char *)va_arg(ap, char *));
		else if (save[i] == 'p')
			*count += ft_mem_address((void *)va_arg(ap, char *));
		else if (save[i] == 'd' || save[i] == 'i')
			*count += ft_putnbr((int)va_arg(ap, char *));
		else if (save[i] == 'u')
			*count += ft_putunsignednbr((unsigned int)va_arg(ap, char *));
		else if (save[i] == 'x')
			*count += ft_low_x((unsigned int)va_arg(ap, char *));
		else if (save[i] == 'X')
			*count += ft_high_x((unsigned int)va_arg(ap, char *));
		else if (save[i] == '%')
		{
			write(1, "%", 1);
			*count += 1;
		}
	}
	else
		*count += ft_putchar(save[i]);
	return (i);
}

int	ret_count(const char *save, va_list ap)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (save[i])
	{
		i = find_next(save, ap, &count, i);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, str);
	count += ret_count(str, ap);
	va_end(ap);
	return (count);
}
