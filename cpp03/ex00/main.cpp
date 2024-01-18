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

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct = ClapTrap("Jesous");
	ct.attack("Alfred");
	ct.attack("Louis");
	ct.attack("Jean");
	ct.attack("Jacques");
	ct.attack("Timothe");

	ct.takeDamage(9);

	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.attack("Timothe");

	ct.takeDamage(10);
	ct.beRepaired(1);
	ct.attack("Alfred");
	
	return 0;
}
