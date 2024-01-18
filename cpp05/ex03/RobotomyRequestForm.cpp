/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:14:51 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:14:52 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target("default"){
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : Form("RobotomyRequestForm", 72, 45){
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	(*this) = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){
	_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target){
	std::cout << "RobotomyRequestForm named constructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	Form::execute(executor);
	std::srand(std::time(NULL));
	int number = std::rand();
	
	std::cout << "* drill's noises *" << std::endl;
	if (number % 2 == 0)
		std::cout << _target << " been robotomised with success" << std::endl;
	else
		std::cout << "attempt of robotomised failed on " << _target << std::endl;
}
