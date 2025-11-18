#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

class PmergeMe 
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);
        ~PmergeMe();

        void mergeInsertSort(std::vector<int>& vec);
        void mergeInsertSort(std::deque<int>& deq);

    private:
        void pairElements(const std::vector<int>& vec, std::vector<int>& main, std::vector<int>& pend, int& unpaired);
        void pairElements(const std::deque<int>& deq, std::deque<int>& main, std::deque<int>& pend, int& unpaired);

        void recursiveSort(std::vector<int>& chain);
        void recursiveSort(std::deque<int>& chain);

        std::vector<size_t> Jacobsthal(size_t n);
        std::deque<size_t> JacobsthalDeque(size_t n);

        int binarySearch(const std::vector<int>& vec, int size, int value);
        int binarySearch(const std::deque<int>& deq, int size, int value);
};

#endif 