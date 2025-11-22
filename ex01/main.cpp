#include"RPN.hpp"


int main(int argc , char *argv[])
{
    if (argc != 2) 
    {
        std::cout << "Usage: ./RPN \"expression\"\n";
        return 1;
    } 
    RPN a(argv[1]);
    return 0;

}