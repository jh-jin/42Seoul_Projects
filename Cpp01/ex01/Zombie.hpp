/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:46:05 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 17:17:04 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie();
        Zombie( std::string name );
        ~Zombie();

        void announce( void ) const;
        void setName( std::string name );
};

Zombie* zombieHorde( int N, std::string name );

#endif