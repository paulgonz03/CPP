#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
        return (*this);
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

/************/
/*  VECTOR  */
/************/

void PmergeMe::printVector(std::vector<int> vector)
{
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::vector<int> PmergeMe::parserArgsVector(int argc, char **argv)
{
    std::vector<int> vector;

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg.empty() == true)
            throw std::invalid_argument("Empty arguments");
        for (long unsigned int j = 0; j < arg.length(); j++)
            if (!isdigit(arg[j]))
                throw std::invalid_argument("Invalid numbers");
        long number = atol(arg.c_str());
        if (number > 2147483647)
            throw std::out_of_range("Invalid numbers");
        if (argc == 2)
        {
            vector.push_back(static_cast<int>(number));
            printVector(vector);
            return (vector);
        }
        vector.push_back(static_cast<int>(number));
    }
    printVector(vector);
    return (vector);
}

void PmergeMe::insertVector(int nbr, std::vector<int> &big)
{
    size_t start = 0;
    size_t end = big.size();
    size_t middle = 0;
    while (start < end)
    {
        middle = (end + start) / 2;
        if (nbr > big[middle])
            start = middle + 1;
        else
            end = middle;
    }
    if (big[middle] < nbr)
        middle++;
    big.insert(big.begin() + middle, nbr);
}

void PmergeMe::findVector(std::vector<int> jacob, std::vector<int> small, std::vector<int> &big, int last)
{
    std::vector<int>::iterator posJacob = jacob.begin();
    while (posJacob != jacob.end())
    {
        insertVector(small.at(*posJacob - 1), big);
        posJacob++;
    }
    if (last >= 0)
        insertVector(last, big);
}

void PmergeMe::JacobsthalVector(std::vector<int> small, std::vector<int> &big, int last)
{
    size_t prev = 1;
    size_t curr = 3;

    std::vector<int> jacob;
    jacob.push_back(1);

    while (prev < small.size())
    {
        size_t limit = curr;
        if (limit > small.size())
            limit = small.size();

        for (size_t i = limit; i > prev; i--)
            jacob.push_back(i);

        size_t next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    findVector(jacob, small, big, last);
}

std::vector<int> PmergeMe::sortVector(std::vector<int> vector)
{
    if (vector.size() == 1)
        return vector;

    std::vector<int>::iterator first = vector.begin();
    std::vector<int>::iterator second = vector.begin();
    std::vector<int> small;
    std::vector<int> big;
    int last;
    second++;
    last = -1;
    while (first != vector.end() && second != vector.end())
    {
        if (*first < *second)
        {
            small.push_back(*first);
            big.push_back(*second);
        }
        else
        {
            big.push_back(*first);
            small.push_back(*second);
        }
        first++;
        first++;
        second++;
        second++;
    }
    if (vector.size() % 2 != 0)
        last = *first;

    std::vector<int> sortedBig = sortVector(big);
    JacobsthalVector(small, sortedBig, last);
    return (sortedBig);
}

/***********/
/*  DEQUE  */
/***********/

void PmergeMe::printDeque(std::deque<int> deque)
{
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::deque<int> PmergeMe::parserArgsDeque(int argc, char **argv)
{
    std::deque<int> deque;

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg.empty() == true)
            throw std::invalid_argument("Empty arguments");
        for (long unsigned int j = 0; j < arg.length(); j++)
            if (!isdigit(arg[j]))
                throw std::invalid_argument("Invalid numbers");
        long number = atol(arg.c_str());
        if (number > 2147483647)
            throw std::out_of_range("Invalid numbers");
        if (argc == 2)
        {
            deque.push_front(static_cast<int>(number));
            return (deque);
        }
        deque.push_front(static_cast<int>(number));
    }
    return (deque);
}

void PmergeMe::insertDeque(int nbr, std::deque<int> &big)
{
    size_t start = 0;
    size_t end = big.size();
    size_t middle = 0;
    while (start < end)
    {
        middle = (end + start) / 2;
        if (nbr > big[middle])
            start = middle + 1;
        else
            end = middle;
    }
    if (big[middle] < nbr)
        middle++;
    big.insert(big.begin() + middle, nbr);
}

void PmergeMe::findDeque(std::deque<int> jacob, std::deque<int> small, std::deque<int> &big, int last)
{
    std::deque<int>::iterator posJacob = jacob.begin();
    while (posJacob != jacob.end())
    {
        insertDeque(small.at(*posJacob - 1), big);
        posJacob++;
    }
    if (last >= 0)
        insertDeque(last, big);
}

void PmergeMe::JacobsthalDeque(std::deque<int> small, std::deque<int> &big, int last)
{
    size_t prev = 1;
    size_t curr = 3;

    std::deque<int> jacob;
    jacob.push_back(1);

    while (prev < small.size())
    {
        size_t limit = curr;
        if (limit > small.size())
            limit = small.size();

        for (size_t i = limit; i > prev; i--)
            jacob.push_back(i);

        size_t next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    findDeque(jacob, small, big, last);
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> deque)
{
    if (deque.size() == 1)
        return deque;

    std::deque<int>::iterator first = deque.begin();
    std::deque<int>::iterator second = deque.begin();
    std::deque<int> small;
    std::deque<int> big;
    int last;
    second++;
    last = -1;
    while (first != deque.end() && second != deque.end())
    {
        if (*first < *second)
        {
            small.push_back(*first);
            big.push_back(*second);
        }
        else
        {
            big.push_back(*first);
            small.push_back(*second);
        }
        first++;
        first++;
        second++;
        second++;
    }
    if (deque.size() % 2 != 0)
        last = *first;

    std::deque<int> sortedBig = sortDeque(big);
    JacobsthalDeque(small, sortedBig, last);
    return (sortedBig);
}