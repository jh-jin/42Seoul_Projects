/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:46:05 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 17:33:57 by jjin             ###   ########.fr       */
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
        ~Zombie();

        void announce( void ) const;
        void setName ( std::string name );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif