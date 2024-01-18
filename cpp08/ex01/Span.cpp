/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:53:26 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/18 14:41:15 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void){   
}

Span::Span(unsigned int n): _size(n), _tab() {
}

Span::Span(const Span &parent){
    (*this) = parent;
}

Span& Span::operator=(const Span &parent)
{
    _size = parent._size;
    _tab = parent._tab;
    return (*this);
}

Span::~Span(void) {}

unsigned int    Span::shortestSpan(void){
    
    if (_tab.size() < 2)
                throw (SpanTooSmall());

        std::vector<unsigned int> sorted_tab = _tab;
        std::sort(sorted_tab.begin(), sorted_tab.end());
        unsigned int distance = sorted_tab[1] - sorted_tab[0];

        for (unsigned int i = 2; i < _tab.size(); i++)
        {
                if (sorted_tab[i] - sorted_tab[i - 1] < distance)
                        distance = sorted_tab[i] - sorted_tab[i - 1];
        }
        return (distance);
}

unsigned int    Span::longestSpan(void){

    if(_tab.size() < 2)
        throw (Span::SpanTooSmall());
    
    int big = *std::max_element(_tab.begin(), _tab.end());
    int small = *std::min_element(_tab.begin(), _tab.end());
    return (big - small);
}

void            Span::addNumber(int value){
     if (_size == _tab.size())
            throw (OutOfSize());
    _tab.push_back(value);
}

void            Span::fillRange(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end){
   
    if (_size < _tab.size() + std::distance(start, end))
            throw (Span::SpanTooSmall());
    _tab.insert(_tab.end(), start, end);    
}

void            Span::show(void) const{
    
      if (_tab.size() == 0)
                return ;
        for (unsigned int i = 0; i < _tab.size(); i++)
        {
                std::cout << _tab[i];
                if (i + 1 < _tab.size())
                        std::cout << ", ";
        }
        std::cout << std::endl;
}

void            Span::fillRandom(void){
    
    _tab = std::vector<unsigned int>(_size);
    std::srand(std::time(NULL));
    std::generate(_tab.begin(), _tab.end(), std::rand);
}