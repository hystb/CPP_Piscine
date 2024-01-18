/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:24 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 15:16:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void){
	PhoneBook::nbContact = 0;
}

PhoneBook::~PhoneBook(void){
	
}
void	PhoneBook::addContact(Contact *element){
	
	static int	i = 0;
	std::string	tmp;
	
	std::cout << "Please enter the first name" << std::endl;
	std::getline (std::cin, tmp);
	element[i].setFirstName(tmp);
	std::cout << "Please enter the last name" << std::endl;
	std::getline (std::cin, tmp);
	element[i].setLastName(tmp);
	std::cout << "Please enter the nickname" << std::endl;
	std::getline (std::cin, tmp);
	element[i].setNickname(tmp);
	std::cout << "Please enter the phone number" << std::endl;
	std::getline (std::cin, tmp);
	element[i].setPhoneNumber(tmp);
	std::cout << "Please enter the darkest secret" << std::endl;
	std::getline (std::cin, tmp);
	element[i].setDarkSecret(tmp);
	i++;
	if (this->nbContact < 8)
		this->nbContact++;
	if (i == 8)
		i = 0;
}
void	PhoneBook::showList(Contact *list){
	int	i = 0;

	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "index";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "first name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "last name";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "nickname";
	std::cout << "|" << std::endl;
	while (i < this->nbContact)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << (i + 1);
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << this->showTen(list[i].getFirstName());
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << this->showTen(list[i].getLastName());
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << this->showTen(list[i].getNickname());
		std::cout << "|" << std::endl;
		i++;
	}
}
void	PhoneBook::showOne(Contact *list, int index){
	
	if (index > 0 && index <= 8 && index <= this->nbContact)
	{
		index--;
		std::cout << "Index : " << index + 1 << std::endl;
		std::cout << "First Name : " << this->showTen(list[index].getFirstName()) << std::endl;
		std::cout << "Last Name : " << this->showTen(list[index].getLastName()) << std::endl;
		std::cout << "Nickname : " << this->showTen(list[index].getNickname()) << std::endl;
		std::cout << "Phone Number : " << this->showTen(list[index].getPhoneNumber()) << std::endl;
		std::cout << "Darkest Secret : " << this->showTen(list[index].getDarkSecret()) << std::endl;
	}
	return;
}
std::string PhoneBook::showTen(std::string str) {
		if(str.size() >= 10)
			return (str.substr(0,9) + ".");
		return (str);
}
