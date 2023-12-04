/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:49:37 by jjin              #+#    #+#             */
/*   Updated: 2023/06/21 20:49:43 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>
# include <string>
# include <map> 

std::map<std::string, double> getDatabase(void);

void exchangeBitcoin(std::string fileName);
void exchangeLine(std::string line, std::map<std::string, double> database);

#endif