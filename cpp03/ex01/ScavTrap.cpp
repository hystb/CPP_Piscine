/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:37:32 by nmilan            #+#    #+#             */
/*   Updated: 2023/08/28 16:28:50 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap &src){
	ClapTrap::operator=(src);
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src.getName()){
	*this = src;
	std::cout << "ScavTrap constructor by copy called for " << _name << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << _name << " entered Gate keeper mode !" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if(_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " \
		<< _attackDamage << " points of damage!" << std::endl;
	}
	else if (_hitPoints > 0 && _energyPoints == 0)
		std::cout << "Not in of energy to make attack action." << std::endl;
	else
		std::cout << _name << " is already dead too late!" << std::endl;
}
