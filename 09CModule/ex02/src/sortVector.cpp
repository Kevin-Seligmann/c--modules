#include "PmergeMe.hpp"

void getNextInd(int & ind, int & jacobsthalInd, int & prevJacobsthal, int & jacobsthal, int & exp);

namespace
{
void vectorSwapInsidePartition(std::vector<int> & vec, int sortSize, int partitionMaxInd)
{
	for (int partitionInd = 0; partitionInd < partitionMaxInd; partitionInd ++)
	{
		if (vec[partitionInd * 2 * sortSize] < vec[(partitionInd * 2 + 1) * sortSize])
		{
			for (int i = 0; i < sortSize; i ++)
			{
				std::swap(vec[partitionInd * 2 * sortSize + i], vec[(partitionInd * 2 + 1) * sortSize + i]);
			}
		}
	}
}

void vectorSeparatePairs(std::vector<int> & vec, std::vector<int> & vecA, std::vector<int> & vecB, int sizeMaxInd, int sortSize)
{
	int i;
	vecA.reserve(vec.size());
	vecB.reserve((sizeMaxInd / 2) * sortSize);

	for (i = 0; i < sizeMaxInd; i ++)
	{
		if (i % 2 == 0)
		{
			if (i == sizeMaxInd - 1 && sizeMaxInd % 2 == 1)
			{
				vecB.insert(vecB.end(), vec.begin() + i * sortSize, vec.begin() + (i + 1) * sortSize);
			}
			else
			{
				vecA.insert(vecA.end(), vec.begin() + i * sortSize, vec.begin() + (i + 1) * sortSize);
			}
		}
		else
		{
			vecB.insert(vecB.end(), vec.begin() + i * sortSize, vec.begin() + (i + 1) * sortSize);
		}
	}
}

void vectorBinaryInsert(std::vector<int> & vecA, std::vector<int> & vecB, int ind, int sortSize, int exp)
{
	int upperBound = std::min(static_cast<int>(vecA.size() / sortSize), exp);
	int lowerBound = 0;
	int mid;

	ind --;
	while (upperBound > lowerBound)
	{	
		mid = (upperBound + lowerBound) / 2;
		if (vecB[ind * sortSize] > vecA[mid * sortSize])
		{
			lowerBound = mid + 1;
		}
		else 
		{
			upperBound = mid;
		}
	}

	vecA.insert(vecA.begin() + upperBound * sortSize, vecB.begin() + ind * sortSize, vecB.begin() + (ind + 1) * sortSize);
}

void vectorInsertion(std::vector<int> & vecA, std::vector<int> & vecB, int partitionMaxInd, int sizeMaxInd, int sortSize)
{
	int jacobsthalInd = 1;
	int jacobsthal = 1;
	int prevJacobsthal = 0;
	int ind = 1;
	int exp = 2;

	vectorBinaryInsert(vecA, vecB, 1, sortSize, exp);
	while (1)
	{
		getNextInd(ind, jacobsthalInd, prevJacobsthal, jacobsthal, exp);
		if (ind <= partitionMaxInd || (ind == partitionMaxInd + 1 && sizeMaxInd % 2 == 1))
		{
			vectorBinaryInsert(vecA, vecB, ind, sortSize, exp);
		}
		if (prevJacobsthal > partitionMaxInd)
		{
			break;
		}
	}
}
}

void PmergeMe::sortVector(std::vector<int> & vec, int sortSize)
{
	int sizeMaxInd;
	int partitionMaxInd;
	std::vector<int> vecA;
	std::vector<int> vecB;

	sizeMaxInd = vec.size() / sortSize;
	partitionMaxInd = sizeMaxInd / 2;
	if (sizeMaxInd < 2)
	{
		return ;
	}
	vectorSwapInsidePartition(vec, sortSize, partitionMaxInd);
	PmergeMe::sortVector(vec, sortSize * 2);
	vectorSeparatePairs(vec, vecA, vecB, sizeMaxInd, sortSize);
	vectorInsertion(vecA, vecB, partitionMaxInd, sizeMaxInd, sortSize);
	vec = vecA;
}