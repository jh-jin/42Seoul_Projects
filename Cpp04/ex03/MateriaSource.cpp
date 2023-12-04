/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:36:51 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 21:05:42 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
# include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: Default Constructor called" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
		slot[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource& other) 
{
	std::cout << "MateriaSource: Copy Constructor called" << std::endl;
	*this = other;
}

MateriaSource& MateriaSource::operator=(MateriaSource &other) 
{
	const AMateria* otherAM;

	std::cout << "MateriaSource: Copy Assignment Operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot[i])
			delete slot[i];
		slot[i] = NULL;
		otherAM = other.getAMateria(i);
		if (otherAM)
			slot[i] = otherAM->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource() 
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot[i])
			delete slot[i];
		slot[i] = NULL;
	}
}

const AMateria *MateriaSource::getAMateria(int idx) const
{
	return slot[idx];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
			std::cout << "learnMateria [" << m->getType() << "] succeed" << std::endl;
			return ;
		}
	}
	std::cout << "the slot is full, \
	learnMateria [" << m->getType() << "] failed" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot[i] && slot[i]->getType() == type)
		{
			std::cout << "createMateria [" << type << "] succeed" << std::endl;
			return slot[i]->clone();
		}
	}
	std::cout << "the type is unknown, \
	createMateria [" << type << "] failed" << std::endl;
	return NULL;
}
