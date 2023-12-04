/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:04 by jjin              #+#    #+#             */
/*   Updated: 2023/04/20 22:42:24 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n\n";
    std::cout << ">>>>>>>>>>>>>>>>>>>> Test 1:  Constructor <<<<<<<<<<<<<<<<<<<\n";

    Bureaucrat bBasic;
    std::cout << bBasic << std::endl;

    Bureaucrat bNameAndGrade("bNameAndGrade", 2);
    std::cout << bNameAndGrade << std::endl;

    Bureaucrat bCopy(bNameAndGrade);
    std::cout << bCopy << std::endl;

    bBasic = bNameAndGrade;
    std::cout << bBasic << std::endl;


    std::cout << "\n\n";
    std::cout << ">>>>>>>>>>>>>>>>>>>> Test 2:  Exception Handling <<<<<<<<<<<<<<<<<<<\n";
    
    try {
        Bureaucrat bHigherGrade("bHigherGrade", 0);
        std::cout << bHigherGrade << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat bLowerGrade("bLowerGrade", 151);
        std::cout << bLowerGrade << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}