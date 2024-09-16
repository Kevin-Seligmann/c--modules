#include "PmergeMe.hpp"

void getNextInd(int & ind, int & jacobsthalInd, int & prevJacobsthal, int & jacobsthal, int & exp)
{
	ind --;
	if (ind == prevJacobsthal)
	{
		jacobsthalInd ++;
		prevJacobsthal = jacobsthal;
		exp = 1 << jacobsthalInd;
		jacobsthal = exp - prevJacobsthal;
		ind = jacobsthal;
	}
}

void PmergeMe::printVector(std::vector<int> & vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it ++)
	{
		std::cout << *it ;
		std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::buildVector(std::vector<int> & vec)
{
	int	n;
	char **args = argv;
	char *end;

	while (*args)
	{
        n = std::strtol(*args, &end, 10);
 		if (*end != '\0' || end == *args)
            throw InvalidCharacterException();
		if (n <= 0)
			throw NonpositiveInputException();
		if (std::find(vec.begin(), vec.end(), n) != vec.end())
			throw RepeatedNumberException();
		vec.push_back(n);
		args ++;
	}
}

void PmergeMe::buildList()
{
	int	n;
	char **args = argv;
	char *end;

	while (*args)
	{
        n = std::strtol(*args, &end, 10);
 		if (*end != '\0' || end == *args)
            throw InvalidCharacterException();
		if (n <= 0)
			throw NonpositiveInputException();
		if (std::find(list.begin(), list.end(), n) != list.end())
			throw RepeatedNumberException();
		args ++;
	}
}

void PmergeMe::doVectorSort()
{
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	buildVector(vector);
//	sortVector(vector, 1);
	clock_gettime(CLOCK_MONOTONIC, &end);
	vectorTime = (double) (end.tv_sec - start.tv_sec) * 1000000. + (double) (end.tv_nsec - start.tv_nsec) / 1000.;
}

void PmergeMe::doListSort()
{
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	buildList();
//	sortList(list);
	clock_gettime(CLOCK_MONOTONIC, &end);
	listTime = (double) (end.tv_sec - start.tv_sec) * 1000000. + (double) (end.tv_nsec - start.tv_nsec) / 1000.;
}

void PmergeMe::sort(char **argv)
{
	PmergeMe merger;
	merger.argv = argv;
	merger.buildVector(merger.input);

	std::cout << "Before: ";
	merger.printVector(merger.input);

	merger.doListSort();
	merger.doVectorSort();

	std::cout << "After: ";
	merger.printVector(merger.vector);

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of " << merger.vector.size() <<
	" elements with std::vector: " << merger.vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << merger.vector.size() <<
	" elements with std::list: " << merger.listTime << " us" << std::endl;
}

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const & src){(void) src;};
PmergeMe & PmergeMe::operator=(PmergeMe const & rhs){(void) rhs; return *this;};
