/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:58:19 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:01:59 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename U>
void    iter(T &tab, size_t len, U &function)
{
    for(size_t i = 0; i < len; i++)
        function(tab[i]);
}

template <typename T, typename U>
void    iter(T &tab, size_t len, U const &function)
{
    for(size_t i = 0; i < len; i++)
       function(tab[i]);
}

template <typename T>
void  test(T &value)
{
    value += 1;
}

template <typename T>
void    printTab(T *tab, size_t len)
{
    std::cout << "values :";
    for(size_t i = 0; i < len; i++)
        std::cout << tab[i] << " ";
    std::cout << std::endl;
}

#endif