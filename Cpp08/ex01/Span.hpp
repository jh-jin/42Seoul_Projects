/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:48:26 by jjin              #+#    #+#             */
/*   Updated: 2023/06/09 22:25:23 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	private:
		std::vector<int> _data;
		unsigned int _capacity;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif