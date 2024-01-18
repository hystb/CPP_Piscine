/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:53:51 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:53:52 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
    std::cout << "Brain default constructor !" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &src){
	std::cout << "Brain copy constructor !" << std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain &src){
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain(void){
    std::cout << "Brain destructor !" << std::endl;
}

void Brain::setIdea(std::string idea, unsigned int index){
	if (index > 99)
		return;
	ideas[index] = idea;
}

const std::string* Brain::getIdeas(void) const{
	return (ideas);
}

void Brain::printIdeas(void) const{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i] != "")
			std::cout << i << " : " << ideas[i] << std::endl; 
	}
}
