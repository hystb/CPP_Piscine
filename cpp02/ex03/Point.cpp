/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/27 15:55:14 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)){
}

Point::Point(float x, float y) :_x(Fixed(x)), _y(Fixed(y)){
}

Point::~Point(){
}

Point::Point(const Point& src){
	*this = src;
}

Point &Point::operator=(const Point& src){
	_x = src._x;
	_y = src._y;
	return *this;
}

Fixed	Point::getX(void) const{
	return _x;
}
Fixed	Point::getY(void) const{
	return _y;
}
bool	Point::operator==(const Point& right) const{
	if (_x == right._x && _y == right._y)
		return true;
	else
		return false;
}
bool	Point::operator!=(const Point& right) const{
		if (_x != right._x && _y != right._y)
		return true;
	else
		return false;

}