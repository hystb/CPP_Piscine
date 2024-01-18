/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/27 15:55:14 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed _x;
	Fixed _y;
public:
	Point(void);
	~Point();
	Point(float x, float y);
	Point(const Point& src);
	Point	&operator=(const Point& src);
	Fixed	getX(void) const;
	Fixed	getY(void) const;
	bool	operator==(const Point& right) const;
	bool	operator!=(const Point& right) const;

};

#endif