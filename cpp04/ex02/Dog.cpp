/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:55:01 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:55:02 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : AAnimal(){
	type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor !" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src){
	*this = src;
	std::cout << "Dog copy constructor !" << std::endl;
}

Dog& Dog::operator=(const Dog &src){
	_brain = new Brain(*(src._brain));
	type = src.type;
	return (*this);
}

Dog::~Dog(void){
	delete _brain;
	std::cout << "Dog destructor !" << std::endl;
}

void Dog::makeSound(void) const{
	std::cout << "Wouf, wouf, wouf..." << std::endl;
}

Brain* Dog::getBrain(void) const{
	return (_brain);
}
