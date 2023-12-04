/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:14:57 by jjin              #+#    #+#             */
/*   Updated: 2023/04/20 18:47:43 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("RobotomyRequestForm", R_SIGN, R_EXEC), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", R_SIGN, R_EXEC), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), target(other.getTarget()) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) 
{
	if (this != &other) 
    {
		AForm::operator=(other);
        target = other.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const 
{ 
	return target;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const 
{
	if (!getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (getGradeToExec() < executor.getGrade()) {
		throw AForm::GradeTooLowException();
	}
    std::cout << "* drilling noises * " << std::endl;
    if (rand() % 2 == 0) {
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "Robotomy on " << this->getTarget() << " failed" << std::endl;
    }
}
