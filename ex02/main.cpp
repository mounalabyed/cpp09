#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

std::vector<int> jacobsthal(int n)
{
    std::vector<int> vect;
    int j_0 = 0;
    int j_1 = 1;
    int jn_2 = j_0;
    int jn_1 = j_1;
    int j =0;
    // storer les order des indice selon jacohbstal 
    // ignore 0 pour jacohbstal
    // if(j_1 <= n -1)
    //     vect.push_back(1);
    while(true)
    {
        j = jn_1 + 2 * jn_2;
        if(j > n -1)
            break;
        vect.push_back(j);
  jn_2 = jn_1;  // ancienne valeur de jn_1 devient jn_2
jn_1 = j; ;
    }
    // ajouter les indice qui reste en decroissant 
    for(int i = n-1 ; i >= 0; i--)
    {
        bool found = 0;
        for(size_t j = 0; j < vect.size(); j++)
        {
            if(vect[j] == i)
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
           // std::cout << " i = "<< i<< " j "<< j << std::endl;
            vect.push_back(i);
        }
    }
    //  std::vector<int>::iterator it ;
    // for(it = vect.begin(); it != vect.end(); it++)
    // {
    //     std::cout << " suite = "<< *it << std::endl;
    // }
    return vect;
}
void insert_ft(std::vector<unsigned int> &vect, unsigned int value)
{
    std::vector<unsigned int>::iterator it= vect.begin();
    while(it != vect.end() && *it < value)
    {
        it++;
    }
    vect.insert(it, value);
}
int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        clock_t start = clock();
        PmergeMe a;
        std::string pair_one;
        std::string pair_;
        bool has_orpholan = false;
        int orpholan;
        int hold2;
        int hold1;
        int i = 1;
        // 11111111111________________>stor the data in vect<int, int> and stor orpholan if is
        while (i < argc)
        {
            pair_one = argv[i];
            hold1 = std::atoi(pair_one.c_str());
            if (!a.is_valide_digit(pair_one))
            {
                std::cout << "Error" << std::endl;
                return 1;
            }
            if (i + 1 < argc && argv[i + 1])
            {
                pair_ = argv[i + 1];
                if (!a.is_valide_digit(pair_))
                {
                    std::cout << "Error" << std::endl;
                    return 1;
                }
                hold2 = std::atoi(pair_.c_str());
                a.stor.push_back(std::make_pair(hold1, hold2));
                i++;
            }
            else
            {
                pair_one = argv[i];
                orpholan = std::atoi(pair_one.c_str());
                has_orpholan = true;
            }
            i++;
        }

        std::vector<std::pair<unsigned int, unsigned int> >::iterator it;
        // if (has_orpholan)
        // {
        //     std::cout << " orpholin is : " << orpholan << std::endl;
        // }
        // 2222_______________>swap the nmbr if the first is grather
        for (it = a.stor.begin(); it != a.stor.end(); it++)
        {
            if (it->first > it->second)
            {
                std::swap(it->first, it->second);
            }
        }
        // 333-________________> extract the seconde elemet metre dans un vect est firt dans un smallest

        for (it = a.stor.begin(); it != a.stor.end(); it++)
        {
            a.largest.push_back(it->second);
            a.smallest.push_back(it->first);
        }
        // std::vector<unsigned int>::iterator it2;
        // for (it2 = a.smallest.begin(); it2 != a.smallest.end(); it2++)
        // {
            //     std::cout << " smalstt    = " << *it2 << std::endl;
            // }
            // trie largest vect
            //  std::vector<unsigned int >::iterator it1;
            if(has_orpholan)
            a.largest.insert(a.largest.begin(), orpholan);
            std::sort(a.largest.begin(), a.largest.end());
            std::vector<int> indice = jacobsthal(a.smallest.size());
            std::vector<int>::iterator e;
            for(e = indice.begin(); e !=indice.end() ; e++)
            {
                int in = *e;
                //  std::cout << " value "<< a.smallest[in]<< std::endl;
                insert_ft(a.largest, a.smallest[in]);
            }
            std::vector<unsigned int>::iterator e1 ;
             std::vector<std::pair<unsigned int, unsigned int> >::iterator it1;
            std::cout << "Before: " ;
            for (it1 = a.stor.begin(); it1 != a.stor.end(); it1++)
            {
                std::cout << " "<<it1->first<< " " << it1->second;
            }
            if(has_orpholan)
                std::cout << " "<< orpholan<< std::endl;
            std::cout << "After: ";
       for(e1 = a.largest.begin(); e1 != a.largest.end(); e1++)
       {
        std::cout << *e1 << " "; 
       }
       std::cout << "\n";
        

    clock_t end = clock();    // end time

    double duration_us = double(end - start) / CLOCKS_PER_SEC * 1e6; // microseconds

    std::cout << "Time to process a range of 5 elements with std::sort : "
              << duration_us << " us" << std::endl;
    }

    else
    {
        std::cout << " invalid argument\n";
    }
}