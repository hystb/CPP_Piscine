/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/07/21 14:23:52 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	
	// triangle n'1 - valide

	Point cible = Point(1, 1);
	Point a = Point(0, 0);
	Point b = Point(0, 3);
	Point c = Point(2, 0);

	std::cout << "a : " << a.getX() << " " << a.getY() << std::endl;
	std::cout << "b : " << b.getX() << " " << b.getY() << std::endl;
	std::cout << "c : " << c.getX() << " " << c.getY() << std::endl;
	std::cout << bsp(a, b, c, cible) << " <- résultat" << std::endl;

	// triangle n'2 - valide

	Point cible2 = Point(4, 4);
	Point e = Point(2, 3);
	Point f = Point(6, 4);
	Point d = Point(4, 9);

	std::cout << "e : " << e.getX() << " " << e.getY() << std::endl;
	std::cout << "f : " << f.getX() << " " << f.getY() << std::endl;
	std::cout << "d : " << d.getX() << " " << d.getY() << std::endl;
	std::cout << bsp(e, f, d, cible2) << " <- résultat" << std::endl;

	// triangle n'2 - invalide -> arrete
	
	Point cible3 = Point(3, 6);
	std::cout << bsp(e, f, d, cible3) << " <- résultat" << std::endl;

	// triangle n'2 - invalide -> arrete

	Point cible4 = Point(6.5, 5);
	std::cout << bsp(e, f, d, cible4) << " <- résultat" << std::endl;

	// triangle n'2 - invalide -> droite

	Point cible5 = Point(8, 6);
	std::cout << bsp(e, f, d, cible5) << " <- résultat" << std::endl;

	// triangle n'2 - invalide -> gauche

	Point cible6 = Point(1, 8);
	std::cout << bsp(e, f, d, cible6) << " <- résultat" << std::endl;
	return (0);
}
