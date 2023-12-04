/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:03:44 by jjin              #+#    #+#             */
/*   Updated: 2023/06/21 20:26:00 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	std::vector<int> input;
	time_t start, end;
	double result;

	if (argc == 1) {
		std::cout << "Error: no input" << std::endl;
		return 0;
	}
	try {
		input = checkInput(argc, argv);
		std::cout << "Before: ";
		printContainer(input);
		std::cout << " \n-------------------------------------------------------\n\n";
		std::cout << "After (std::vector):  ";
		printContainer(vecFordJohnson(input));
		std::cout << " \n-------------------------------------------------------\n\n";
		std::cout << "After (std::list):  ";
		printContainer(listFordJohnson(input));
		
		start = clock();
		vecFordJohnson(input);
		end = clock();
		result = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << result << "ms" << std::endl;
		
		start = clock();
		listFordJohnson(input);
		end = clock();
		result = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time to process a range of " << input.size() << " elements with std::list : " << result << "ms" << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}