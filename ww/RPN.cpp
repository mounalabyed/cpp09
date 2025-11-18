#include"RPN.hpp"

RPN::RPN() : vect() {}
RPN::RPN(const RPN &other) : vect(other.vect) {}
RPN::~RPN() {}
RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        vect = other.vect;
    }
    return *this;
}
bool RPN::is_valide_digit(std::string &nbr)
{
    int i =0;
    while(nbr[i])
    {
        if(!std::isdigit(nbr[i]))
            return false;
        i++;
    }
    int a = std::atoi(nbr.c_str());
    if(a >= 10)
        return false;
    return true;
}
bool  RPN::is_valide_operator(std::string &oper)
{
    if(oper.size() > 1)
        return false;
    if(oper[0] == '+' || oper[0] == '-' || oper[0] == '*' || oper[0] == '/')
    {
        return true;
    }
    return false;
}
