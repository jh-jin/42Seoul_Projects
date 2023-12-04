/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:03:42 by jjin              #+#    #+#             */
/*   Updated: 2023/06/22 22:39:41 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void rpn(std::string str) {
	std::stringstream ss(str);
	std::stack<int> stk;
	std::string tkn;
	int val;

	while (ss >> tkn) {
		if (tkn == "+" || tkn == "-" || tkn == "/" | tkn == "*") {
			if (stk.size() < 2)
				throw std::runtime_error("Error: invalid expression.");
			
			int b = stk.top();	
			stk.pop();
			int a = stk.top();	
			stk.pop();
			
			switch (tkn[0]) {
				case '+':
					stk.push(a + b); 
					break;
				case '-':
					stk.push(a - b); 
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Error: cannot devide by zero");
					stk.push(a / b); 
					break;
				case '*':
					stk.push(a * b); 
					break;
			}
		}
		else if (tkn.length() == 1) {
			std::stringstream ssDegit(tkn);
			if (!(ssDegit >> val) || ssDegit.tellg() != -1)
				throw std::runtime_error("Error: stringstream error");
			if (val >= 10 || val < 0)
				throw std::runtime_error("Error: invalid number range");
			stk.push(val);
		}
		else
			throw std::runtime_error("Error: invalid input");
	}
	if (stk.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	std::cout << stk.top() << std::endl;
}