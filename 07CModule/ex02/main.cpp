#include <iostream>
#include <stdlib.h>
#include "Array.hpp"

void ownTests(void)
{
	Array<int> B(5);

	std::cout << std::endl << std::endl << "--- Basic ---"<< std::endl;
//	// Default initalization // Commented to not have init error, uncomment if necessary to demonstrate
//	for (int i = 0; i < 5; i ++)
//	{
//		std::cout << B[i] << " ";
//	}
//	std::cout << std::endl;

	// Changing some values
	for (int i = 0; i < 5; i ++)
	{
		B[i] = i;
	}
	for (int i = 0; i < 5; i ++)
	{
		std::cout << B[i] << " ";
	}
	std::cout << std::endl;

	// Copy constructor
	std::cout << std::endl << "--- Copy ---"<< std::endl;
	Array<int> C(B);
	B[1] = 10;
	C[0] = 10;

	for (int i = 0; i < 5; i ++)
	{
		std::cout << B[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i ++)
	{
		std::cout << C[i] << " ";
	}
	std::cout << std::endl;

	// Assignment
	std::cout << std::endl << "--- Assingment ---"<< std::endl;
	Array<int> D;
	D = C;
	D[4] = 20;
	C[3] = 20;
	for (int i = 0; i < 5; i ++)
	{
		std::cout << C[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i ++)
	{
		std::cout << D[i] << " ";
	}
	std::cout << std::endl;

	// Out of bounds
	std::cout << std::endl << "--- Out of bounds ---" << std::endl;
	try
	{
		Array<int> A;
		A[0] = 1;
	}
	catch (Array<int>::OutOfBoundsException & e)
	{
		std::cout << "Should happen ! - " << e.what() << std::endl;
	}

	try
	{
		B[5] = 0;
	}
	catch (Array<int>::OutOfBoundsException & e)
	{
		std::cout << "Should happen ! - " << e.what() << std::endl;
	}
}

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	ownTests(); // Own tests
    return 0;
}
