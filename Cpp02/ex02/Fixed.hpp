/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:35:10 by jjin              #+#    #+#             */
/*   Updated: 2023/03/16 16:40:00 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int rawBits;
		static const int numOfFractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
		Fixed(const int number);
		Fixed(const float number);

		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;

		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		// 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를 받지만 실제로는 아무것도 전달되지 않는다.
		Fixed& operator++(); // 전위: 연산 후 자신 반환
		Fixed operator++(int); // 후위: 연산 전 저장해둔 것 반환
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream &operator<<(std::ostream &o, const Fixed &obj);

#endif