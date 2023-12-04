/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:03:44 by jjin              #+#    #+#             */
/*   Updated: 2023/06/21 20:44:11 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: invalid arguments" << std::endl;
		return 0;
	}
	try {
		rpn(argv[1]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}