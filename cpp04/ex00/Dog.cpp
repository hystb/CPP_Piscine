/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:50:51 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:50:52 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(){
	type = "Dog";
	std::cout << "Dog default constructor !" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src){
	std::cout << "Dog copy constructor !" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog &src){
	type = src.type;
	return (*this);
}

Dog::~Dog(void){
	std::cout << "Dog destructor !" << std::endl;
}

void Dog::makeSound(void) const{
	std::cout << "Wouf, wouf, wouf..." << std::endl;
}
