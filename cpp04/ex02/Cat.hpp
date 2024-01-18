/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:54:57 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:54:58 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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
