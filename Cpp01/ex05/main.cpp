/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:10:40 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 23:26:59 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ( void )
{
    Harl harl;

    harl.complain("DEBUG");
    std::cout << std::endl;

    harl.complain("INFO");
    std::cout << std::endl;

    harl.complain("WARNING");
    std::cout << std::endl;
    
    harl.complain("ERROR");
    std::cout << std::endl;

    return (0);
}