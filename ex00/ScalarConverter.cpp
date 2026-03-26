#include "ScalarConverter.hpp"

const int ScalarConverter::CHAR_NUMERIC_MIN = std::numeric_limits<char>::min();
const int ScalarConverter::CHAR_NUMERIC_MAX = std::numeric_limits<char>::max();
const int ScalarConverter::INT_NUMERIC_MIN = std::numeric_limits<int>::min();
const int ScalarConverter::INT_NUMERIC_MAX = std::numeric_limits<int>::max();

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter(){};

namespace
{
    bool shouldAppendDotZero(const std::string &formatted)
    {
        return (formatted.find('.') == std::string::npos
            && formatted.find('e') == std::string::npos
            && formatted.find('E') == std::string::npos);
    }
}


// print functions
void ScalarConverter::printChar(unsigned char c)
{
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
}
void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}
void ScalarConverter::printFloat(float f) {
    std::ostringstream oss;
    oss << f;
    const std::string formatted = oss.str();
    std::cout << "float: " << formatted;
    if (shouldAppendDotZero(formatted))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}
void ScalarConverter::printDouble(double d) {
    std::ostringstream oss;
    oss << d;
    const std::string formatted = oss.str();
    std::cout << "double: " << formatted;
    if (shouldAppendDotZero(formatted))
        std::cout << ".0";
    std::cout<<std::endl;
}


// conversion functions
bool ScalarConverter::isForChar(const std::string &str)
{
    if(str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
    {
        char c = str[0];
        printChar(static_cast<unsigned char>(c));
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
        return true;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string &str,int &num)
{
    std::istringstream iss(str);
    iss>>num;
    if (iss.fail() || !iss.eof()) 
        return false;
    return true;
}

bool ScalarConverter::isForInt(const std::string &str)
{
    int num;
    if(!isInt(str,num))
        return false;
    if (num > CHAR_NUMERIC_MAX || num < CHAR_NUMERIC_MIN)
        std::cout << "char: impossible" << std::endl; 
    else
        printChar(static_cast<unsigned char>(num));
    printInt(num);
    printFloat(static_cast<float>(num));
    printDouble(static_cast<double>(num));
    return true;
}

bool ScalarConverter::isForFloat(const std::string &str)
{
    float num;

    if (str.empty() || str[str.length()-1] != 'f')
        return false;
    std::string str_trimmed(str);
    str_trimmed.erase(str_trimmed.length() - 1);
    if (str_trimmed == "nan" || str_trimmed == "inf" || str_trimmed == "-inf" || str_trimmed == "+inf")
    {
        std::cout << "char: impossible"<<std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str_trimmed << std::endl;
        return true;
    }
    std::istringstream iss(str_trimmed);
    if (!(iss >> num) || !iss.eof()) 
        return false;
    if (num > CHAR_NUMERIC_MAX || num < CHAR_NUMERIC_MIN)
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<unsigned char>(num)); 
    if (num > INT_NUMERIC_MAX || num < INT_NUMERIC_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        printInt(static_cast<int>(num));
    printFloat(num);
    printDouble(static_cast<double>(num));
    return true;
}



bool ScalarConverter::isForDouble(const std::string &str)
{
    if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf")
    {
        std::cout << "char: impossible\nint: impossible\n";
        std::cout << "float: " << str << "f\n";
        std::cout << "double: " << str << std::endl;
        return true;
    }
    std::istringstream iss(str);
    double num;
    iss >> num;
    if (iss.fail() || !iss.eof()) 
        return false;
    if (num > CHAR_NUMERIC_MAX || num < CHAR_NUMERIC_MIN)
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<unsigned char>(num)); 
    if (num > INT_NUMERIC_MAX || num < INT_NUMERIC_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        printInt(static_cast<int>(num));
    printFloat(num);
    printDouble(static_cast<double>(num));
    return true;
}


void ScalarConverter::convert(const std::string &literal) {
    if (literal.empty())
    {
        std::cerr << "Error: Empty input." << std::endl;
        return;
    }
    if (isForChar(literal))
        return;
    if (isForInt(literal))
        return;
    if (isForFloat(literal))
        return;
    if (isForDouble(literal))
        return;
    std::cerr << "Error: Invalid input format." << std::endl;
}
