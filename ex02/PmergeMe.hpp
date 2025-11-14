#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stdlib.h>
class PmergeMe{

private:
public:
std::vector<std::pair< unsigned int, unsigned int> > stor;
std::vector<unsigned int> largest;
std::vector<unsigned int> smallest;
bool is_valide_digit(std::string &ref);

};

#endif