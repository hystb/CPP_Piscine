/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:18:39 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:18:40 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form(void) : _name("default"), _status(false), _rank_to_sign(150), _rank_to_use(150){
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const Form& src) : _name(src.getName()){
	std::cout << "Form copy constructor" << std::endl;
	(*this) = src;
}

Form& Form::operator=(const Form& src){
	_status = src._status;
	_rank_to_sign = src._rank_to_sign;
	_rank_to_use = src._rank_to_use;
	return (*this);
}

Form::~Form(void){
	std::cout << "Form destructor" << std::endl;
}

Form::Form(const std::string name, unsigned int rank_to_sign, unsigned int rank_to_use) : _name(name), _status(false), _rank_to_sign(rank_to_sign), _rank_to_use(rank_to_use){
	std::cout << "Form complete constructor" << std::endl;
	if (_rank_to_sign > RANKMIN || _rank_to_use > RANKMIN)
		throw Bureaucrat::GradeTooLowException();
	if (_rank_to_use < RANKMAX || _rank_to_sign < RANKMAX)
		throw Bureaucrat::GradeTooHighException();
}

const std::string Form::getName() const{
	return (_name);
}

unsigned Form::getRankToSign() const{
	return (_rank_to_sign);
}

unsigned Form::getRankToUse() const{
	return (_rank_to_use);
}
	
bool Form::getStatus() const{
	return (_status);
}

void Form::beSigned(Bureaucrat &user){
	if (user.getRank() <= _rank_to_sign)
	{
		std::cout << user.getName() << " signed " << getName() << std::endl;
		_status = true;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

void Form::execute(Bureaucrat const & executor) const
{
	if (_status == false)
		throw (Form::NotSignedException());
	if (executor.getRank() > getRankToUse())
		throw (Bureaucrat::GradeTooLowException());
	else
		std::cout << executor.getName() << " executed " << getName() << std::endl;
}

const char* Form::NotSignedException::what(void) const throw()
{
	return ("The form need to be signed !");
}

std::ostream& operator<<(std::ostream& os, Form &form){
	os << "Form : " << form.getName() << ", actual state : " << form.getStatus() << ", level required to sign : " << form.getRankToSign() << ", level required to execute : " << form.getRankToUse() << std::endl;
	return (os);
}
