#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    timeval start;
    timeval end;
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    try
    {
        gettimeofday(&start, NULL);
        std::cout << "Before: ";
        std::vector<int> vector = PmergeMe::parserArgsVector(argc, argv);
        std::vector<int> sorted = PmergeMe::sortVector(vector);
        std::cout << "After:  ";
        PmergeMe::printVector(sorted);
        gettimeofday(&end, NULL);
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << (end.tv_sec - start.tv_sec)*1e6 +(end.tv_usec - start.tv_usec) << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    try
    {
        gettimeofday(&start, NULL);
        std::deque<int> deque = PmergeMe::parserArgsDeque(argc, argv);
        std::deque<int> sorted = PmergeMe::sortDeque(deque);
        gettimeofday(&end, NULL);
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque :  " << (end.tv_sec - start.tv_sec)*1e6 +(end.tv_usec - start.tv_usec) << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}