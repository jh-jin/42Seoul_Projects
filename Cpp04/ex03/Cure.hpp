/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:36:41 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 19:48:15 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure& other);
		Cure& operator=(Cure &other);
		~Cure();

		Cure(std::string const & type);
	
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif