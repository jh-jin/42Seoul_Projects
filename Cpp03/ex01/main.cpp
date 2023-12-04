/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:58:13 by jjin              #+#    #+#             */
/*   Updated: 2023/03/17 20:20:07 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
    ScavTrap a;
    ScavTrap b("jjin");
    ScavTrap c(b);
    ScavTrap d = a;

    a.printStatus();
    b.printStatus();
    c.printStatus();
    d.printStatus();

    d.attack("hi");
    d.beRepaired(10);
    d.takeDamage(1546);
    d.guardGate();

    b.guardGate();
}