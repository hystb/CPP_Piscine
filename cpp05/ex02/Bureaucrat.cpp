/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:15:25 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:15:27 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _rank(150){
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()){
	std::cout << "Bureaucrat copy constructor" << std::endl;
	(*this) = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src){
	_rank = src.getRank();
	return (*this);
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int rank) : _name(name) , _rank(rank){
	std::cout << "Bureaucrat complete constructor" << std::endl;
	if (_rank < RANKMAX)
		throw (Bureaucrat::GradeTooHighException());
	if (_rank > RANKMIN)
		throw (Bureaucrat::GradeTooLowException());
}

const std::string Bureaucrat::getName(void) const{
	return (_name);
}

unsigned int Bureaucrat::getRank(void) const{
	return (_rank);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw(){
	return ("The grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("The grade is too low");
}

void Bureaucrat::rankDown(void){
	if (_rank + 1 > RANKMIN)
		throw (Bureaucrat::GradeTooLowException());
	_rank = _rank + 1;
	std::cout << "Bureaucrat " << getName() << " made something wrong, now his rank is " << getRank() << std::endl;
}

void Bureaucrat::rankUp(void){
	if (_rank - 1 < RANKMAX)
		throw (Bureaucrat::GradeTooHighException());
	_rank = _rank - 1;
	std::cout << "Bureaucrat " << getName() << " was promoted, now his rank is " << getRank() << std::endl;
}

void Bureaucrat::signForm(Form &form){
	try {
		form.beSigned(*this);
		} 
	catch (Bureaucrat::GradeTooLowException& e){
		std::cout << getName() << " couldn't sign " << form.getName() << " because his rank is too low !" << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form){
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because : " << e.what() << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, Bureaucrat &bc){
	os << bc.getName() << ", bureaucrat grade " << bc.getRank() << std::endl;
	return (os);
}
