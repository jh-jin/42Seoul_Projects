/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:49:19 by jjin              #+#    #+#             */
/*   Updated: 2023/06/21 20:49:20 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	(void)argc;
	try {
		exchangeBitcoin(argc > 1 ? argv[1]: "");
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}