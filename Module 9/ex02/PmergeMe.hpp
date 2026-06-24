#pragma once

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#include <sys/time.h>

class PmergeMe
{
    private:
        static void insertVector(int nbr, std::vector<int> &big);
        static void JacobsthalVector(std::vector<int> small, std::vector<int> &big, int last);
        static void findVector(std::vector<int> jacob, std::vector<int> small, std::vector<int> &big, int last);

        static void insertDeque(int nbr, std::deque<int> &big);
        static void JacobsthalDeque(std::deque<int> small, std::deque<int> &big, int last);
        static void findDeque(std::deque<int> jacob, std::deque<int> small, std::deque<int> &big, int last);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        static std::vector<int> parserArgsVector(int argc, char **argv);
        static void printVector(std::vector<int> vector);
        static std::vector<int> sortVector(std::vector<int> vector);

        static std::deque<int> parserArgsDeque(int argc, char **argv);
        static void printDeque(std::deque<int> vector);
        static std::deque<int> sortDeque(std::deque<int> vector);
};
