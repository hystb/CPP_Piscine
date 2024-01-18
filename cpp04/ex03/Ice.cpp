/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:57:26 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:57:27 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
}

Ice::Ice(const Ice& src) : AMateria(src.getType()){
}

Ice& Ice::operator=(const Ice& src){
	_type = src.getType();
	return (*this);
}

Ice::~Ice(){
}

Ice* Ice::clone() const{
	return (new Ice());
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
