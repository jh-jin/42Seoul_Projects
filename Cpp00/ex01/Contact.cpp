/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:59:13 by jjin              #+#    #+#             */
/*   Updated: 2023/03/14 23:23:13 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact() {}

// void Contact::SetFirstName(std::string first_name)
// {
//     first_name_ = first_name;
// }

// void Contact::SetLastName(std::string last_name)
// {
//     last_name_ = last_name;
// }

// void Contact::SetNickname(std::string nickname)
// {
//     nickname_ = nickname;
// }

// void Contact::SetPhoneNumber(std::string phone_number)
// {
//     phone_number_ = phone_number;
// }

// void Contact::SetDarkestSecret(std::string darkest_secret)
// {
//     darkest_secret_ = darkest_secret;
// }

void Contact::Set(int field, std::string content)
{
    if (field == FIRST_NAME)
        first_name_ = content;
    if (field == LAST_NAME)
        last_name_ = content;
    if (field == NICKNAME)
        nickname_ = content;
    if (field == PHONE_NUMBER)
        phone_number_ = content;
    if (field == DARKEST_SECRET)
        darkest_secret_ = content;
}

std::string Contact::GetFirstName(void) const
{
    return first_name_;
}

std::string Contact::GetLastName(void) const
{
    return last_name_;
}

std::string Contact::GetNickname(void) const
{
    return nickname_;
}

std::string Contact::GetPhoneNumber(void) const
{
    return phone_number_;
}

std::string Contact::GetDarkestSecret(void) const
{
    return darkest_secret_;
}

std::string Contact::Get(int field) const
{
    if (field == FIRST_NAME)
        return first_name_;
    if (field == LAST_NAME)
        return last_name_;
    if (field == NICKNAME)
        return nickname_;
    if (field == PHONE_NUMBER)
        return phone_number_;
    if (field == DARKEST_SECRET)
        return darkest_secret_;
    return 0;
}