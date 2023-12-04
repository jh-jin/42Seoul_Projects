/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:09:15 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 17:21:30 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 5

int main ( void )
{
    Zombie *zombies = zombieHorde(N, "Zomzom");

    for (int i = 0; i < N; i++)
        zombies[i].announce();

    delete[] zombies;
    return 0;
}