#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "math.h"

class PmergeMe 
{
	public:
		static void sortVector(std::vector<int> & vec, int partitionSize);
		static void sortList(std::list<int> & lst, int sortSize);

	private:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const & src);
		PmergeMe & operator=(PmergeMe const & rhs);
};

#endif
