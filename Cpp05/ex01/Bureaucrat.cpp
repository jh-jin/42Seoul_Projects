/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:22:57 by jjin              #+#    #+#             */
/*   Updated: 2023/04/19 19:00:03 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()), grade(other.getGrade())
{
    if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat&         Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        *(const_cast<std::string*>(&name)) = other.getName();
        grade = other.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string   Bureaucrat::getName() const
{
    return name;
}

int                 Bureaucrat::getGrade() const
{
    return grade;
}

void                Bureaucrat::incGrade()
{
    if (grade == HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}

void                Bureaucrat::decGrade()
{
    if (grade == LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

void                Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch(const std::exception& e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName() 
        << " because Bureaucrat " << e.what() << "." << std::endl;
    }
}

std::ostream&       operator<<(std::ostream &o, const Bureaucrat& obj)
{
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return o;
}