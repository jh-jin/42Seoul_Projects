/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:58:11 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 21:31:02 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>

void test_normal(void) 
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "1 -----------------------------------------------" << std::endl;

	ICharacter* jjin = new Character("jjin");

	AMateria* tmp;
	tmp = src->createMateria("Ice");
	jjin->equip(tmp);
	tmp = src->createMateria("Cure");
	jjin->equip(tmp);

	std::cout << "2 -----------------------------------------------" << std::endl;

	ICharacter* jjap = new Character("jjap");
	jjin->use(0, *jjap);
	jjin->use(1, *jjap);

	std::cout << "3 -----------------------------------------------" << std::endl;

	delete jjap;
	delete jjin;
	delete src;
}

void test_other(void) 
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(NULL);

	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << "1 -----------------------------------------------" << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("Fire");

	ICharacter* jjin = new Character("jjin");
	ICharacter* jjap = new  Character("jjap");

	jjin->unequip(0);

	std::cout << "2 -----------------------------------------------" << std::endl;

	tmp = src->createMateria("Ice");
	jjin->equip(tmp);
	tmp = src->createMateria("Cure");
	jjin->equip(tmp);
	
	std::cout << "3 -----------------------------------------------" << std::endl;

	AMateria* tmp1 = src->createMateria("Ice");
	jjin->equip(tmp1);
	AMateria* tmp2 = src->createMateria("Cure");
	jjin->equip(tmp);

	jjin->unequip(2);
	jjin->unequip(3);
	jjin->unequip(4);

	jjap->equip(tmp1);
	jjap->equip(tmp2);

	std::cout << "4 -----------------------------------------------" << std::endl;

	jjin->use(0, *jjap);
	jjin->use(1, *jjap);

	jjap->use(0, *jjin);
	jjap->use(1, *jjin);

	std::cout << "5 -----------------------------------------------" << std::endl;

	delete jjap;
	delete jjin;
	delete src;
}

int main(void) 
{
	test_normal();
	std::cout << "===============================================================" << std::endl;
	test_other();
	return 0;
}
