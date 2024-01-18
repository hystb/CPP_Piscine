/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:39:55 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:01:16 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T & a, T & b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;

    return ;
}

template <typename T>
T &min(T & a, T & b)
{
    return (a >= b ? b : a);
}

template <typename T>
T &max(T & a, T & b)
{
    return (a >= b ? a : b);
}

#endif