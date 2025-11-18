#ifndef RPN_HPP
#define RPN_HPP
#include<iostream>
#include<sstream>
#include<stack>

class RPN{
    private: 
    std::stack<int> stack;
    public :
    RPN(const std::string & str);
    ~RPN();
    int calcule( const std::string &str);
      class InvalidToken : public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };
        
        class NotEnoughOperands : public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };

        class DivisionZero : public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };
        
        class EmptyStack : public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };
};


#endif 