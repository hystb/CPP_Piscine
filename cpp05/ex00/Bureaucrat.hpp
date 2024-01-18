/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:36 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:08:19 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# define RANKMIN 150
# define RANKMAX 1

class Bureaucrat
{
private:
	const std::string 	_name;
	unsigned int 		_rank;

public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& src);
	~Bureaucrat(void);

	Bureaucrat(std::string name, unsigned int rank);

	const std::string getName(void) const;
	unsigned int getRank(void) const;
	void rankUp(void);
	void rankDown(void);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat &bc);

#endif
