/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:01:22 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 14:32:38 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class Contact {
	
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact(void);
		~Contact(void);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkSecret(void) const;
	
		void		setFirstName(std::string name);
		void		setLastName(std::string name);
		void		setNickname(std::string name);
		void		setPhoneNumber(std::string number);
		void		setDarkSecret(std::string secret);
};

#endif
