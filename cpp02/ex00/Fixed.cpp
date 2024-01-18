/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/08/02 13:33:58 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

static const int	bits = 8;

Fixed::Fixed(void): _raw(0){
	(void) bits;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = src.getRawBits();
	return *this;

}

Fixed::Fixed(const Fixed& src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	_raw = raw;
}

int		Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _raw;
}
