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

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav_a = ScavTrap("Louis");
	std::cout << "ScavTrap a: " << scav_a.getName() << std::endl;
	std::cout << std::endl;

	ScavTrap scav_b = ScavTrap("Alfred");
	std::cout << "ScavTrap b: " << scav_b.getName() << std::endl;
	std::cout << "Hitpoints : " << scav_b.getHit() << std::endl;
	std::cout << "Energypoints : " << scav_b.getEnergy() << std::endl;
	std::cout << "Attackdamage : " << scav_b.getAttack() << std::endl << std::endl;

	std::cout << "ScavTrap a: " << scav_b.getName() << std::endl;
	ScavTrap scav_c = ScavTrap(scav_b);
	scav_b = scav_a;
	std::cout << "ScavTrap a: " << scav_b.getName() << std::endl << std::endl;

	scav_a.guardGate();
	scav_b.guardGate();

	std::cout << std::endl;
	scav_a.attack("Michel");
	scav_b.beRepaired(10);
	scav_a.takeDamage(100);
	std::cout << std::endl;

}