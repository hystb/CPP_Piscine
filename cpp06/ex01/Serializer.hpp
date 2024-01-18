/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:04:31 by nmilan            #+#    #+#             */
/*   Updated: 2023/10/25 17:05:43 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>

struct Data
{
	std::string text;
	int			number;
};

class Serializer
{
private:
	Serializer(void);
public:
	Serializer(const Serializer& parent);
	Serializer& operator=(const Serializer& parent);
	~Serializer(void);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif