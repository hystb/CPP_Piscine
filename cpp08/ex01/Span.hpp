/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:53:17 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 16:59:37 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <algorithm>
# include <iostream>
# include <list>
# include <cstdlib>
# include <ctime>
# include <vector>

class Span
{
private:
    unsigned int                _size;
    std::vector<unsigned int>   _tab;
    Span(void);
public:
    Span(unsigned int n);
    ~Span(void);
    Span& operator=(const Span &parent);
    Span(const Span &parent);
    unsigned int    shortestSpan(void);
    unsigned int    longestSpan(void);
    void            addNumber(int value);
    void            fillRange(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end);
    void            show(void) const;
    void            fillRandom(void);

    class SpanTooSmall : public std::exception
        {
        public:
                virtual const char* what() const throw() { return ("Span is too small to do operation !");}
        };

    class OutOfSize : public std::exception
        {
        public:
                virtual const char* what() const throw() { return ("Attempt to go out the size of the span !");}
        };
};

#endif
