/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:15:10 by jjin              #+#    #+#             */
/*   Updated: 2023/03/17 20:10:08 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

# define CLASSNAMAE  "FragTrap"
# define FRAG_NAME  "fragtrap"
# define FRAG_HP    100
# define FRAG_EP    100
# define FRAG_AD    30

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();

        int canDo( std::string move ) const;
        void printStatus() const;
        void checkToDie() const;

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void highFivesGuys(void);
};

#endif