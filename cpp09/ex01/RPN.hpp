/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:39 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/29 15:19:31 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <exception>
# include <cstdlib>

class RPN
{
private:
    std::stack<int> _data;
    std::string     _tmp;
    RPN();

	bool	isOperator(char c);
	int		makeCalc(int op1, int op2, char sign);
public:
	RPN(char *arg);
    ~RPN();
	RPN& operator=(const RPN &parent);
    RPN(const RPN &parent);
	void	run(void);

	class NbToBig : public std::exception
        {
        public:
            virtual const char* what() const throw() { return ("One number is to big in the arg (0-9)");}
        };
	class WrongChar : public std::exception
        {
        public:
            virtual const char* what() const throw() { return ("Your arg have a wrong char");}
        };
	class DivZero : public std::exception
    	{
		public:
    		virtual const char* what() const throw() { return ("You try to divide by 0");}
		};
	class MissingOp : public std::exception
    	{
		public:
    		virtual const char* what() const throw() { return ("Missing sign to make the calculation");}
		};
};

#endif