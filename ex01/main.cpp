#include"RPN.hpp"


int main(int argc , char *argv[])
{
    if(argc == 2)
    {
        RPN a(argv[1]);

    }
    else{
        std::cerr << "invalid argument "<< std::endl;
    }
}