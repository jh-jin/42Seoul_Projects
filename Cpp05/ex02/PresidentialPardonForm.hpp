/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:14:52 by jjin              #+#    #+#             */
/*   Updated: 2023/04/20 18:46:39 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

# define P_SIGN 25
# define P_EXEC 5

class PresidentialPardonForm : public AForm
{
    private:
        std::string         target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        std::string         getTarget() const;
        virtual void        execute(Bureaucrat const& executor) const;
};

#endif