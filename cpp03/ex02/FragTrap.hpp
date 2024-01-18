/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:25:55 by nmilan            #+#    #+#             */
/*   Updated: 2023/08/28 16:32:32 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap();
	
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &src);
	~FragTrap();
	void highFivesGuys() const;

};


#endif
