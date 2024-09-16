#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <sstream>
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <limits>
#include "math.h"

class PmergeMe 
{
public:
	static void sort(char **argv);

private:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const & src);
	PmergeMe & operator=(PmergeMe const & rhs);

	char **argv;
	double listTime;
	double vectorTime;
	std::vector<int> vector;
	std::list<int> list;
	std::vector<int> input;

	void doVectorSort();
	void doListSort();
	void buildVector(std::vector<int> & vec);
	void buildList();
	void sortVector(std::vector<int> & vec, int sortSize);
	void sortList(std::list<int> & lst);

	class NonpositiveInputException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Non positive number found on sequence");
		}
	};
	class InvalidCharacterException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("An invalid character may be present in the sequence");
		}
	};
	class RepeatedNumberException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Repeated number found in sequence");
		}
	};
};

#endif
