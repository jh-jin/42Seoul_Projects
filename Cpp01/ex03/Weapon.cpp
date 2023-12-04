/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:06:43 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 20:07:50 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon( std::string type )
{
    this->type = type;
}

Weapon::~Weapon() {}

std::string Weapon::getType() const
{
    return type;
}

void Weapon::setType( std::string type )
{
    this->type = type;
}