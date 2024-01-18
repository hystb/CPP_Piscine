/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:36:40 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:00:19 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <vector>
#include <exception>


class NotFoundException : public std::exception {
        public:
                virtual const char* what() const throw () {
                        return ("Value not found");
                }
};

template <typename T>
typename T::iterator easyfind(T &item, int n){
    typename T::iterator it = std::find(item.begin(), item.end(), n);

    if (it == item.end())
        throw (NotFoundException());
    else
        return (it);
}

#endif