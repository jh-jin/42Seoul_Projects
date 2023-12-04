/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:22:51 by jjin              #+#    #+#             */
/*   Updated: 2023/03/14 23:29:59 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
    contact_cnt_ = 0;
}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::readline_() const
{
    std::string line;

    std::getline(std::cin, line);
    if (std::cin.eof() || std::cin.fail())
	{
		std::cout << std::endl << "Error Ocurred, Exit!" << std::endl;
		exit(1);
	}
	return line;
}

void PhoneBook::add_field_(int idx, int field, std::string input)
{
	contacts_[idx].Set(field, input);
}

void PhoneBook::add_contact_()
{
	std::string input;
	int idx;
	
	idx = contact_cnt_ % 8;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter " << FieldName[i] << ": ";
		try
		{
			input = readline_();
			if (input.length() == 0 || std::cin.eof() || input == "")
				throw std::exception();
			if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != std::string::npos)
				throw std::exception();
			add_field_(idx, i, input);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: Invalid Input!" << '\n';
			i--;
		}
	}
	contact_cnt_++;
}

std::string PhoneBook::resizing_(std::string str) const
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return str;
}

void PhoneBook::display_summary_() const
{
	std::cout << "|" << std::setw(10) << std::right << "Index";
	std::cout << "|" << std::setw(10) << std::right << FieldName[FIRST_NAME];
	std::cout << "|" << std::setw(10) << std::right << FieldName[LAST_NAME];
	std::cout << "|" << std::setw(10) << std::right << FieldName[NICKNAME] << "|" << std::endl;

	for (int idx = 0; idx < contact_cnt_ && idx < 8; idx++)
	{
		std::cout << "|" << std::setw(10) << std::right << idx;
		std::cout << "|" << std::setw(10) << std::right << resizing_(contacts_[idx].Get(FIRST_NAME));
		std::cout << "|" << std::setw(10) << std::right << resizing_(contacts_[idx].Get(LAST_NAME));
		std::cout << "|" << std::setw(10) << std::right << resizing_(contacts_[idx].Get(NICKNAME)) << "|" << std::endl;
	}
}

void PhoneBook::display_detail_(int idx) const
{
	Contact contact;

	contact = contacts_[idx];

	std::cout << FieldName[FIRST_NAME] << ": " << contact.GetFirstName() << std::endl;
	std::cout << FieldName[LAST_NAME] << ": " << contact.GetLastName() << std::endl;
	std::cout << FieldName[NICKNAME] << ": " << contact.GetNickname() << std::endl;
	std::cout << FieldName[PHONE_NUMBER] << ": " << contact.GetPhoneNumber() << std::endl;
	std::cout << FieldName[DARKEST_SECRET] << ": " << contact.GetDarkestSecret() << std::endl;
}

void PhoneBook::search_contact_() const
{
	std::string input;
	int idx;

	display_summary_();
	std::cout << "Enter Contact Index to See Details: ";
	input = readline_();
	try
	{
		if (input.length() != 1)
			throw std::exception();
		if (input[0] < '0' || input[0] > '7')
			throw std::exception();
		idx = input[0] - '0';
		if (idx >= contact_cnt_)
			throw std::exception();
		display_detail_(idx);
	}
	catch(const std::exception& e)
	{
		std::cout << "Wrong Index! or No Contact Yet!" << std::endl;
	}
}

void PhoneBook::run()
{
	std::string command;

	std::cout << "*** ------ PhoneBook Program ------ ***" << std::endl;
	
	while (true)
	{
		std::cout << "Enter command [ ADD | SEARCH | EXIT ]: ";
		command = readline_();
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			add_contact_();
		else if (command == "SEARCH")
			search_contact_();
		else
			std::cout << "Usage: [ ADD | SEARCH | EXIT ]" << std::endl;
	}
}