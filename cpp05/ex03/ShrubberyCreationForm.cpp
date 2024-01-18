/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:14:54 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:14:55 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("default"){
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : Form("ShrubberyCreationForm", 145, 137){
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	(*this) = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){
	_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << "ShrubberyCreationForm named constructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	Form::execute(executor);
	std::string res = _target + "_shrubbery";
	std::ofstream ofs(res.c_str());
	if (ofs.fail() == 1)
	{
		std::cout << executor.getName() << " fail to create the file while executing form : " << getName() << std::endl;
	}
	else
	{
		ofs << "       _-_" << std::endl;
		ofs << "    /~~   ~~\\" << std::endl;
		ofs << " /~~         ~~\\" << std::endl;
		ofs << "{               }" << std::endl;
		ofs << " \\  _-     -_  /" << std::endl;
		ofs << "   ~  \\ //  ~" << std::endl;
		ofs << "_- -   | | _- _" << std::endl;
		ofs << "  _ -  | |   -_" << std::endl;
		ofs << "      // \\\\" << std::endl;
	}
}
