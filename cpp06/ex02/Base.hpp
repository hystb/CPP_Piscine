/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:06:00 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:07:22 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
public:
	virtual ~Base(void);

	Base *generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif