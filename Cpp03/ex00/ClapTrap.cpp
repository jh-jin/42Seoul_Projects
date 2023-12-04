/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:58:37 by jjin              #+#    #+#             */
/*   Updated: 2023/03/17 12:43:25 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name(CLAP_NAME), hp(CLAP_HP), ep(CLAP_EP), ad(CLAP_AD)
{
    std::cout << "ClapTrap " << name << ", Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(CLAP_HP), ep(CLAP_EP), ad(CLAP_AD)
{
   	std::cout << "ClapTrap " << name << ", Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other) : name(other.name), hp(other.hp), ep(other.ep), ad(other.ad)
{
    std::cout << "ClapTrap " << name << ", Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other) 
{
    std::cout << "ClapTrap " << name << ", Copy asignment operator function called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hp = other.hp;
        this->ep = other.ep;
        this->ad = other.ad;
    }
    return (*this);
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << name << ", Destructor called" << std::endl;
}

void ClapTrap::printStatus() const
{
    std::cout << "[[ ClapTrap " << name << " ]] ep: " << ep << " hp: " << hp << std::endl;
}

void ClapTrap::checkToDie() const
{
    if (hp == 0)
    {
        std::cout << "~~~~~ ClapTrap " << name << " died! ~~~~~" << std::endl;
        return ;
    }
}

int ClapTrap::canDo( std::string action ) const
{
    if (ep == 0 || hp == 0)
    {
        std::cout << "~~~~~ ClapTrap " << name << " is dead ... " << " cannot " << action << " ... ~~~~~" << std::endl;
        printStatus();
        return (0);
    }
    return (1);
}

void ClapTrap::attack(const std::string& target)
{
    if (!canDo("attack"))
        return ;
        
    ep--;

    std::cout << "~~~~~ ClapTrap " << name << " attacks " << target << ", causing " << ad << " points of damage! ~~~~~" << std::endl;
    printStatus();
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!canDo("takeDamage"))
        return ;

    amount = amount < hp ? amount : hp;
    hp -= amount;
    
    std::cout << "~~~~~ ClapTrap " << name << " takes " << amount << " points of damage! ~~~~~" << std::endl;
    printStatus();
    
    checkToDie();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!canDo("beRepaired"))
        return ;

    hp += amount;
    ep--;
    
    std::cout << "~~~~~ ClapTrap " << name << " is recovering " << amount << " points of hp! ~~~~~" << std::endl;
    printStatus();
}