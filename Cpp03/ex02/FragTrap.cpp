/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:23:01 by jjin              #+#    #+#             */
/*   Updated: 2023/03/17 20:06:04 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap(FRAG_NAME)
{   
    this->hp = FRAG_HP;
    this->ep = FRAG_EP;
    this->ad = FRAG_AD;
    std::cout << CLASSNAMAE << " " << this->name << ", Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hp = FRAG_HP;
    this->ep = FRAG_EP;
    this->ad = FRAG_AD;
    std::cout << CLASSNAMAE << " " << this->name << ", Name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other.name)
{
    std::cout << CLASSNAMAE << " " << this->name << ", Copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    std::cout << CLASSNAMAE << " " << this->name << ", Copy asignment operator function called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hp = other.hp;
        ep = other.ep;
        ad = other.ad;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << CLASSNAMAE << " " << this->name << ", Destructor called" << std::endl;
}


void FragTrap::printStatus() const
{
    std::cout << "[[ " << CLASSNAMAE << " " << name << " ]] ep: " << ep << " hp: " << hp << std::endl;
}

void FragTrap::checkToDie() const
{
    if (hp == 0)
    {
        std::cout << "~~~~~ " << CLASSNAMAE << " " << name << " died! ~~~~~" << std::endl;
        return ;
    }
}

int FragTrap::canDo( std::string action ) const
{
    if (ep == 0 || hp == 0)
    {
        std::cout << "~~~~~ " << CLASSNAMAE << " " << name << " is dead ... cannot " << action << " ... ~~~~~" << std::endl;
        printStatus();
        return (0);
    }
    return (1);
}

void FragTrap::attack(const std::string& target)
{
    if (!canDo("attack"))
        return ;
        
    ep--;

    std::cout << "~~~~~ " << CLASSNAMAE << " " << name << " attacks " << target << ", causing " << ad << " points of damage! ~~~~~" << std::endl;
    printStatus();
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (!canDo("takeDamage"))
        return ;

    amount = amount < hp ? amount : hp;
    hp -= amount;
    
    std::cout << "~~~~~ " << CLASSNAMAE << " " << name << " takes " << amount << " points of damage! ~~~~~" << std::endl;
    printStatus();
    
    checkToDie();
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (!canDo("beRepaired"))
        return ;

    hp += amount;
    ep--;
    
    std::cout << "~~~~~ " << CLASSNAMAE << " " << name << " is recovering " << amount << " points of hp! ~~~~~" << std::endl;
    printStatus();
}

void FragTrap::highFivesGuys(void)
{
    if (!canDo("highFiveGuys"))
        return ;
    std::cout << "~~~~~ " << CLASSNAMAE << " " << name << " makes high five guys! ~~~~~" << std::endl;
    printStatus();
}
