/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:22 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 14:32:38 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"
# include <iomanip>
# include <string>
# include <sstream> 

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook();
	Contact	list[8];
	int		nbContact;
	void	showList(Contact *list);
	void	addContact(Contact *list);
	std::string	showTen(std::string str);
	void	showOne(Contact *list, int index);
};

# endif

