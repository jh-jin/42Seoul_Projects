/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:59:35 by jjin              #+#    #+#             */
/*   Updated: 2023/03/16 16:44:09 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ex00 ---------------------------------------------------------------------*/
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

/* ex01 ---------------------------------------------------------------------*/

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

/* ex02 ---------------------------------------------------------------------*/

bool Fixed::operator>(const Fixed &obj) const
{
    return (rawBits > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
    return (rawBits < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return (rawBits >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (rawBits <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (rawBits == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (rawBits != obj.getRawBits());
}



Fixed Fixed::operator+(const Fixed &obj) const
{
    return (Fixed(toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    return (Fixed(toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    return (Fixed(toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    return (Fixed(toFloat() / obj.toFloat()));
}



Fixed& Fixed::operator++()
{
    rawBits++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    //Fixed ret = *this;
    rawBits++;
    return (ret);
}

Fixed& Fixed::operator--()
{
    rawBits--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    //Fixed ret = *this;
    rawBits--;
    return (ret);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

Fixed const& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

Fixed const& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}