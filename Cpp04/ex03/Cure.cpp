/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:36:39 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 19:53:40 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
# include "ICharacter.hpp"
# include <iostream>

Cure::Cure() : AMateria("Cure") 
{
	std::cout << "Cure: Default Constructor called" << std::endl;
}

Cure::Cure(Cure& other) : AMateria(other.getType()) 
{
	std::cout << "Cure: Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(Cure &other)
{
	std::cout << "Cure: Copy Assignment Operator called" << std::endl;
	if (this != &other)
		type = other.getType();
	return *this;
}

Cure::~Cure() 
{
	std::cout << "Cure: Destructor called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type) 
{
	std::cout << "Cure: Type Constructor called" << std::endl;	
}


AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
