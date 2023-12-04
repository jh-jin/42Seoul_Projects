/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:27:15 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 19:48:51 by jjin             ###   ########.fr       */
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
    //const Animal a;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;
    //a->makeSound();
    j->makeSound();
    i->makeSound();
    delete i;
    delete j;
    std::cout << std::endl;

    return 0;
}