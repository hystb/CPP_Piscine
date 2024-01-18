/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:04:23 by nmilan            #+#    #+#             */
/*   Updated: 2023/08/02 19:04:43 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
private:
		std::string 			_name;
		unsigned int			_hitPoints;
		unsigned int			_energyPoints;
		unsigned int			_attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &src);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	setName(std::string name);
	void	setHit(unsigned int amount);
	void	setEnergy(unsigned int amount);
	void	setAttack(unsigned int amount);
	std::string	getName(void) const;
	unsigned int	getHit(void) const;
	unsigned int	getEnergy(void) const;
	unsigned int	getAttack(void) const;
};

#endif
