/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:36:45 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 19:55:26 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice& other);
		Ice& operator=(Ice &other);
		~Ice();

		Ice(std::string const & type);
	
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif