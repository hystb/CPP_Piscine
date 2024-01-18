/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:10:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/27 15:55:14 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl << "Not correct amount of args" << std::endl;
		return (1);
	}
	Harl mess;
	int i = 0;
		std::string lvl[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	while (i < 4 && lvl[i] != argv[1])
		i++;
	switch (i)
	{
	case 0:
		std::cout << "[ " << lvl[0] << " ]" << std::endl;
		mess.complain(lvl[0]);
		std::cout << std::endl;
		// intentional fallthrough
	case 1:
		std::cout << "[ " << lvl[1] << " ]" << std::endl;
		mess.complain(lvl[1]);
		std::cout << std::endl;
		// intentional fallthrough
	case 2:
		std::cout << "[ " << lvl[2] << " ]" << std::endl;
		mess.complain(lvl[2]);
		std::cout << std::endl;
		// intentional fallthrough
	case 3:
		std::cout << "[ " << lvl[3] << " ]" << std::endl;
		mess.complain(lvl[3]);
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	
	return (0);
}