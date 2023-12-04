/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:59:35 by jjin              #+#    #+#             */
/*   Updated: 2023/03/16 16:22:02 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    rawBits = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        rawBits = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (rawBits);
}

void Fixed::setRawBits( int const raw )
{
    rawBits = raw;
}

/*----------------------------------------------------------------------------*/

float Fixed::toFloat( void ) const
{
    return ((float)rawBits / (1 << numOfFractionalBits));
}

int Fixed::toInt( void ) const
{
    return (rawBits >> numOfFractionalBits);
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    rawBits = number << numOfFractionalBits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    rawBits = roundf(number * (1 << numOfFractionalBits));
}

std::ostream &operator<<(std::ostream &o, const Fixed &obj)
{
    return (o << obj.toFloat());
}
