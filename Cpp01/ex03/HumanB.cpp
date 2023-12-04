/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:06:35 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 20:27:41 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB( std::string name ) : weapon(NULL)
{
    this->name = name;
}

HumanB::~HumanB() {}

void HumanB::setWeapon( Weapon& weapon )
{
    this->weapon = &weapon;
}

void HumanB::attack()
{    
    if (!weapon)
        std::cout << name << " has no weapon " << std::endl;
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}