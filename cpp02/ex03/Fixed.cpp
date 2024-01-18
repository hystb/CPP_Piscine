/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/07/20 15:46:46 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _raw(0){
}

Fixed::~Fixed(){
}

Fixed &Fixed::operator=(const Fixed &src){
	this->_raw = src._raw;
	return *this;

}

Fixed::Fixed(const Fixed& src){
	*this = src;
}

void	Fixed::setRawBits(int const raw){
	_raw = raw;
}

int		Fixed::getRawBits(void) const{
	return _raw;
}

Fixed::Fixed(int const value){
	_raw = (value << _bits);
}

Fixed::Fixed(float const value){
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
