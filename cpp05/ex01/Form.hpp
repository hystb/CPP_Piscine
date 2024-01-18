/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:09:12 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/08 12:44:49 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string 	_name;
	bool 				_status;
	const unsigned int 		_rank_to_sign;
	const unsigned int		_rank_to_use;

public:
	Form(void);
	Form(const Form& src);
	Form& operator=(const Form& src);
	~Form(void);
	
	const std::string getName() const;
	unsigned getRankToSign() const;
	unsigned getRankToUse() const;
	bool getStatus() const;
	Form(const std::string name, unsigned int rank_to_sign, unsigned int rank_to_use);
	void beSigned(Bureaucrat &user);
};
std::ostream& operator<<(std::ostream& os, Form &form);

#endif
