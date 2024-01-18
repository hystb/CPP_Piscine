#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	type = "null";
	std::cout << "WrongAnimal default constructor !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	std::cout << "WrongAnimal copy constructor !" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src){
	type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor !" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return (type);
}

void WrongAnimal::makeSound(void) const{
	std::cout << "* insert WrongAnimal type sound *" << std::endl;
}
