/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:58:13 by jjin              #+#    #+#             */
/*   Updated: 2023/03/17 20:19:52 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main (void)
{
    FragTrap a;
    FragTrap b("jjin");
    FragTrap c(b);
    FragTrap d = a;
    ClapTrap *x = new FragTrap("JJJJiIIIIN");


    a.printStatus();
    b.printStatus();
    c.printStatus();
    d.printStatus();

    d.attack("hi");
    d.beRepaired(10);
    d.takeDamage(1546);
    d.highFivesGuys();

    b.highFivesGuys();
    delete x;
}