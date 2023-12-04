/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:29:39 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 17:53:20 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ( void )
{
    Zombie *zombie;

    randomChump("Foo");
    zombie = newZombie("Bar");
    zombie->announce();
    
    delete zombie;
    return 0;
}