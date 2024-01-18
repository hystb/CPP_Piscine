/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:54:26 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:54:27 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal(){
	type = "WrongCat";
	std::cout << "WrongCat default constructor !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src){
	std::cout << "WrongCat copy constructor !" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &src){
	type = src.type;
	return (*this);
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor !" << std::endl;
}

void WrongCat::makeSound(void) const{
	std::cout << "Weow, Weow, Weow..." << std::endl;
}
