#include"PmergeMe.hpp"


bool PmergeMe::is_valide_digit(std::string &nbr)
{
    int i =0;
    while(nbr[i])
    {
        if(!std::isdigit(nbr[i]))
            return false;
        i++;
    }

    return true;
}