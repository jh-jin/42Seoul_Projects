/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:35:58 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 20:05:53 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

# define SLOT_SIZE 4

class ICharacter;

class AMateria
{
	protected:
		std::string type;
		
	public:
		AMateria();
		AMateria(AMateria& other);
		AMateria& operator=(AMateria &other);
		virtual ~AMateria();

		AMateria(std::string const & type);
	
		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif