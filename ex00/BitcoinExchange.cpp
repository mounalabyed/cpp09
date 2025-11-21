
#include "BitcoinExchange.hpp"
#include <cctype>

const char *BitcoinExchange::Invalidata::what() const throw()
{
    return "Error : invalid data. ";
}

const char *BitcoinExchange::Invalidfile::what() const throw()
{
    return "Error: could not open file.";
}
const char *BitcoinExchange::Invalidinput ::what() const throw()
{
    return "Error: bad input.";
}
const char *BitcoinExchange::Invalidnegativ ::what() const throw()
{
    return "Error: not a positive number.";
}
const char *BitcoinExchange::Invalidtolarge ::what() const throw()
{
    return "Error: too large a number.";
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->data_ = other.data_;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->data_ = other.data_;
    }
    return *this;
}
std::string trim(const std::string &str)
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
    std::string s1 = "data.csv";
    std::ifstream f(s1.c_str());
    if (!f)
    {
        throw BitcoinExchange::Invalidfile();
    }
    std::string s2;
    getline(f, s2);
    while (getline(f, s2))
    {
        std::istringstream ss(s2);
        std::string data, value;
        if (!getline(ss, data, ',') || !getline(ss, value))
            continue;
        data = trim(data);
        value = trim(value);
        data_[data] = std::strtof(value.c_str(), NULL);
    }
    f.close();
}

void BitcoinExchange::valid_value(std::string &value)
{
    std::istringstream ss(value);
    double v;
    ss >> v;
    if (ss.fail())
        throw BitcoinExchange::Invalidinput();
    char a;
    if (ss >> a)
        throw BitcoinExchange::Invalidinput();
    if (v < 0)
        throw BitcoinExchange::Invalidnegativ();
    if (v > 1000)
        throw BitcoinExchange::Invalidtolarge();
    return;
}
bool BitcoinExchange::is_nmb(std::string &date)
{
    std::istringstream ss(date);
    int a;
    char b;
    ss >> a;
    if (ss.fail())
        return false;
    if (ss >> b)
        return false;
    return true;
}
void BitcoinExchange::valid_date(std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw BitcoinExchange::Invalidinput();
    std::string y = date.substr(0, 4);
    std::string m = date.substr(5, 2);
    std::string d = date.substr(8, 2);
    std::istringstream ss(y);
    if (!is_nmb(y))
        throw BitcoinExchange::Invalidata();
    if (!is_nmb(m))
        throw BitcoinExchange::Invalidata();
    if (!is_nmb(d))
        throw BitcoinExchange::Invalidata();
    int year = atoi(y.c_str());
    int month = atoi(m.c_str());
    int day = atoi(d.c_str());

    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days_in_month[1] = 29;

    if (day < 1 || day > days_in_month[month - 1])
        throw BitcoinExchange::Invalidinput();
    return;
}

void BitcoinExchange::pars_line(std::string &line)
{
    std::istringstream ss(line);
    std::string key_, value_;
    if (!getline(ss, key_, '|') || !getline(ss, value_))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    key_ = trim(key_);
    value_ = trim(value_);
    try
    {
        valid_date(key_);
        valid_value(value_);
        double v = std::atof(value_.c_str());
        std::map<std::string, double>::iterator it = data_.lower_bound(key_);
        if (it == data_.begin() && it->first > key_)
        {
            std::cerr << "Error: no exchange rate available before 2009-01-02." << std::endl;
            return;
        }
        if (it == data_.end() || it->first != key_)
            it--;
        double rate = it->second;
        double result = v * rate;
        std::cout << key_ << " => " << value_ << " = " << result << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
