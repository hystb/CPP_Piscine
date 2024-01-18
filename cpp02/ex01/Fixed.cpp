/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/27 15:55:14 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _raw(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = src._raw;
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

Fixed::Fixed(int const value){
	std::cout << "Int constructor called" << std::endl;
	_raw = (value << _bits);
}

Fixed::Fixed(float const value){
	std::cout << "Float constructor called" << std::endl;
	_raw = int(roundf(value * (1 << _bits)));
}

float	Fixed::toFloat( void ) const{
	return float(_raw) / (1 << _bits);
}

int		Fixed::toInt( void ) const{
	return this->_raw >> _bits;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}