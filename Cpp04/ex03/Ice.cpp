/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:36:43 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 19:54:53 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
# include "ICharacter.hpp"
# include <iostream>

Ice::Ice() : AMateria("Ice") 
{
	std::cout << "Ice: Default Constructor called" << std::endl;
}

Ice::Ice(Ice& other) : AMateria(other.getType()) 
{
	std::cout << "Ice: Copy Constructor called" << std::endl;
}

Ice& Ice::operator=(Ice &other)
{
	std::cout << "Ice: Copy Assignment Operator called" << std::endl;
	if (this != &other)
		type = other.getType();
	return *this;
}

Ice::~Ice() 
{
	std::cout << "Ice: Destructor called" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type) 
{
	std::cout << "Ice: Type Constructor called" << std::endl;	
}


AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}