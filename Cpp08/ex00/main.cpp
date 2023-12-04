/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:28:05 by jjin              #+#    #+#             */
/*   Updated: 2023/06/09 21:57:34 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <exception>
#include <array>

int main(void)
{
	std::array<int, 5> arr = {0, 1, 2, 3, 4};

	try {
		easyfind(arr, 0);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(arr, 5);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}