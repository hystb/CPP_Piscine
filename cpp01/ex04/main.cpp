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

#include <iostream>
#include <istream>
#include <fstream>
#include <string>

void	ft_replace(char *buffer, std::ifstream *is, char **argv)
{
	std::string	filename = argv[1];
	size_t		find;
	std::string	buf = buffer;
	std::string exp1 = argv[2];
	std::string exp2 = argv[3];

	if (is->good())
	{
		if (is->peek() == std::ifstream::traits_type::eof())
		{
			std::cout << "Error" << std::endl << "Nothing in the file" << std::endl;
			return ;
		}
		std::ofstream os(filename.append(".replace").data());
			find = buf.find(exp1, 0);
			while (find != std::string::npos)
			{
				buf.erase(find, exp1.length());
				buf.insert(find, exp2);
				find = buf.find(exp1, find);			
			}
			os << buf;
			os.close();
			return;			
	}
}

void	ft_sed(char **argv)
{
	int			lenght = 0;
	char		*buffer;

	std::ifstream is(argv[1], std::ifstream::binary);
	if(is)
	{
		is.seekg(0, is.end);
		lenght = is.tellg();
		is.seekg(0, is.beg);
	}
	else
	{
		std::cout << "Error" << std::endl << "No file" << std::endl;
		is.close();
		return;
	}
	buffer = new char [lenght + 1];
	is.read(buffer, lenght);
	buffer[lenght] = '\0';
	is.seekg(0, is.beg);
	ft_replace(buffer, &is, argv);
	is.close();
	delete [] buffer;
		
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		ft_sed(argv);
	else
		std::cout << "Error" << std::endl << "Please entre as following <fileName> <expressionA> <expressionB>";
}
