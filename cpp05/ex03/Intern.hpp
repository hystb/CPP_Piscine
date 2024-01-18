/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:18:55 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:19:40 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
	Form* makePresident(std::string target);
	Form* makeRobotomy(std::string target);
	Form* makeShrubbery(std::string target);

public:
    Intern(void);
    Intern(const Intern& parent);
    Intern& operator=(const Intern& parent);
    ~Intern(void);

    Form* makeForm(std::string formType, std::string target);
};

#endif