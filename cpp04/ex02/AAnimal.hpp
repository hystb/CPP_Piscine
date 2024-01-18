/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:54:43 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:54:44 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal(void);
	AAnimal(const AAnimal &src);
	AAnimal& operator=(const AAnimal &src);
	virtual ~AAnimal(void) = 0;

	std::string getType(void) const;
	virtual void makeSound(void) const = 0;
};
