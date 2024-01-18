/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:54:13 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:54:14 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:
	Dog(void);
	Dog(const Dog &src);
	Dog& operator=(const Dog &src);
	~Dog(void);

	virtual void makeSound(void) const;
	Brain* getBrain(void) const;
};
