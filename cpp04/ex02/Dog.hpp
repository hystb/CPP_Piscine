/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:55:05 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:55:06 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
