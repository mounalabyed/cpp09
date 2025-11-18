#include "PmergeMe.hpp"

#include <set>
#include <climits>

int main(int argc, char** argv) 
{
    if (argc < 2) 
    {
        std::cout << "Error: no input" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) 
    {
        std::string str = argv[i];
        for (size_t j = 0; j < str.length(); ++j) 
        {
            if (!isdigit(str[j])) 
            {
                std::cout << "Error" << std::endl;
                return 1;
            }
        }
        double num = strtod(str.c_str(),  NULL);
        if (num < 0 || num > INT_MAX) 
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
        if (std::find(vec.begin(), vec.end(), num) != vec.end())
        {
            std::cout << "Error: duplicate detected" << std::endl;
            return 1;
        }
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }

    std::cout << "vector--> Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "deque--> Before: ";
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << std::endl;

    PmergeMe sorter;
    clock_t startVec = clock();
    sorter.mergeInsertSort(vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) * 1e6 / CLOCKS_PER_SEC;

    clock_t startDeq = clock();
    sorter.mergeInsertSort(deq);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) * 1e6 / CLOCKS_PER_SEC ;

    std::cout << "vector--> After:  ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::cout << "deque--> After:  ";
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;

    return 0;
}
