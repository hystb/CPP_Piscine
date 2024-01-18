/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:54:03 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:54:04 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* _brain;
public:
	Cat(void);
	Cat(const Cat &src);
	Cat& operator=(const Cat &src);
	virtual ~Cat(void);
	
	virtual void makeSound(void) const;
	Brain* getBrain(void) const;
};
