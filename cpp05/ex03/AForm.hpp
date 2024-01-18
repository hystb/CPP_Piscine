/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:18:42 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:21:54 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string 	_name;
	bool 				_status;
	unsigned int 		_rank_to_sign;
	unsigned int		_rank_to_use;

public:
	Form(void);
	Form(const Form& src);
	Form& operator=(const Form& src);
	virtual ~Form(void) = 0;
	
	const std::string getName() const;
	unsigned getRankToSign() const;
	unsigned getRankToUse() const;
	bool getStatus() const;

	Form(const std::string name, unsigned int rank_to_sign, unsigned int rank_to_use);

	void beSigned(Bureaucrat &user);
	virtual void execute(Bureaucrat const & executor) const;
	class NotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, Form &form);

#endif