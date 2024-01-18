/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:26:14 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 14:26:15 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
}

Cure::Cure(const Cure& src) : AMateria(src.getType()){
}

Cure& Cure::operator=(const Cure& src){
	_type = src.getType();
	return (*this);
}

Cure::~Cure(){	
}

Cure* Cure::clone() const{
	return (new Cure());
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
