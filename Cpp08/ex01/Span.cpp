/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:00 by jjin              #+#    #+#             */
/*   Updated: 2023/06/09 22:25:17 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <iostream>
# include <vector>

Span::Span(unsigned int n) : _capacity(n) {}

Span::Span(const Span& other): _data(other._data), _capacity(other._capacity) {}

Span &Span::operator=(const Span& other) {
    if (this != &other) {
        _capacity = other._capacity;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void  Span::addNumber(int number) {
    if (_data.size() == _capacity)
        throw std::runtime_error("Span is full");

    _data.push_back(number);
}

void  Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_data.size() + (end - begin) > _capacity)
        throw std::runtime_error("Span is full");
        
    _data.insert(_data.end(), begin, end);
}

unsigned int  Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("Too few elements");

    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());

    unsigned int minDiff = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; i++) {
        unsigned int diff = tmp[i + 1] - tmp[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

unsigned int   Span::longestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("Too few elements");
        
    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());

    return tmp[tmp.size() - 1] - tmp[0];
}