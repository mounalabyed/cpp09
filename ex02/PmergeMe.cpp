#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) 
{ 
    *this = src; 
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) 
{ 
    (void)src; 
    return *this; 
}

PmergeMe::~PmergeMe() {}

void PmergeMe::pairElements(const std::vector<int>& vec, std::vector<int>& main, std::vector<int>& pend, int& unpaired) 
{
    size_t i = 0;
    while (i + 1 < vec.size()) 
    {
        if (vec[i] < vec[i + 1]) 
        {
            pend.push_back(vec[i]);
            main.push_back(vec[i + 1]);
        } 
        else 
        {
            pend.push_back(vec[i + 1]);
            main.push_back(vec[i]);
        }
        i += 2;
    }

    if (vec.size() % 2 != 0)
        unpaired = vec.back();
    else
        unpaired = -1;
}

void PmergeMe::pairElements(const std::deque<int>& deq, std::deque<int>& main, std::deque<int>& pend, int& unpaired) 
{
    size_t i = 0;
    while (i + 1 < deq.size()) 
    {
        if (deq[i] < deq[i + 1]) 
        {
            pend.push_back(deq[i]);
            main.push_back(deq[i + 1]);
        } 
        else 
        {
            pend.push_back(deq[i + 1]);
            main.push_back(deq[i]);
        }
        i += 2;
    }
    if (deq.size() % 2 != 0)
        unpaired = deq.back();
    else
        unpaired = -1;
}

void PmergeMe::recursiveSort(std::vector<int>& chain) 
{
    if (chain.size() <= 1) 
        return;
    size_t mid = chain.size() / 2;
    std::vector<int> left(chain.begin(), chain.begin() + mid);
    std::vector<int> right(chain.begin() + mid, chain.end());
    recursiveSort(left);
    recursiveSort(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), chain.begin());
}

void PmergeMe::recursiveSort(std::deque<int>& chain) 
{
    if (chain.size() <= 1) 
        return;
    size_t mid = chain.size() / 2;
    std::deque<int> left(chain.begin(), chain.begin() + mid);
    std::deque<int> right(chain.begin() + mid, chain.end());
    recursiveSort(left);
    recursiveSort(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), chain.begin());
}

int PmergeMe::binarySearch(const std::vector<int>& vec, int size, int value) 
{
    int first = 0;
    int end = size - 1;
    while (first <= end) 
    {
        int mid = (first + end) / 2;
        if (value == vec[mid]) 
            return mid;
        else if (value < vec[mid]) 
            end = mid - 1;
        else 
            first = mid + 1;
    }
    return first;
}

int PmergeMe::binarySearch(const std::deque<int>& deq, int size, int value) 
{
    int first = 0;
    int end = size - 1;
    while (first <= end) 
    {
        int mid = (first + end) / 2;
        if (value == deq[mid]) 
            return mid;
        else if (value < deq[mid]) 
            end = mid - 1;
        else   
            first = mid + 1;
    }
    return first;
}

std::vector<size_t> PmergeMe::Jacobsthal(size_t n) 
{
    std::vector<size_t> order;
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

    for (size_t i = 2; i < jacob.size(); ++i) 
    {
        if (jacob[i] >= n)
            break;
        order.push_back(jacob[i]);
    }
    for (size_t i = 0; i < n; ++i) 
    {
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }
    return order;
}

std::deque<size_t> PmergeMe::JacobsthalDeque(size_t n) 
{
    std::deque<size_t> order;
    std::deque<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

    for (size_t i = 2; i < jacob.size(); ++i) 
    {
        if (jacob[i] >= n)
            break;
        order.push_back(jacob[i]);
    }
    for (size_t i = 0; i < n; ++i) 
    {
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }
    return order;
}

 
void PmergeMe::mergeInsertSort(std::vector<int>& vec) 
{
    std::vector<int> main;
    std::vector<int> pend;
    int unpaired;
    pairElements(vec, main, pend, unpaired);
    recursiveSort(main);
    std::vector<size_t> order = Jacobsthal(pend.size());
    for (size_t i = 0; i < order.size(); ++i) 
    {
        if (order[i] < pend.size()) 
        {
            int pos = binarySearch(main, main.size(), pend[order[i]]);
            main.insert(main.begin() + pos, pend[order[i]]);
        }
    }
    if (unpaired != -1) 
    {
        int pos = binarySearch(main, main.size(), unpaired);
        main.insert(main.begin() + pos, unpaired);
    }
    vec = main;
}

void PmergeMe::mergeInsertSort(std::deque<int>& deq) 
{
    std::deque<int> main;
    std::deque<int> pend;
    int unpaired;
    pairElements(deq, main, pend, unpaired);
    recursiveSort(main);
    std::deque<size_t> order = JacobsthalDeque(pend.size());
    for (size_t i = 0; i < order.size(); ++i) 
    {
        if (order[i] < pend.size()) 
        {
            int pos = binarySearch(main, main.size(), pend[order[i]]);
            main.insert(main.begin() + pos, pend[order[i]]);
        }
    }
    
    if (unpaired != -1) 
    {
        int pos = binarySearch(main, main.size(), unpaired);
        main.insert(main.begin() + pos, unpaired);
    }
    deq = main;
}
