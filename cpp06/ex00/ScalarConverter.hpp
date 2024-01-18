/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:03:07 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/18 14:02:03 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <cmath>
# include <limits>
# include <stdbool.h>
# include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& parent);

public:
    ScalarConverter& operator=(const ScalarConverter& parent);
    ~ScalarConverter(void);	
    static void convert(std::string str);
};

enum	e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

#endif