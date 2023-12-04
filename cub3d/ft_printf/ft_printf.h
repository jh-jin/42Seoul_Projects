/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:07:48 by wonljeon          #+#    #+#             */
/*   Updated: 2022/12/12 17:09:44 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
int		ret_count(const char *save, va_list ap);
int		find_next(const char *save, va_list ap, int *count, int i);
int		ft_high_x(unsigned int nbr);
void	print_highhex(int length, unsigned int nbr, char *base, int *count);
int		ft_low_x(unsigned int nbr);
void	print_lowhex(int length, unsigned int nbr, char *base, int *count);
int		ft_mem_address(void *n);
void	hex_print(unsigned long long nbr, char *base, int length, int *count);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ret_idx(long number, char num[], int *count);
int		ft_putstr(char *str);
size_t	ft_strlen2(char *str);
int		ft_putunsignednbr(unsigned int n);
int		ret_unsignedidx(unsigned long number, char num[], int *count);
#endif
