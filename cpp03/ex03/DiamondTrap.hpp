/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:00:59 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/04 13:01:02 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap :virtual public FragTrap, virtual public ScavTrap
{
private:
	std::string _name;

public:
	DiamondTrap(void);
	~DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &parent);
	DiamondTrap& operator=(const DiamondTrap &parent);

	std::string getDiamondName(void);
	void whoAmI();
};

#endif
