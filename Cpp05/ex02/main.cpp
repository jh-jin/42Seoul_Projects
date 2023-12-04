/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:04 by jjin              #+#    #+#             */
/*   Updated: 2023/04/24 18:15:16 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "\n\n";
    std::cout << ">>>>>>>>>>>>>>>>>>>> Test 1:  ShrubberyCreationForm <<<<<<<<<<<<<<<<<<<\n";
    std::cout << "\n----------------- valid -----------------\n";
    {
        ShrubberyCreationForm scf("home");
        Bureaucrat          jjin("jjin", 3);

        jjin.signForm(scf);
        jjin.executeForm(scf);
    }
    std::cout << "\n----------------- excute invalid -----------------\n";
    {
        ShrubberyCreationForm scf("home");
        Bureaucrat          jjin("jjin", 140);

        jjin.signForm(scf);
        jjin.executeForm(scf);
    }
    std::cout << "\n----------------- sign invalid -----------------\n";
    {
        ShrubberyCreationForm scf("home");
        Bureaucrat          jjin("jjin", 146);

        jjin.signForm(scf);
        jjin.executeForm(scf);
    }

    std::cout << "\n\n";
    std::cout << ">>>>>>>>>>>>>>>>>>>> Test 2:  RobotomyRequestForm <<<<<<<<<<<<<<<<<<<\n";
    std::cout << "\n----------------- valid -----------------\n";
    {
        RobotomyRequestForm rrf("r2b2");
        Bureaucrat          jjin("jjin", 3);

        jjin.signForm(rrf);
        jjin.executeForm(rrf);
    }
    std::cout << "\n----------------- excute invalid -----------------\n";
    {
        RobotomyRequestForm rrf("r2b2");
        Bureaucrat          jjin("jjin", 55);

        jjin.signForm(rrf);
        jjin.executeForm(rrf);
    }
    std::cout << "\n----------------- sign invalid -----------------\n";
    {
        RobotomyRequestForm rrf("r2b2");
        Bureaucrat          jjin("jjin", 130);

        jjin.signForm(rrf);
        jjin.executeForm(rrf);
    }

    std::cout << "\n\n";
    std::cout << ">>>>>>>>>>>>>>>>>>>> Test 3:  PresidentialPardonForm <<<<<<<<<<<<<<<<<<<\n";
    std::cout << "\n----------------- valid -----------------\n";
    {
        PresidentialPardonForm ppf("citizen");
        Bureaucrat          jjin("jjin", 3);

        jjin.signForm(ppf);
        jjin.executeForm(ppf);
    }
    std::cout << "\n----------------- excute invalid -----------------\n";
    {
        PresidentialPardonForm ppf("citizen");
        Bureaucrat          jjin("jjin", 24);

        jjin.signForm(ppf);
        jjin.executeForm(ppf);
    }
    std::cout << "\n----------------- sign invalid -----------------\n";
    {
        PresidentialPardonForm ppf("citizen");
        Bureaucrat          jjin("jjin", 130);

        jjin.signForm(ppf);
        jjin.executeForm(ppf);
    }

    return 0;    
}
