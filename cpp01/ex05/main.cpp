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

int	main(void)
{
	Harl mess;
	int i = 0;
	while (i < 2)
	{
		mess.complain("DEBUG");
		mess.complain("INFO");
		mess.complain("WARNING");
		mess.complain("ERROR");
		i++;
	}
	i = 0;
	while (i < 2)
	{
		mess.complain("WARNING");
		mess.complain("INFO");
		mess.complain("ERROR");
		mess.complain("DEBUG");
		i++;
	}
	return (0);
}