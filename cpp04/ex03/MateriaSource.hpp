/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:56:59 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 14:25:33 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _memory[4];
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& src);
	MateriaSource&  operator=(const MateriaSource& src);
	~MateriaSource(void);

	void learnMateria(AMateria* source);
	AMateria* createMateria(std::string const & type);
};

