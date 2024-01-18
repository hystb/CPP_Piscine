/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:53:55 by nmilan            #+#    #+#             */
/*   Updated: 2023/09/06 13:53:56 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain
{
private:
    std::string ideas[100];
	
public:
    Brain(void);
    Brain(const Brain &src);
    Brain& operator=(const Brain &src);
    ~Brain(void);

	void setIdea(std::string idea, unsigned int index);
	const std::string* getIdeas(void) const;
	void printIdeas(void) const;
};
