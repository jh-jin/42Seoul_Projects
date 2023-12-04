/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:28:22 by jjin              #+#    #+#             */
/*   Updated: 2023/03/17 19:41:24 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(FRAG_NAME)
{   
    this->hp = FRAG_HP;
    this->ep = FRAG_EP;
    this->ad = FRAG_AD;
    std::cout << CLASSNAME << " " << this->name << ", Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hp = FRAG_HP;
    this->ep = FRAG_EP;
    this->ad = FRAG_AD;
    std::cout << CLASSNAME << " " << this->name << ", Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other.name)
{
    std::cout << CLASSNAME << " " << this->name << ", Copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << CLASSNAME << " " << this->name << ", Copy asignment operator function called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hp = other.hp;
        ep = other.ep;
        ad = other.ad;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << CLASSNAME << " " << this->name << ", Destructor called" << std::endl;
}


void ScavTrap::printStatus() const
{
    std::cout << "[[ " << CLASSNAME << " " << name << " ]] ep: " << ep << " hp: " << hp << std::endl;
}

void ScavTrap::checkToDie() const
{
    if (hp == 0)
    {
        std::cout << "~~~~~ " << CLASSNAME << " " << name << " died! ~~~~~" << std::endl;
        return ;
    }
}

int ScavTrap::canDo( std::string action ) const
{
    if (ep == 0 || hp == 0)
    {
        std::cout << "~~~~~ " << CLASSNAME << " " << name << " is dead ... cannot " << action << " ... ~~~~~" << std::endl;
        printStatus();
        return (0);
    }
    return (1);
}

void ScavTrap::attack(const std::string& target)
{
    if (!canDo("attack"))
        return ;
        
    ep--;

    std::cout << "~~~~~ " << CLASSNAME << " " << name << " attacks " << target << ", causing " << ad << " points of damage! ~~~~~" << std::endl;
    printStatus();
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (!canDo("takeDamage"))
        return ;

    amount = amount < hp ? amount : hp;
    hp -= amount;
    
    std::cout << "~~~~~ " << CLASSNAME << " " << name << " takes " << amount << " points of damage! ~~~~~" << std::endl;
    printStatus();
    
    checkToDie();
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (!canDo("beRepaired"))
        return ;

    hp += amount;
    ep--;
    
    std::cout << "~~~~~ " << CLASSNAME << " " << name << " is recovering " << amount << " points of hp! ~~~~~" << std::endl;
    printStatus();
}

void ScavTrap::guardGate()
{
    if (!canDo("guardGate"))
        return ;
    std::cout << "~~~~~ " << CLASSNAME << " " << name << " is now in Gate keeper mode! ~~~~~" << std::endl;
    printStatus();
}
