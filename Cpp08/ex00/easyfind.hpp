/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:50:18 by jjin              #+#    #+#             */
/*   Updated: 2023/06/09 22:19:33 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <string>
# include <stdexcept>

template <typename T>
void    easyfind(T &nums, int n) {
    typename T::iterator it;

    it = std::find(nums.begin(), nums.end(), n);
    if (it == nums.end())
        throw std::runtime_error("Not found");
    std::cout << "OK" << '\n';
}

#endif