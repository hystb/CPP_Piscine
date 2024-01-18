/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:58:37 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/29 15:19:27 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <list>
# include <iostream>
# include <algorithm>
# include <iterator>
# include <ctime>

class PmergeMe
{
private:
    std::deque<int> 	_deque;
    std::list<int>  	_list;
	std::vector<int>	_jackList;
	size_t				_size;
	char				**_data;
	void testPrintLt(std::list<int> lst);
	void testPrintDq(std::deque<int> dq);
	std::vector<int> makeJackList(size_t size);
	void makeSortDeque(void);
	void makeSortList(void);
	std::deque<std::pair<int, int> > makeMergeDq(std::deque<std::pair<int, int> > dq);
	std::list<std::pair<int, int> > makeMergeLt(std::list<std::pair<int, int> > lst);
	void	pushLt(std::list<std::pair<int, int> > lst);
	void	pushDq(std::deque<std::pair<int, int> > lst);
	std::list<int>::iterator	binarySearchLt(int target);
	std::deque<int>::iterator	binarySearchDq(int target);
    
	PmergeMe(void);
public:
	PmergeMe(size_t size, char **data);
	~PmergeMe(void);
	PmergeMe& operator=(const PmergeMe &parent);
	PmergeMe(const PmergeMe &parent);
	void	run(void);

    class SyntaxException : public std::exception {
		public:
			virtual const char * what() const throw () { return ("invalid character found !");}
	};

	class OverFlowException : public std::exception {
		public:
			virtual const char * what() const throw () { return ("too high number must be an integer !");}
	};
};

#endif