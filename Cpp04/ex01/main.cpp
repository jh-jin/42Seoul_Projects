/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:27:15 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 23:02:35 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;
    delete i;
    delete j;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    Dog d;
    Cat c;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Dog d_copy(d);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Cat c_op;
    c_op = c;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}