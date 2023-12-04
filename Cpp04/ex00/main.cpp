/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:27:15 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 22:41:02 by jjin             ###   ########.fr       */
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
    Animal animal;
    Dog dog;
    Cat cat;
    std::cout << std::endl;

    std::cout << "Who are you? " << animal.getType() << std::endl;
    std::cout << "Who are you? " << dog.getType() << std::endl;
    std::cout << "Who are you? " << cat.getType() << std::endl;
    animal.makeSound();
    dog.makeSound();
    cat.makeSound(); //will output the cat sound!
    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;



    std::cout << std::endl;
    Animal animal_copy(animal);
    Dog dog_copy(dog);
    Cat cat_copy_oper;
    cat_copy_oper = cat;
    std::cout << std::endl;

    std::cout << "Who are you? " << animal_copy.getType() << std::endl;
    std::cout << "Who are you? " << dog_copy.getType() << std::endl;
    std::cout << "Who are you? " << cat_copy_oper.getType() << std::endl;
    animal_copy.makeSound();
    dog_copy.makeSound();
    cat_copy_oper.makeSound(); //will output the cat sound!
    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;



    std::cout << std::endl;
    const Animal* animal_new = new Animal();
    const Animal* dog_new = new Dog();
    const Animal* cat_new = new Cat();
    std::cout << std::endl;

    std::cout << "Who are you? " << animal_new->getType() << std::endl;
    std::cout << "Who are you? " << dog_new->getType() << std::endl;
    std::cout << "Who are you? " << cat_new->getType() << std::endl;
    animal_new->makeSound();
    dog_new->makeSound();
    cat_new->makeSound(); //will output the cat sound!
    std::cout << std::endl;
    
    delete animal_new;
    delete cat_new;
    delete dog_new;
    std::cout << std::endl;
    std::cout << std::endl;    
    std::cout << std::endl;
    




    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wi = new WrongCat();
    std::cout << std::endl;

    std::cout << "Who are you? " << wmeta->getType() << std::endl;
    std::cout << "Who are you? " << wi->getType() << std::endl;
    wmeta->makeSound();
    wi->makeSound(); //will output the cat sound!
    std::cout << std::endl;

    delete wmeta;
    delete wi;
    
    std::cout << std::endl;    
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}