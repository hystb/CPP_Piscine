/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:14:42 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:16:18 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm(std::string target);
	virtual void execute(Bureaucrat const & executor) const;
};

#endif