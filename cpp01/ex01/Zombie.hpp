/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:24 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 15:16:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
				Zombie();
				~Zombie();

	void		announce(void) const;
	std::string	getName(void) const;
	void		setName(std::string name);
};

#endif
