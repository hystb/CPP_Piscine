/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:25 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/29 15:18:27 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv){

    if (argc == 2){
        RPN calc(argv[1]);
        try{
            calc.run();
        }
        catch(const std::exception& e){
            std::cerr << e.what() << std::endl;
        }
        
    }
    else
    {
        std::cout << "Program need only 1 arg" << std::endl;
    }
}