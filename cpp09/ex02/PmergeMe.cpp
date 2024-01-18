/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:58:32 by nmilan            #+#    #+#             */
/*   Updated: 2023/12/28 18:43:20 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(size_t size, char **data) : _size(size), _data(data) {
	for(size_t i = 0; data[i]; i++){
		for(size_t j = 0; data[i][j]; j++){
			if (!std::isdigit(_data[i][j]))
				throw SyntaxException();
		}
		_deque.push_back(std::atoi(_data[i]));
		_list.push_back(std::atoi(_data[i]));
	}
	if (_size >= 3)
		_jackList = makeJackList(_size);
}

PmergeMe::PmergeMe(const PmergeMe &parent){
	(*this) = parent;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &parent){
	_deque = parent._deque;
	_list = parent._list;
	return (*this);
}

PmergeMe::~PmergeMe(void) {
}

std::vector<int> PmergeMe::makeJackList(size_t limit){
    std::vector<int> jacobsthalSequence;
	size_t	start;
	int jacobsthalNumber = 0;
    int prev1 = 0, prev2 = 1;
	limit = ((limit) / 2) + 1;

    while (static_cast<size_t>(jacobsthalNumber) < limit) {
        if (jacobsthalNumber != 0){
			jacobsthalSequence.push_back(jacobsthalNumber);
			for (int i = jacobsthalNumber - 1 ; i >  prev1; i--)
			{
				jacobsthalSequence.push_back(i);
			}
		}
        jacobsthalNumber = prev2 + 2 * prev1;
        prev1 = prev2;
        prev2 = jacobsthalNumber;	
	}
	for(start = *(std::max_element(jacobsthalSequence.begin(), jacobsthalSequence.end())) + 1; start < limit; start ++){
		jacobsthalSequence.push_back(start);
	}
    return jacobsthalSequence;
}
void PmergeMe::makeSortDeque(void){
	std::deque<std::pair<int, int> >	pairTmp;
	std::deque<int>::iterator			it = _deque.begin();
	std::deque<int>::iterator			it2 = _deque.begin();

	for( ; it != _deque.end(); ){
		std::advance(it2, 1);
		if (it2 != _deque.end()){
			if (*it > *it2)
				pairTmp.push_back(std::make_pair(*it, *it2));
			else
				pairTmp.push_back(std::make_pair(*it2, *it));
			std::advance(it, 2);
			std::advance(it2, 1);
		}
		else{
			pairTmp.push_back(std::make_pair(-1, *it));
			break ;
		}
	}
	_deque.clear();
	pairTmp = makeMergeDq(pairTmp);
	pushDq(pairTmp);
}


void PmergeMe::makeSortList(void){
	std::list<std::pair<int, int> >	pairTmp;
	std::list<int>::iterator			it = _list.begin();
	std::list<int>::iterator			it2 = _list.begin();

	for( ; it != _list.end(); ){
		std::advance(it2, 1);
		if (it2 != _list.end()){
			if (*it > *it2)
				pairTmp.push_back(std::make_pair(*it, *it2));
			else
				pairTmp.push_back(std::make_pair(*it2, *it));
			std::advance(it, 2);
			std::advance(it2, 1);
		}
		else{
			pairTmp.push_back(std::make_pair(-1, *it));
			break ;
		}		
	}
	_list.clear();
	pairTmp = makeMergeLt(pairTmp);
	pushLt(pairTmp);
}

void PmergeMe::testPrintLt(std::list<int> lst){
	std::list<int>::iterator	it;
	for (it = lst.begin(); it != lst.end(); it++){
		std::cout << *it << " "; 
	}
	std::cout << std::endl;
}

void PmergeMe::testPrintDq(std::deque<int> dq){
	std::deque<int>::iterator	it;
	for (it = dq.begin(); it != dq.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::deque<std::pair<int, int> > PmergeMe::makeMergeDq(std::deque<std::pair<int, int> > dq){
    if (dq.size() <= 1)
        return (dq);

    std::deque<std::pair<int, int> >::iterator    mid = dq.begin() + dq.size() / 2;
    std::deque<std::pair<int, int> >            leftVec(dq.begin(), mid);
    std::deque<std::pair<int, int> >            rightVec(mid, dq.end());
    
    std::deque<std::pair<int, int> >    leftSorted = makeMergeDq(leftVec);
    std::deque<std::pair<int, int> >    rightSorted = makeMergeDq(rightVec);

    std::deque<std::pair<int, int> >    mergedVec;
    std::merge(leftSorted.begin(), leftSorted.end(), rightSorted.begin(), rightSorted.end(), std::back_inserter(mergedVec));
    return (mergedVec);
}

std::list<std::pair<int, int> > PmergeMe::makeMergeLt(std::list<std::pair<int, int> > lst){
    if (lst.size() <= 1)
        return (lst);

    std::list<std::pair<int, int> >::iterator    mid = lst.begin();
	std::advance(mid, lst.size() / 2);
    std::list<std::pair<int, int> >            leftVec(lst.begin(), mid);
    std::list<std::pair<int, int> >            rightVec(mid, lst.end());
    
    std::list<std::pair<int, int> >    leftSorted = makeMergeLt(leftVec);
    std::list<std::pair<int, int> >    rightSorted = makeMergeLt(rightVec);

    std::list<std::pair<int, int> >    merged;
    std::merge(leftSorted.begin(), leftSorted.end(), rightSorted.begin(), rightSorted.end(), std::back_inserter(merged));
    return (merged);
}

void	PmergeMe::pushLt(std::list<std::pair<int, int> > lst){
	std::list<std::pair<int, int> >::iterator	it;
	std::list<int>::iterator					it2;
	std::vector<int>::iterator					it3;
	for(it = lst.begin() ; it != lst.end() ; it++){
		if (it->first != -1)
			_list.push_back(it->first);
	}
	for(it3 = _jackList.begin(); it3 != _jackList.end(); it3++){
		it = lst.begin();
		std::advance(it, *it3 - 1);
		it2 = binarySearchLt(it->second);
		_list.insert(it2, it->second);
	}
	
}

void	PmergeMe::pushDq(std::deque<std::pair<int, int> > lst){
	std::deque<std::pair<int, int> >::iterator	it;
	std::deque<int>::iterator					it2;
	std::vector<int>::iterator					it3;
	for(it = lst.begin() ; it != lst.end() ; it++){
		if (it->first != -1)
			_deque.push_back(it->first);
	}
	for(it3 = _jackList.begin(); it3 != _jackList.end(); it3++){
		it = lst.begin();
		std::advance(it, *it3 - 1);
		it2 = binarySearchDq(it->second);
		_deque.insert(it2, it->second);
	}
	
}

std::deque<int>::iterator	PmergeMe::binarySearchDq(int target)
{
    std::deque<int>::iterator left = _deque.begin();
    std::deque<int>::iterator right = _deque.end();

    while (left != right) {
        std::deque<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (*mid < target) {
            left = ++mid;
        } else {
            right = mid;
        }
    }
    return right;
}

std::list<int>::iterator	PmergeMe::binarySearchLt(int target)
{
    std::list<int>::iterator left = _list.begin();
    std::list<int>::iterator right = _list.end();

    while (left != right) {
        std::list<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (*mid < target) {
            left = ++mid;
        } else {
            right = mid;
        }
    }
    return right;
}


void	PmergeMe::run(void){
	
	std::cout << "Before in lst : ";
	testPrintLt(_list);
	clock_t start = clock();
	makeSortList();
	clock_t end = clock();
	std::cout << "After in lst : ";
	testPrintLt(_list);
	std::cout << "Time to process a range of " << _size - 1 << " with std::list : " << static_cast<double>(end - start) << " us" << std::endl;
	std::cout << "Before in dq : ";
	testPrintDq(_deque);
	start = clock();
	makeSortDeque();
	end = clock();
	std::cout << "Time to process a range of " << _size - 1 << " with std::list : " << static_cast<double>(end - start) << " us" << std::endl;
	std::cout << "After in dq : ";
	testPrintDq(_deque);
}