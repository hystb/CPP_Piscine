/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:25:08 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/29 15:24:58 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	BitcoinExchange btc;

	if (argc != 2)
		return (std::cout << "Wrong numbers of args : ./btc <inputfile>" << std::endl, 1);
	else
		btc.doAnalyse(argv[1]);
	return (0);
}
