#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::string str;
	argv ++;
	while (*argv)
	{
		str += *argv;
		str += " ";
		argv ++;
	}
	
	int n;
	std::vector<int> vec;
	std::list<int> lst;
	std::stringstream stream(str);

	while (stream >> n)
	{
		if (n <= 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		if (std::find(vec.begin(), vec.end(), n) != vec.end())
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		vec.push_back(n);
		lst.push_back(n);
	}
	if (!stream.eof())
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe::sortVector(vec, 1);
	PmergeMe::sortList(lst, 1);
}
