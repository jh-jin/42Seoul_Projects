/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:36:53 by jjin              #+#    #+#             */
/*   Updated: 2023/05/10 20:46:06 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERASOURCE_HPP
# define MATERASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* slot[SLOT_SIZE];

	public:
		const AMateria *getAMateria(int idx) const;
		MateriaSource();
		MateriaSource(MateriaSource& other);
		MateriaSource& operator=(MateriaSource &other);

		~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif