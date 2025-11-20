    
#include"BitcoinExchange.hpp"
#include <cctype> 
const char* BitcoinExchange:: Invalidata::what() const throw() 
{
    return  "Error : invalid data ";
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->data_ = other.data_;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other) 
    {
        this->data_ = other.data_;
    }
    return *this;
}
std::string trim(const std::string& str)
{
    size_t first = 0;
    while (first < str.size() && std::isspace(str[first]))
        ++first;

    size_t last = str.size();
    while (last > first && std::isspace(str[last - 1]))
        --last;

    return str.substr(first, last - first);
}

  BitcoinExchange::BitcoinExchange()
  {
    std::cout << ">>> Constructeur BitcoinExchange lancé <<<" << std::endl;
    std::string s1 = "data.csv";
    std::ifstream f(s1.c_str());
    if (!f)
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    
    
    std::string s2;
    getline(f, s2);
    while(getline(f, s2))
    {
        
        std::istringstream ss(s2);
        std::string data, value;
        if(!getline(ss, data, ',') || !getline(ss, value))
            continue ;
       // std::cout << " data = "<< data  << " value =  "<< value<<std::endl;
        data = trim(data);
        value = trim(value);
        data_[data] = std::strtof(value.c_str(), NULL);
     //std::cout << ">>> Fin du constructeur <<<" << std::endl;

    
        }
  }

std::string BitcoinExchange::cle(std::string x)
{
    std::map<std::string,float>::iterator it ;
    it = data_.find(x);
    if(it != data_.end())
    {
        return x;
    }
    else{
        std::cout << "string not foud in map"<< std::endl;
        return NULL;
    }
}
float BitcoinExchange::vleur(std::string y)
{
    return data_[y];
}
bool BitcoinExchange::valid_date(std::string &date)
{
    if(date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
   int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

     int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days_in_month[1] = 29;

    if (day < 1 || day > days_in_month[month - 1])
        return false;
 //   std::cout << " year= "<< year << " month =" << month<< " day= "<< day<<std::endl;
    return true;
}
float BitcoinExchange::get_date(std::string &date)
{
    std::map<std::string, float>::iterator it = data_.lower_bound(date);
    if(it == data_.begin() && it->first > date )
    {
        throw BitcoinExchange::Invalidata();
    }
    if(it == data_.end() || it->first != date)
        it--;
    return it->second;
}

void BitcoinExchange::pars_line(std::string &line)
{
   std::istringstream ss(line);
    std::string key_ , value_;
    if(!getline(ss, key_, '|') || !getline(ss, value_))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }
    key_ = trim(key_);
    value_ = trim(value_);
    if(! valid_date(key_))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }
    float value = atof(value_.c_str());
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    try{

        float rate = get_date(key_);
        float result = value * rate;
    
        std::cout << key_ << " => " << value << " = " << result << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
