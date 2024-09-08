#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mut;

	mut.push(1);
	mut.pop();
	for (int i = 0; i < 10; i ++)
	{
		mut.push(i);
	}
	for (MutantStack<int>::iterator it = mut.begin(); it != mut.end(); it ++)
	{
		std::cout << *it << std::endl;
	}
}
