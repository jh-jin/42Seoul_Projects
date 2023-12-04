/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:36:04 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 21:29:13 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
# include <iostream>

Character::Character() : name("") 
{
	std::cout << "Character: Default Constructor called" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
		slot[i] = NULL;
}

Character::Character(Character& other) : name(other.getName()) 
{
	std::cout << "Character: Copy Constructor called" << std::endl;
	*this = other;
}

Character& Character::operator=(Character& other) 
{
	const AMateria* otherAM;

	std::cout << "Character: Copy Assignment Operator called" << std::endl;
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

Character::~Character() 
{
	std::cout << "Character: Destructor called" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot[i])
			delete slot[i];
		slot[i] = NULL;
	}
}

Character::Character(std::string const & name) : name(name) 
{
	std::cout << "Character: Name Constructor called" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
		slot[i] = NULL;
}


AMateria const * Character::getAMateria(int idx) const 
{
	return slot[idx];
}

std::string const & Character::getName() const 
{
	return name;
}


void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
		    std::cout << "[" << name << "] equip succeed" << std::endl;
			return ;
		}
	}
	std::cout << "slot is full, [" << name << "] equip failed" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < SLOT_SIZE && slot[idx])
	{
		slot[idx] = NULL;
		std::cout << "[" << name << "] unequip succeed" << std::endl;
		return ;
	}
	std::cout << "empty or wrong slot, [" << name << "] unequip failed" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < SLOT_SIZE && slot[idx])
	{
		slot[idx]->use(target);
		return ;
	}
	std::cout << "empty or wrong slot, [" << name << "] use failed" << std::endl;
}