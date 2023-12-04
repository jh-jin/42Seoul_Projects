/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:18:54 by jjin              #+#    #+#             */
/*   Updated: 2023/03/14 23:23:18 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    읽기 전용 함수: 뒤에 const가 붙은 상수 함수는 멤버를 변경하지 못한다.
*/

#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

enum Field
{
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET,
};

static const char *FieldName[5] = {
	"first name",
	"last name",
	"nickname",
	"phone number",
	"darkest secret"
};

class Contact
{
    private:
        std::string first_name_;
        std::string last_name_;
        std::string nickname_;
        std::string phone_number_;
        std::string darkest_secret_;
        
    public:
        Contact();
        ~Contact();

        void SetFirstName(std::string first_name);
        void SetLastName(std::string last_name);
        void SetNickname(std::string nickname);
        void SetPhoneNumber(std::string phone_number);
        void SetDarkestSecret(std::string darkest_secret);
        void Set(int field, std::string content);

        std::string GetFirstName(void) const;
        std::string GetLastName(void) const;
        std::string GetNickname(void) const;
        std::string GetPhoneNumber(void) const;
        std::string GetDarkestSecret(void) const;
        std::string Get(int field) const;

};

#endif