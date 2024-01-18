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

#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src){
	(*this) = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src){
	for (int i = 0; i < 4; i++)
		_memory[i] = src._memory[i];
	return (*this);
}

MateriaSource::~MateriaSource(){
}

void MateriaSource::learnMateria(AMateria* src){
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] == NULL)
		{
			std::cout << "You learnt a new Materia : " << src->getType() << " (" << i << ")" << std::endl;
			_memory[i] = src;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != NULL && _memory[i]->getType() == type)
			return (_memory[i]->clone());
	}
	std::cout << "You don't already know Materia : " << type << std::endl; 
	return (0);
}
