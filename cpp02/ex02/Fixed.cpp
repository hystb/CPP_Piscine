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
	return float(this->_raw) / (1 << _bits);
}

int		Fixed::toInt( void ) const{
	return this->_raw >> _bits;
}

bool	Fixed::operator>(const Fixed& right) const{
	return _raw > right._raw;
}
bool	Fixed::operator<(const Fixed& right) const{
	return _raw < right._raw;
}
bool	Fixed::operator>=(const Fixed& right) const{
	return _raw >= right._raw;
}
bool	Fixed::operator<=(const Fixed& right) const{
	return _raw <= right._raw;
}
bool	Fixed::operator==(const Fixed& right) const{
	return _raw == right._raw;
}
bool	Fixed::operator!=(const Fixed& right) const{
	return _raw != right._raw;
}
Fixed	Fixed::operator+(const Fixed& right) const{
	Fixed res;

	res.setRawBits(_raw + right._raw);
	return res;
}
Fixed	Fixed::operator-(const Fixed& right) const{
	Fixed res;

	res.setRawBits(_raw - right._raw);
	return res;
}
Fixed	Fixed::operator*(const Fixed& right) const{
	Fixed res;

	res.setRawBits(_raw * right._raw >> _bits);
	return res;
}
Fixed	Fixed::operator/(const Fixed& right) const{
	Fixed res;

	res.setRawBits((_raw << _bits) / right._raw);
	return res;
}
Fixed&	Fixed::operator++(){
	++_raw;
	return *this;
}
Fixed&	Fixed::operator--(){
	--_raw;
	return *this;
}
Fixed	Fixed::operator++(int){
	Fixed tmp = *this;
	++*this;
	return tmp;
}
Fixed	Fixed::operator--(int){
	Fixed tmp = *this;
	--*this;
	return tmp;
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2){
	if (num1._raw < num2._raw)
		return num1;
	else
		return num2;
}
const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2){
	if (num1._raw > num2._raw)
		return num1;
	else
		return num2;

}
Fixed&	Fixed::min(Fixed& num1, Fixed& num2){
	if (num1< num2)
		return num1;
	else
		return num2;

}
Fixed&	Fixed::max(Fixed& num1, Fixed& num2){
	if (num1> num2)
		return num1;
	else
		return num2;

}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}