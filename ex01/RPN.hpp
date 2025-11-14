#ifndef RPN_HPP
#define RPN_HPP
#include<vector>
#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype> 
#include<sstream>
class RPN{
private:
std::vector<std::string> vect;
public :
    RPN();
    RPN(const RPN &other);
    ~RPN();
    RPN &operator=(const RPN &other);
bool is_valide_digit(std::string &nbr);
bool is_valide_operator(std::string &oper);


};

#endif