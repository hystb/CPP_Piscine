/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/27 15:55:14 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_raw;
	static const int	_bits = 8;
public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed& src);
	Fixed &operator=(const Fixed &src);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	bool	operator>(const Fixed& right) const;
	bool	operator<(const Fixed& right) const;
	bool	operator>=(const Fixed& right) const;
	bool	operator<=(const Fixed& right) const;
	bool	operator==(const Fixed& right) const;
	bool	operator!=(const Fixed& right) const;
	Fixed	operator+(const Fixed& right) const;
	Fixed	operator-(const Fixed& right) const;
	Fixed	operator*(const Fixed& right) const;
	Fixed	operator/(const Fixed& right) const;
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator--(int);
	Fixed	operator++(int);
	static const Fixed&	min(const Fixed& num1, const Fixed& num2);
	static const Fixed&	max(const Fixed& num1, const Fixed& num2);
	static Fixed&	min(Fixed& num1, Fixed& num2);
	static Fixed&	max(Fixed& num1, Fixed& num2);
};
std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif