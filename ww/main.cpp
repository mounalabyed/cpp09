#include<iostream>
#include"RPN.hpp"
#include<stack>
#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    RPN r;
    if (argc == 2)
    {
        std::istringstream ss(argv[1]);
        std::string token;
        std::vector<std::string> tokens;

        // Découper l'argument en tokens
        while (getline(ss, token, ' '))
        {
            if (!token.empty())
                tokens.push_back(token);
        }

        std::stack<int> s;

        for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            if (r.is_valide_digit(*it))
            {
                s.push(std::atoi(it->c_str()));
            }
            else if (r.is_valide_operator(*it))
            {
                if (s.size() < 2)
                {
                    std::cerr << "Error: invalid expression" << std::endl;
                    return 1;
                }
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                if (*it == "+") s.push(a + b);
                else if (*it == "-") s.push(a - b);
                else if (*it == "*") s.push(a * b);
                else if (*it == "/") s.push(a / b);
            }
            else
            {
                std::cerr << "Error" << std::endl;//: invalid token '" << *it << "'" << std::endl;
                return 1;
            }
        }

        if (s.size() != 1)
        {
            std::cerr << "Error: invalid expression" << std::endl;
            return 1;
        }

        std::cout << "  is " <<s.top() << std::endl;
    }
    else
    {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    return 0;
}
