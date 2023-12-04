/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:19:04 by jjin              #+#    #+#             */
/*   Updated: 2023/03/14 23:23:23 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>

class PhoneBook
{
    private:
        int contact_cnt_;
        Contact contacts_[8];
        std::string readline_() const;
        std::string resizing_(std::string str) const;
        void display_summary_() const;
        void display_detail_(int idx) const;
        void add_field_(int idx, int field, std::string input);
        void add_contact_();
        void search_contact_() const;

    public:
        PhoneBook();
        ~PhoneBook();
        
        void run();
};

#endif