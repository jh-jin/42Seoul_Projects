/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:28:25 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 15:06:36 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : type("") 
{
	std::cout << "AMateria: Default Constructor called" << std::endl;
}

AMateria::AMateria(AMateria& other) : type(other.getType()) 
{
	std::cout << "AMateria: Copy Constructor called" << std::endl;
}

AMateria& AMateria::operator=(AMateria &other) 
{
	std::cout << "AMateria: Copy Assignment Operator called" << std::endl;
	if (this != &other)
		type = other.getType();
	return *this;
}

AMateria::~AMateria() 
{
	std::cout << "AMateria: Destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) 
{
	std::cout << "AMateria: Type Constructor called" << std::endl;	
}

std::string const & AMateria::getType() const 
{
	return type;
}

void AMateria::use(ICharacter& target) 
{
	std::cout << "AMateria: use Function called on target: \
	[" << target.getName() << "]" << std::endl;	
}