/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:47:59 by jjin              #+#    #+#             */
/*   Updated: 2023/06/21 21:18:52 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

static bool checkDate(std::string date);

static bool comp(const std::string& key, const std::pair<std::string, double>& pair) {
  return key < pair.first;
}

void exchangeBitcoin(std::string fileName) {
	std::map<std::string, double> database = getDatabase();
	
	std::fstream file(fileName.c_str(), std::ios::in);
	std::string line, date, value;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");

	/* get first line */
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: input file begin line should 'date | value'");

	/* get one line */
	while (std::getline(file, line)) {
		try {
			exchangeLine(line, database);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void exchangeLine(std::string line, std::map<std::string, double> database) {
	std::string date, value;
	
	if (line.find(" | ") == std::string::npos)
		throw std::runtime_error(("Error: bad input => " + line).c_str());

	std::stringstream ss(line);

	/* get date & value */
	std::getline(ss, date, '|');
	std::getline(ss, value);
	float fValue;
	std::stringstream ssValue(value);
	if (!(ssValue >> fValue) || ssValue.tellg() != -1 || ss.tellg() != -1)
		throw std::runtime_error(("Error: bad input => " + line).c_str());

	/* check date & value */
	checkDate(date);
	if (fValue < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (fValue > 1000)
		throw std::runtime_error("Error: too large a number.");

	std::map<std::string, double>::iterator find;
	find = std::upper_bound(database.begin(), database.end(), date, comp);
	if (find == database.begin())
		throw std::runtime_error("Error: there is no matched data.");
	std::cout << date << "=> " << fValue << " = " << (--find)->second * static_cast<double>(fValue) << std::endl;	
}

std::map<std::string, double> getDatabase(void) {
	std::map<std::string, double> database;

	std::fstream file("data.csv", std::ios::in);
	std::string line, date, value;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file");

	/* get first line */
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: database begin line should be csv format");

	/* get one line */
	while (std::getline(file, line)) {
		std::stringstream ss(line);

		/* get date & value */
		std::getline(ss, date, ',');
		std::getline(ss, value);
		double dValue;
		std::stringstream ssValue(value);
		if (!(ssValue >> dValue) || ssValue.tellg() != -1 || ss.tellg() != -1)
			throw std::runtime_error(("Error: bad input => " + line).c_str());

		/* check date & value */
		checkDate(date);
		database[date] = dValue;
	}
	return database;
}

static bool checkDate(std::string date) {
	std::stringstream ssDate(date);
	struct tm tm;
	char c;
	
	/* 2000-01-01 */
	if (date.find('-', 0) != 4 || date.find('-', 5) != 7 || !(date.find(' ', 0) == std::string::npos ? date.length() == 10 : date.length() == 11))
		throw std::runtime_error("Error: invalid date format");
	if (!(ssDate >> tm.tm_year) || !(ssDate >> c) || c != '-' || \
			!(ssDate >> tm.tm_mon) || !(ssDate >> c) || c != '-' || \
			!(ssDate >> tm.tm_mday)) {
		throw std::runtime_error("Error: invalid date format: delimeter");
	}
	if (tm.tm_year < 0 || tm.tm_year > 9999 || tm.tm_mon < 1 || tm.tm_mon > 12 || tm.tm_mday < 1 || tm.tm_mday > 31) {
		throw std::runtime_error("Error: invalid date format");
	}
	if ((tm.tm_mon == 4 || tm.tm_mon == 6 || tm.tm_mon == 9 || tm.tm_mon == 11) && tm.tm_mday > 30) {
		throw std::runtime_error("Error: invalid date format");
	}
	if (tm.tm_mon == 2) {
		if (((tm.tm_year % 4 == 0) && (tm.tm_year % 100 != 0)) || (tm.tm_year % 400 == 0)) {
			if (tm.tm_mday > 29) {
				throw std::runtime_error("Error: invalid date format");
			}
		}
		else {
			if (tm.tm_mday > 28) {
				throw std::runtime_error("Error: invalid date format");
			}
		}
	}
	return true;
}