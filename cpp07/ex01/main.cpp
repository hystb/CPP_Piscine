/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:19:40 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/13 16:19:42 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main( void ) 
{
	int int_tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printTab(int_tab, 10);
	iter(int_tab, 10, test<int>);
	printTab(int_tab, 10);
	
	std::cout << std::endl;

	float float_tab[10] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f};
	printTab(float_tab, 10);
	iter(float_tab, 10, test<float>);
	printTab(float_tab, 10);

	std::cout << std::endl;

	double double_tab[10] = {1.0005, 1.0005, 2.0005, 3.0005, 4.0005, 5.0005, 6.0005, 7.0005, 8.0005, 9.0005};
	printTab(double_tab, 10);
	iter(double_tab, 10, test<double>);
	printTab(double_tab, 10);

	std::cout << std::endl;

	char char_tab[5] = "abcd";
	printTab(char_tab, 4);
	iter(char_tab, 5, test<char>);
	printTab(char_tab, 4);

	return (0);
}