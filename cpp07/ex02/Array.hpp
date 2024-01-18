/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:49:59 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/18 16:01:44 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
private:
    unsigned int    _size;
    T *             _array;
public:
    Array(void) : _size(0), _array(new T()) {   
    }
    ~Array(void) {
    if (!this->_size)
        delete this->_array;
    else
        delete [] this->_array;
    }
    Array(unsigned int n){
        if (n > 0){
            _array = new T[n];
            _size = n;
        }
        else{
            _array = new T();
            _size = 0;
        }   
    }
    T& operator[](unsigned int n){
        if (_size == 0)
            return (_array[0]);
        if (n >= _size)
            throw std::out_of_range("Wrong index");
        else
            return (_array[n]);
    }
    const T operator[](unsigned int n) const{
         if (_size == 0)
            return (_array[0]);
        if (n >= _size)
            throw std::out_of_range("Wrong index");
        else
            return (_array[n]);
    }
    Array& operator=(const Array &parent){
        _size = parent._size;
        delete[] _array;
        _array = new T[_size];
        for(unsigned int i = 0; i < _size; i++)
            _array[i] = parent._array[i];
        return (*this);
    }
    Array(const Array &parent){
        _array = new T[0];
        (*this) = parent;        
    }
    unsigned int size(void){
        return (_size);
    } 
};

template <typename T>
std::ostream& operator<<(std::ostream & os, Array<T>& array)
{
    if (array.size() == 0){
        os << array[0];
    }
       
    for (unsigned int i = 0; i < array.size(); i++){
        os << array[i];
    }
    return (os);
}

#endif