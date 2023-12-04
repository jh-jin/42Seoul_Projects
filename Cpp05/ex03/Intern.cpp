/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:01:06 by jjin              #+#    #+#             */
/*   Updated: 2023/04/29 21:47:06 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char* Intern::UnknownFormTypeException::what() const throw()
{
    return "Unknown Form Type";
}

Intern::Intern() {}

Intern::Intern(const Intern& other) 
{
	*this = other;
}

Intern&         Intern::operator=(const Intern& other)
{
	(void) other;
    return *this;
}

Intern::~Intern() {}

AForm*   Intern::makeForm(const std::string& formName, const std::string& target)
{
    const	std::string formTypeTable[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int		formTypeIdx = -1;
	AForm	*form;

	for (int i = 0; i < 3; i++)
	{
		if (formName == formTypeTable[i])
		{
			formTypeIdx = i;
			break;
		}
	}
	
	switch (formTypeIdx)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::UnknownFormTypeException();
	}
	std::cout << "Intern creates " << formName << std::endl;
	return form;
}