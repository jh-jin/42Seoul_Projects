/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:28:40 by jjin              #+#    #+#             */
/*   Updated: 2023/03/18 22:52:37 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;
    
    public:
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound() const;
        const Brain* getBrain() const;
};

#endif