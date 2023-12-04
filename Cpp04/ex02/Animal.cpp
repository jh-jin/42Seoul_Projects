/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:27:13 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 19:47:48 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal: Copy assignment operator function called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}