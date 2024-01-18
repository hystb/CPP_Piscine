/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/07/21 14:24:54 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float ft_is_positive(Point const pt, Point const p1, Point const p2)
{
	return (pt.getX().toFloat() - p2.getX().toFloat()) * \
	(p1.getY().toFloat() - p2.getY().toFloat()) * (pt.getY().toFloat() - p2.getY().toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	test1 = ft_is_positive(point, a, b);
	float	test2 = ft_is_positive(point, b, c);
	float	test3 = ft_is_positive(point, c, a);

	bool is_negative = (test1 < 0) || (test2 < 0) || (test3 < 0);
	bool is_positive = (test1 > 0) || (test2 > 0) || (test3 > 0);
	bool is_zero = (test1 == 0) || (test2 == 0) || (test3 == 0);
	
	return !(is_negative && is_positive && !is_zero);
}
