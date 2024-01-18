/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:32 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/29 15:18:34 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void){
}

RPN::RPN(char *arg){
    _tmp = arg;
}

RPN::~RPN(){
}

RPN& RPN::operator=(const RPN &parent){
    (void) parent;
    return *this;
}
RPN::RPN(const RPN &parent){
    (*this) = parent;
}

bool RPN::isOperator(char c){
    if (c == '/' || c == '*' || c == '+' || c == '-')
        return true;
    else 
        return false;
}

int	RPN::makeCalc(int op1, int op2, char sign){
	switch (sign)
	{
	case '*':
		return (op1 * op2);
	case '-':
		return (op1 - op2);
	case '+':
		return (op1 + op2);
	case '/':
		if (op2 == 0)
			throw DivZero();
		return (op1 / op2);	
	default:
		throw WrongChar();
	}
}

void	RPN::run(void){
    size_t	i = 0;
	int		op1;
	int		op2;
    
    while (i != std::string::npos && _tmp[i]){
        i = _tmp.find_first_not_of("\f\n\t\v\r   ", i);
        if (i != std::string::npos && std::isdigit(_tmp[i])){
            _data.push(std::atoi(&_tmp[i]));
            if (_data.top() > 9)
                throw NbToBig();
		}
        else if (i != std::string::npos && _data.size() > 1\
		 && isOperator(_tmp[i])){
			op2 = _data.top();
			_data.pop();
			op1 = _data.top();
			_data.pop();
			_data.push(makeCalc(op1, op2, _tmp[i]));			
		}
		else if (i != std::string::npos)
			throw WrongChar();
		if (i != std::string::npos)
			i++;
    }
	if (_data.size() == 1)
		std::cout << _data.top() << std::endl;
	else{
		throw MissingOp();
	}
}