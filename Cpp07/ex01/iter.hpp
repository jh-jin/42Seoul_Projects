/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:15:40 by jjin              #+#    #+#             */
/*   Updated: 2023/05/30 22:51:07 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *addr, int len, void (*f)(T &))
{
	for (int i = 0; i < len; i++)
		f(addr[i]);
}

template <typename T>
void iter(T *addr, int len, void (*f)(T const &))
{
	for (int i = 0; i < len; i++)
		f(addr[i]);
}

#endif