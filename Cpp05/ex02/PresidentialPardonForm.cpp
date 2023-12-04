/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:14:50 by jjin              #+#    #+#             */
/*   Updated: 2023/04/20 18:47:48 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("PresidentialPardonForm", P_SIGN, P_EXEC), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", P_SIGN, P_EXEC), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), target(other.getTarget()) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) 
{
	if (this != &other) 
    {
		AForm::operator=(other);
        target = other.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const
{ 
	return target;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const 
{
	if (!getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (getGradeToExec() < executor.getGrade()) {
		throw AForm::GradeTooLowException();
	}
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
