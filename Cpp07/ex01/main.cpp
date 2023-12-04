/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:24:42 by jjin              #+#    #+#             */
/*   Updated: 2023/05/30 22:51:21 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "iter.hpp"

class Awesome
{
    public:
        Awesome( void ) : _n( 42 ) { return; }
        int get( void ) const { return this->_n; }
    private:
        int _n;
};


std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

template <typename T>
void    increment(T &i) {
    i++;
}

int main(void) {

    int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];

    iter( tab, 5, print<int> );
    iter( tab2, 5, print<Awesome> );

    std::cout << "-------------------- my tests --------------------" << std::endl;

    int arrI[5] = {0, 1, 2, 3, 4};
    std::string arrS[3] = {"hello", "world", "!"};

    iter(arrI, 5, increment<int>);
    iter(arrI, 5, print<int>);
    iter(arrS, 3, print<std::string>);
    return 0;
}
