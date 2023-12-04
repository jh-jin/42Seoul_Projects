/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:28:36 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 17:19:18 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    std::cout << "Cat: Default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat: Copy assignment operator function called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Meow!!" << std::endl;
}