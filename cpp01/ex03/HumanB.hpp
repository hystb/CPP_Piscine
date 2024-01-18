/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:24 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 15:16:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon		*_type;
	bool		_haveWeapon;
	
public:
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	setName(std::string name);
	void	setWeapon(Weapon& type);
	Weapon	getWeapon(void) const;
	std::string	getName(void) const;
};

#endif