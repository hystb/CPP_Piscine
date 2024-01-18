/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:24:57 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/29 15:29:53 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& parent) { *this = parent;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& parent)
{
    _historicValues = parent._historicValues;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void    BitcoinExchange::doAnalyse(char const *input)
{
    try {
        fillHistoricValues();
        doInputValues(input);
    } catch (std::exception &e) {
        std::cout << "An error occured : " << e.what() << std::endl;
        return ;
    }
}

void    BitcoinExchange::fillHistoricValues(void)
{
    std::ifstream   ifs("data.csv");
    std::string             key;
    std::string             value;

    if (ifs.fail())
        throw (FileErrorException());
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!ifs.eof())
    {
        std::getline(ifs, key, ',');
        std::getline(ifs, value, '\n');
        _historicValues.insert(std::pair<std::string, float>(key, ft_stof(value)));
    }
}

void    BitcoinExchange::doInputValues(const char *filename)
{
    std::fstream	fs(filename);
    std::string		buffer;


    if (fs.fail())
    	throw (FileErrorException());
    fs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (fs.eof())
        throw (FileEmptyException());
    while (!fs.eof())
    {
    	std::getline(fs, buffer, '\n');
        if (buffer.empty())
            continue ;
        try {
            getAnalyseLine(buffer);
        } catch (std::exception &e) {
            std::cout << "Error : " << e.what() << std::endl; 
        }
    }
}

void BitcoinExchange::treatDate(std::string date)
{
	struct tm time;
    int	year, month, day;
	std::istringstream issYear(date);
	std::istringstream issMonth(date.substr(5));
	std::istringstream issDay(date.substr(8));
	
	if(!strptime(date.c_str(), "%Y-%m-%d", &time))
		throw (LineSyntaxException());
	issYear >> year;
	issMonth >> month;
	issDay >> day;
    if (month == 0 || month > 12 || day == 0 || day > 31)
    	throw (InvalidCalendarException());
    if (year < 2009 || (year == 2009 && month == 1 && day < 2))
       	throw (EarlyDateException());
}

float BitcoinExchange::treatValue(std::string value)
{
    value.erase(value.begin(), value.begin() + 13);

    if (value.find_first_not_of("0123456789.") != std::string::npos || std::count(value.begin(), value.end(), '.') > 1 || *(value.end() - 1) == '.')
		throw (InvalidCharacterException());
	double d_value = ft_stof(value);
	if (d_value > std::numeric_limits<float>::max() || d_value < 0 || d_value > 1000)
		throw (InvalidNumberException());
	return (d_value);
}

void    BitcoinExchange::getAnalyseLine(std::string line)
{
    std::map<std::string, float>::iterator it;
    double quantity, value;
	
    if (line.length() < 14)
		throw (LineTooShortException());
    if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw (LineSyntaxException());
    treatDate(line);
    quantity = treatValue(line);
    line.resize(10);
    if (_historicValues.find(line) != _historicValues.end())
		it = _historicValues.find(line);
    else
		it = --_historicValues.lower_bound(line);
    value = it->second;
    std::cout << line << " => " << quantity << " = " << quantity * value << std::endl;
}

float ft_stof(std::string value)
{
    float				res;
    std::istringstream	is(value);

    is >> res;
    return (res);
}