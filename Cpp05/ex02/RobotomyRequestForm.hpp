/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:14:55 by jjin              #+#    #+#             */
/*   Updated: 2023/04/20 18:47:14 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

# define R_SIGN 72
# define R_EXEC 45

class RobotomyRequestForm : public AForm
{
    private:
        std::string         target;
    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        std::string         getTarget() const;
        virtual void        execute(Bureaucrat const& executor) const;
};

#endif