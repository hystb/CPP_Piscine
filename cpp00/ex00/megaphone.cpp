/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:00:40 by nmilan            #+#    #+#             */
/*   Updated: 2023/06/23 11:00:47 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_trim(std::string str, char *res)
{
	size_t	i = 0;
	size_t	j = 0;

	i = str.find_first_not_of(" ");
	if (i == std::string::npos)
	{
		res[0] = '\0';
		return ;
	}
	j = str.find_last_not_of(" ");
	str.copy(res, j - i + 1, i);
	res[j - i + 1] = '\0';
	return ;
}

int	main(int argc, char **argv)
{
	char	*str = NULL;
	char	c = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		while(*argv)
		{
			ft_trim(*argv, *argv);
			str = *argv;
			while (*str)
			{
				c = *str;
				std::cout << (char)std::toupper(c);
				str++;
			}			
			argv++;
			if (*argv)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
