/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:28:36 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 23:05:23 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(NULL)
{
    std::cout << "Cat: Default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(), brain(NULL)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    type = other.getType();
    brain = new Brain(*(other.getBrain()));
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat: Copy assignment operator function called" << std::endl;
    if (this != &other)
    {
        type = other.getType();
        *(brain) = *(other.getBrain());
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Bowwow!!" << std::endl;
}

const Brain* Cat::getBrain() const
{
    return (brain);
}