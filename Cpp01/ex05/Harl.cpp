/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:10:45 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 23:26:25 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string LevelStr[4] =
{
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
};

const char *Message[4] =
{
    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!",
    "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!",
    "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.",
    "This is unacceptable! I want to speak to the manager now.",
};

void Harl::debug( void )
{
    std::cout << Message[DEBUG] << std::endl;
}

void Harl::info( void )
{
    std::cout << Message[INFO] << std::endl;
}

void Harl::warning( void )
{
    std::cout << Message[WARNING] << std::endl;
}

void Harl::error( void )
{
    std::cout << Message[ERROR] << std::endl;
}

void Harl::complain( std::string level )
{
    void (Harl::*func[4])(void) = 
    {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error
    };
    
    for (int i = 0; i < 5; i++)
    {
        if (level == LevelStr[i])
        {
            (this->*func[i])();
            return ;
        }
    }
}