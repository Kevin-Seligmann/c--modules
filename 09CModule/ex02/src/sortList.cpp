#include "PmergeMe.hpp"

void getNextInd(int & ind, int & jacobsthalInd, int & prevJacobsthal, int & jacobsthal, int & exp);

void buildPairs(std::list<std::pair<int &, std::list<int> &> &> & pairs)
{

}

void PmergeMe::sortList(std::list<int> & lst)
{
    std::list<std::pair<int &, std::list<int> &> &> pairs;
	buildPairs(pairs);
}