/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:16 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 14:33:00 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void){
	return;	
}

std::string Contact::getFirstName(void) const{
	return this->_firstName;
}
std::string Contact::getLastName(void) const{
	return this->_lastName;
}
std::string Contact::getNickname(void) const{
	return this->_nickname;
}
std::string	Contact::getPhoneNumber(void) const{
	return this->_phoneNumber;
}
std::string Contact::getDarkSecret(void) const{
	return this->_darkestSecret;
}

void Contact::setFirstName(std::string str){
	while (str == ""){
		std::cout << "Please enter a value to continue" << std::endl;
		std::getline(std::cin, str);
	}
	this->_firstName = str;

}
void Contact::setLastName(std::string str){
	while (str == ""){
		std::cout << "Please enter a value to continue" << std::endl;
		std::getline(std::cin, str);
	}
	this->_lastName = str;
}
void Contact::setNickname(std::string str){
	while (str == ""){
		std::cout << "Please enter a value to continue" << std::endl;
		std::getline(std::cin, str);
	}
	this->_nickname = str;
}
void Contact::setPhoneNumber(std::string str){
	while (str == ""){
		std::cout << "Please enter a value to continue" << std::endl;
		std::getline(std::cin, str);
	}
	this->_phoneNumber = str;
}
void Contact::setDarkSecret(std::string str){
	while (str == ""){
		std::cout << "Please enter a value to continue" << std::endl;
		std::getline(std::cin, str);
	}
	this->_darkestSecret = str;
}