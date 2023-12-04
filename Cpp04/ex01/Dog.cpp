/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:28:36 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 22:58:08 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain(NULL)
{
    std::cout << "Dog: Default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(), brain(NULL)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    type = other.getType();
    brain = new Brain(*(other.getBrain()));
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog: Copy assignment operator function called" << std::endl;
    if (this != &other)
    {
        type = other.getType();
        *(brain) = *(other.getBrain());
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Dog: Bowwow!!" << std::endl;
}

const Brain* Dog::getBrain() const
{
    return (brain);
}