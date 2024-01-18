/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:04:26 by nmilan            #+#    #+#             */
/*   Updated: 2023/08/03 12:43:26 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("noname"), _hitPoints(100), _energyPoints(50), _attackDamage(20){
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src){
	_name = src._name;
	_attackDamage = src._attackDamage;
	_energyPoints = src._energyPoints;
	_hitPoints = src._hitPoints;
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	*this = src;
	std::cout << "ClapTrap constructor by copy called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20){	
	std::cout << "ClapTrap constructor called for " << name << std::endl; 
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called for " << _name << std::endl; 
}

void	ClapTrap::attack(const std::string& target){
	if(_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " \
		<< _attackDamage << " points of damage!" << std::endl;
	}
	else if (_hitPoints > 0 && _energyPoints == 0)
		std::cout << "Not in of energy to make attack action." << std::endl;
	else
		std::cout << _name << " is already dead too late!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints == 0)
		std::cout << _name << " is already dead too late!" << std::endl;
	else
	{
		if (amount < _hitPoints)
		{
			_hitPoints -= amount;
			std::cout << "ClapTrap " << _name << " take damage " << ", causing " \
			<< amount << " points of damage to him!" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << _name << " take damage " << ", causing " \
			<< _hitPoints << " points of damage to him!" << std::endl;
			_hitPoints = 0;
		}
		if (_hitPoints == 0)
		{
			std::cout << _name << " died." << std::endl;
			_hitPoints = 0;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if(_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " heal himself " \
		<< amount << " hit points!" << std::endl;
		_hitPoints += amount;
	}
	else if (_hitPoints > 0 && _energyPoints == 0)
		std::cout << "Not in of energy to make heal action." << std::endl;
	else
		std::cout << _name << " is already dead too late!" << std::endl;
}

	void	ClapTrap::setName(std::string name){
		_name = name;
	}
	void	ClapTrap::setHit(unsigned int amount){
		_hitPoints = amount;
	}
	void	ClapTrap::setEnergy(unsigned int amount){
		_energyPoints = amount;
	}
	void	ClapTrap::setAttack(unsigned int amount){
		_attackDamage = amount;
	}
	std::string	ClapTrap::getName(void) const{
		return _name;
	}
	unsigned int	ClapTrap::getHit(void) const{
		return _hitPoints;
	}
	unsigned int	ClapTrap::getEnergy(void) const{
		return _energyPoints;
	}
	unsigned int	ClapTrap::getAttack(void) const{
		return _attackDamage;
	}