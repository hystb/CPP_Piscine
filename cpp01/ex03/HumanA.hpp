/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:24 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 15:16:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon&		_type;
	
public:
	HumanA(std::string name, Weapon& type);
	~HumanA();
	void	attack(void) const;
	void	setName(std::string name);
	void	setWeapon(Weapon type);
	Weapon	getWeapon(void) const;
	std::string	getName(void) const;
};

#endif
