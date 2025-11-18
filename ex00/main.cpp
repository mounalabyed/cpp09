#include"BitcoinExchange.hpp"
#include<map>

int input(std::string file_name)
{
    std::string s = file_name;
    std::string s1;
    std::fstream f(s.c_str());
    if(!f)
    {
        std::cout << "Error: could not open file."<< std::endl;
        return 1;
    }
    getline(f, s1);
    while(getline(f, s1))
    {
        
    std::istringstream ss(s1);
        int pos = 0;
        pos = s1.find('|',pos);
        std::cout << " hii "<< s1<< std::endl;
        std::cout << "pos = "<<pos <<std::endl;
    if (pos == -1)
    {
        std::cout << "invalid input" << std::endl;
        break;
    }
    std::string key = trim(s1.substr(0, pos));
    std::string value = trim(s1.substr(pos+1, s1.size()));
        
        std::cout << "["<<key << "]" <<std::endl;
        std::cout << "["<<value << "]" <<std::endl;

    }
    return 1;
}
int main(int argc , char*argv[])
{
    if(argc != 2)
    {
        std::cout << "Error: could not open file."<< std::endl;
        return 1;
    }
    std::ifstream input(argv[1]);
    if(!input.is_open())
    {
        std::cout << "Error: could not open file."<< std::endl;
        return 1;
    }
    if (input.peek() == std::ifstream::traits_type::eof())
    {
         std::cout << "Error: file empty."<< std::endl;
        return 1;
    }
    BitcoinExchange a;
    std::string line ;
    getline(input, line);
    while(getline(input, line))
    {
        if (line.empty())
            continue;
        a.pars_line(line);
    }
  

}