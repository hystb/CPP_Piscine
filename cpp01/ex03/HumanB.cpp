/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:24 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 15:16:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _type(NULL), _haveWeapon(false){
}

HumanB::~HumanB(){

}

void	HumanB::attack(void){
	if (_haveWeapon == true)
		std::cout << this->_name << " attacks with their " << this->_type->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their " << "fist" << std::endl;
}

void		HumanB::setName(std::string name){
	this->_name = name;
}
void		HumanB::setWeapon(Weapon& type){
	this->_haveWeapon = true;
	this->_type = &type;
}
Weapon		HumanB::getWeapon(void) const{
	return *this->_type;
}
std::string	HumanB::getName(void) const{
	return this->_name;
}