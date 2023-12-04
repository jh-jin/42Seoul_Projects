/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:04 by jjin              #+#    #+#             */
/*   Updated: 2023/04/29 21:50:07 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    try
    {
        /*
        * valid
        */
        {
            Intern someRandomIntern;
            AForm* f;
            f = someRandomIntern.makeForm("robotomy request", "Bender");
            delete f;
        }
        /*
        * valid
        */
        {
            Intern someRandomIntern;
            AForm* f;
            f = someRandomIntern.makeForm("presidential pardon", "Bender");
            delete f;
        }
        /*
        * valid
        */
        {
            Intern someRandomIntern;
            AForm* f;
            f = someRandomIntern.makeForm("shrubbery creation", "Bender");
            delete f;
        }
        /*
        * invalid
        */
        {
            Intern someRandomIntern;
            AForm* nf;
            nf = someRandomIntern.makeForm("", "Bender");
            delete nf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
