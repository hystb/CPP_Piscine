/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:24 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 15:16:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) :_name(name), _type(type) {
}

HumanA::~HumanA(){

}

void	HumanA::attack(void) const{
	std::cout << this->_name << " attacks with their " << this->_type.getType() << std::endl;
}

void		HumanA::setName(std::string name){
	this->_name = name;
}
void		HumanA::setWeapon(Weapon type){
	this->_type = type;
}
Weapon		HumanA::getWeapon(void) const{
	return this->_type;
}
std::string	HumanA::getName(void) const{
	return this->_name;
}