/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:24 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 15:16:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::~Zombie(){
	std::cout << this->_name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void) const{
	return this->_name;
}

void	Zombie::setName(std::string name){
	this->_name = name;
	return;
}