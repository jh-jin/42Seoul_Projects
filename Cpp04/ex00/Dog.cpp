/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:28:38 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 17:18:42 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    std::cout << "Dog: Default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog: Copy assignment operator function called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: Bowwow!!" << std::endl;
}