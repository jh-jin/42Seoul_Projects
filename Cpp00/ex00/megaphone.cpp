/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:43:43 by jjin              #+#    #+#             */
/*   Updated: 2023/03/14 23:43:52 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 0;
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
            std::cout << (char)std::toupper(argv[i][j]);
        std::cout << ' ';
    }
    std::cout << std::endl;
    return (0);
}