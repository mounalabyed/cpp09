#include"RPN.hpp"

int RPN::calcule(const std::string &str)
{
    std::istringstream ss(str);
    std::string token;
    while(ss >> token)
    {
        if(token.size() == 1 && std::isdigit(token[0]))
            stack.push(token[0] - '0');
       
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if(stack.size() < 2)
            {
                throw NotEnoughOperands();
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int res;
            if(token == "+")
                res = a + b;
            else  if(token == "-")
                res = a - b;
            else if(token == "*")
                res = a * b;
            else
            {
                if(b == 0)
                    throw DivisionZero();
                res = a / b;
            }
            stack.push(res);
        }
        else
        {
            throw InvalidToken();
        }
    }
    if(stack.empty())
        throw EmptyStack();
    if(stack.size() != 1)
        throw InvalidToken();
    return stack.top();
}
RPN::RPN(const std::string &str)
{
    try{
        
       
        std::cout << calcule(str)<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what()<< std::endl;
    }
}
RPN::~RPN(){}
const char* RPN::NotEnoughOperands::what() const throw()
{
    return "Error: Not enough operands";
}

const char* RPN::InvalidToken::what() const throw()
{
    return "Error: Invalid RPN expression";
}

const char* RPN::DivisionZero::what() const throw()
{
    return "Error: Division by zero";
}

const char* RPN::EmptyStack::what() const throw()
{
    return "Error: Empty stack";
}