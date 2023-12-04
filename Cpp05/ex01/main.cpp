/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:04 by jjin              #+#    #+#             */
/*   Updated: 2023/04/20 22:12:46 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    std::cout << "\n\n";
    std::cout << ">>>>>>>>>>>>>>>>>>>> Test 1:  Constructor <<<<<<<<<<<<<<<<<<<\n";

    Form fBasic;
    std::cout << fBasic << std::endl;

    Form fNameAndGrade("fNameAndGrade", 150, 1);
    std::cout << fNameAndGrade << std::endl;

    Form fCopy(fNameAndGrade);
    std::cout << fCopy << std::endl;

    fBasic = fNameAndGrade;
    std::cout << fBasic << std::endl;

    std::cout << "\n\n";
    std::cout << ">>>>>>>>>>>>>>>>>>>> Test 2:  Exception Handling <<<<<<<<<<<<<<<<<<<\n";

    std::cout << "\n----------------- invalid -----------------\n";
    try {
        Form fHigherGrade("fHigherGrade", 0, 1);
        std::cout << fHigherGrade << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------------- invalid -----------------\n";
    try {
        Form fLowerGrade("fLowerGrade", 1, 151);
        std::cout << fLowerGrade << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------------- valid -----------------\n";
    {
        Form f1("f1", 1, 150);
        Bureaucrat b1("b1", 1);
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    std::cout << "\n----------------- invalid -----------------\n";
    {
        Form f1("f1", 1, 150);
        Bureaucrat b2("b2", 2);
        b2.signForm(f1);
        std::cout << f1 << std::endl;
    }
}