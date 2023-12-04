/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:36:26 by jjin              #+#    #+#             */
/*   Updated: 2023/04/19 19:00:05 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form Is Not Signed";
}

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExec(150) {}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExec) : 
name(name),
isSigned(false),
gradeToSign(gradeToSign),
gradeToExec(gradeToExec)
{
    if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
name(other.getName()), 
isSigned(other.getIsSigned()),
gradeToSign(other.getGradeToSign()), 
gradeToExec(other.getGradeToExec())
{
    if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
}

AForm&         AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        *(const_cast<std::string*>(&name)) = other.getName();
        isSigned = other.getIsSigned();
        *(const_cast<int*>(&gradeToSign)) = other.getGradeToSign();
        *(const_cast<int*>(&gradeToExec)) = other.getGradeToExec();
    }
    return *this;
}

AForm::~AForm() {}

const std::string   AForm::getName() const
{
    return name;
}

bool                AForm::getIsSigned() const
{
    return isSigned;
}

int                 AForm::getGradeToSign() const
{
    return gradeToSign;
}

int                AForm::getGradeToExec() const
{
    return gradeToExec;
}

void                AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

std::ostream&       operator<<(std::ostream &o, const AForm& obj)
{
    o << "AForm - name:" << obj.getName() << ", isSigned: " << obj.getIsSigned() 
    << ", gradeToSign: " << obj.getGradeToSign() << ", gradeToExec: " << obj.getGradeToExec();
    return o;
}