#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP



#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cctype>

class ScalarConverter{
public:
    static void convert(const std::string &literal);
private:
    static const int CHAR_NUMERIC_MIN;
    static const int CHAR_NUMERIC_MAX;
    static const int INT_NUMERIC_MIN;
    static const int INT_NUMERIC_MAX;

    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    


    static void printChar( unsigned char c);
    static void printInt( int i);
    static void printFloat(float f);
    static void printDouble( double d);

    static bool isInt(const std::string &str, int &num);
    static bool isForChar(const std::string &str);
    static bool isForInt(const std::string &str);
    static bool isForFloat(const std::string &str);
    static bool isForDouble(const std::string &str);

    

};


#endif
