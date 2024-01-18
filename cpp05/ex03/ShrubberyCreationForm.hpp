/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:14:57 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:17:50 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm(std::string target);
	virtual void execute(Bureaucrat const & executor) const;
};

#endif