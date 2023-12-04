/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:14:46 by jjin              #+#    #+#             */
/*   Updated: 2023/04/20 18:47:29 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", S_SIGN, S_EXEC), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", S_SIGN, S_EXEC), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), target(other.getTarget()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) 
{
	if (this != &other) 
    {
		AForm::operator=(other);
        target = other.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const 
{ 
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const 
{
	if (!getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (getGradeToExec() < executor.getGrade()) {
		throw AForm::GradeTooLowException();
	}
	std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
	if (ofs.fail()) {
		throw std::runtime_error("Failed to open file.\n");
	}
    ofs <<     "\t\t\t      *\n"
               "\t\t\t     ***\n"
               "\t\t\t    *****\n"
               "\t\t\t   *******\n"
               "\t\t\t  *********\n"
               "\t\t\t     ***\n"
               "\t\t\t     ***\n";
	ofs.close();
}
