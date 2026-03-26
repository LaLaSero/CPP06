#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc!=2 || !argv[0] || !argv[1])
    {
        std::cerr << "Error: Invalid input format." <<std::endl;
        return(1);
    }
   ScalarConverter::convert(std::string(argv[1]));
    return (0);
}