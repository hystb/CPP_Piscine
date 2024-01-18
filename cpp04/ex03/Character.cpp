/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:57:02 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 14:25:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
	_name = "default";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& src){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = src;
}

Character& Character::operator=(const Character& src){
	_name = src.getName();
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete (_inventory[i]);
		if (src._inventory[i] == NULL)	
			_inventory[i] = NULL;
		else
			_inventory[i] = src._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete (_inventory[i]);
		}
	}
}

Character::Character(std::string name){
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

const std::string& Character::getName() const{
	return (_name);
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
}

void Character::unequip(int idx){
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	std::cout << "Character " << _name << " unequip " << _inventory[idx]->getType() << " from inventory (" << idx << ")" << std::endl;
	_inventory[idx] = NULL;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			std::cout << "Character " << _name << " equip " << m->getType() << " from inventory (" << i << ")" << std::endl;
			_inventory[i] = m;
			return ;
		}
	}
}
