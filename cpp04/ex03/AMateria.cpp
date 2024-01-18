/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:50:13 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:50:14 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria(void){
}

AMateria& AMateria::operator=(const AMateria& src) {
	_type = src.getType();
	return (*this);
}

AMateria::AMateria(const AMateria& src){
	*this = src;
}

AMateria::~AMateria(void){
}

AMateria::AMateria(std::string const & type) : _type(type){
}

const std::string& AMateria::getType() const{
	return (_type);
}

void AMateria::use(ICharacter& target){
	std::cout << "Use AMateria on " << target.getName() << std::endl;
}
