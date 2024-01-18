/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:04:20 by nmilan            #+#    #+#             */
/*   Updated: 2023/08/01 17:37:19 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond = DiamondTrap("Alfred");
	std::cout << std::endl << "** Alfred the DiamondTrap **" << std::endl;
	std::cout << "* Name : " << diamond.getName() << std::endl;
	std::cout << "* Diamond Name : " << diamond.getDiamondName() << std::endl;
	std::cout << "* Attack Damage : " << diamond.getAttack() << std::endl;
	std::cout << "* Hit Points : " << diamond.getHit() << std::endl;
	std::cout << "* Energy Points : " << diamond.getEnergy() << std::endl;
	std::cout << "**                        **" << std::endl << std::endl;

	FragTrap frag = FragTrap("Hercule");
	ScavTrap scav = ScavTrap("Corinthe");

	std::cout << std::endl << "* Tests *" << std::endl;
	if (50 == diamond.getEnergy())
		std::cout << "EnergyPoints equality for ScavTrap and DiamondTrap" << std::endl;
	if (30 == diamond.getAttack())
		std::cout << "AttackDamage equality for FragTrap and DiamondTrap" << std::endl;

	std::cout << std::endl << "* Capacities *" << std::endl;
	scav.attack("Michelle");
	diamond.attack("Michelle");
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();
	std::cout << std::endl;
	
}

