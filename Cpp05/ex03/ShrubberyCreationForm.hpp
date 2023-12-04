/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:14:42 by jjin              #+#    #+#             */
/*   Updated: 2023/04/20 18:47:19 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

# define S_SIGN 145
# define S_EXEC 137

class ShrubberyCreationForm : public AForm
{
    private:
        std::string         target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        std::string         getTarget() const;
        virtual void        execute(Bureaucrat const& executor) const;
};

#endif