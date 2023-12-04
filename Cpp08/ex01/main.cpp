/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:49:22 by jjin              #+#    #+#             */
/*   Updated: 2023/06/09 22:25:53 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::cout << "----------- random 20000 nums -----------" << '\n';
    {
        srand(time(NULL));
        Span span = Span(20000);
        for (int i = 0; i < 20000; ++i)
            span.addNumber(rand());

        std::cout << span.shortestSpan() << '\n';
        std::cout << span.longestSpan() << '\n';
    }

    std::cout << "------------ subject 5 nums ------------" << '\n';
    {
        Span span = Span(5);
        span.addNumber(6);
        span.addNumber(3);
        span.addNumber(17);
        span.addNumber(9);
        span.addNumber(11);
		
        std::cout << span.shortestSpan() << '\n';
        std::cout << span.longestSpan() << '\n';
    }

    std::cout << "-------- random argument vector -------" << '\n';
    {
        std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);

        Span span = Span(9);
        span.addNumber(6);
        span.addNumber(3);
        span.addNumber(17);
        span.addNumber(9);
        span.addNumber(11);

        span.addNumbers(v.begin(), v.end());
        std::cout << span.shortestSpan() << '\n';
        std::cout << span.longestSpan() << '\n';
    }

    std::cout << "--------- span full error --------" << '\n';
    {
        try
        {
            std::vector<int> v;
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);

            Span span = Span(7);
            span.addNumber(6);
            span.addNumber(3);
            span.addNumber(17);
            span.addNumber(9);
            span.addNumber(11);

            span.addNumbers(v.begin(), v.end());
            std::cout << span.shortestSpan() << '\n';
            std::cout << span.longestSpan() << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "--------- too few error -------" << '\n';
    {
        try
        {      
            Span span = Span(7);
            span.addNumber(11);

            std::cout << span.shortestSpan() << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		try
        {      
            Span span = Span(7);
            span.addNumber(11);

            std::cout << span.longestSpan() << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
