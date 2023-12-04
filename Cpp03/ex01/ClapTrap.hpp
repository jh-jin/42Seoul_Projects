/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:58:23 by jjin              #+#    #+#             */
/*   Updated: 2023/03/17 20:14:41 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

// # define CLASSNAME   "ClapTrap"
# define CLAP_NAME  "claptrap"
# define CLAP_HP    10
# define CLAP_EP    10
# define CLAP_AD    0

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hp;
        unsigned int ep;
        unsigned int ad;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        virtual ~ClapTrap();

        int canDo( std::string move ) const;
        void printStatus() const;
        void checkToDie() const;

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif