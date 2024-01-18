/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:57:02 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 14:25:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];

public:
	Character(void);
	Character(const Character& src);
	Character& operator=(const Character& src);
	~Character(void);

	Character(std::string name);

	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
