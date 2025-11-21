#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include<iostream>
#include<map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype> 
#include<sstream>
class  BitcoinExchange{
    private : 
    std::map<std::string, double>data_;

    public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);
   bool is_nmb(std::string &date);
   void pars_line(std::string &ref);
   void valid_date(std::string &data);
   void valid_value(std::string &date);
   float get_date(std::string &ref);
    class Invalidata: public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };
    class Invalidinput: public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };
     class Invalidnegativ: public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };
      class Invalidtolarge: public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };
      class Invalidfile: public std::exception
        {
            public :
                virtual const char* what() const throw() ;
        };
};
std::string trim(const std::string& str);
#endif /* F06629D1_3CC6_4DE9_80AA_0F4594724AE7 */
