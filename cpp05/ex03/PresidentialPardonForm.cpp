/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:14:46 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:14:47 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("default"){
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form("PresidentialPardonForm", 25, 5){
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	(*this) = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src){
	_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << "PresidentialPardonForm named constructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	Form::execute(executor);
	std::cout << _target << " was forgiven by Zaphod Beeblebrox" << std::endl;
}
