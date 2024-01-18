/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:25:52 by nmilan            #+#    #+#             */
/*   Updated: 2023/08/28 16:35:21 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called for " << _name << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap &src){
	ClapTrap::operator=(src);
	return *this;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src.getName()){
	*this = src;
	std::cout << "FragTrap constructor by copy called for " << _name << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys(void) const{
	std::cout << "FragTrap " << getName() << " ask for a high fives !" << std::endl;
}
