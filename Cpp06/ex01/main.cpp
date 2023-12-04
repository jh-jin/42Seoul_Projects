/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:24:24 by jjin              #+#    #+#             */
/*   Updated: 2023/05/24 21:57:07 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
	Data *data = new Data;
	data->id = 1;
	data->value = 10;

	uintptr_t serializedData = Serializer::serialize(data);
	std::cout << "data: " << data << std::endl;
	std::cout << "serializedData: " << serializedData << std::endl;

	Data *deserializedData = Serializer::deserialize(serializedData);
	std::cout << "id: " << deserializedData->id << std::endl;
	std::cout << "value: " << deserializedData->value << std::endl;
	std::cout << "Comparing Address: " << (data == deserializedData ? "same" : "different") << std::endl;

	delete data;
}