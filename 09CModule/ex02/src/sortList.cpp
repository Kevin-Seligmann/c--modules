#include "PmergeMe.hpp"

void getNextInd(int & ind, int & jacobsthalInd, int & prevJacobsthal, int & jacobsthal, int & exp);

void printList(std::list<int> & lst)
{
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it ++)
    {
		std::cout << *it ;
		std::cout << " ";
    }
}

void printListofLists(std::list<std::list<int> > & lists)
{
    for (std::list<std::list<int> >::iterator listIt = lists.begin(); listIt != lists.end(); listIt++)
    {
        std::cout << "List: ";
        printList(*listIt);
        std::cout << std::endl;
    }
}

void swapLists(std::list<std::list<int> > & lists, std::list<int> & extra)
{
    
    for (std::list<std::list<int> >::iterator it = lists.begin(); it != lists.end(); it ++)
    {
        std::list<std::list<int> >::iterator prev = it;
        it ++;
        if (it == lists.end())
        {
            return ;
        }
        (void) prev;
        (void) extra;
       std::list<std::list<int> >::iterator next = it;
        if (prev->front().front() < next->front().front())
        {
            prev->splice(prev->end(), next);
        }
        else
        {
            next->splice(next->end(), prev);
        }
    }
}


void PmergeMe::sortList(std::list<std::list<int> > & lists)
{
    std::list<int> extra;
    if (lists.size() < 2)
        return ;
  //  printListofLists(lists);
    swapLists(lists, extra);
    printListofLists(lists);

//    sortList(lists);
//    inserLists(lists);
}