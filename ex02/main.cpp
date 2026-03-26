#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base* generate(void) {
    int random = rand() % 3;

    if (random == 0)
    {
        std::cout << "Generated type: A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Generated type: B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated type: C" << std::endl;
        return new C();
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast&) {}
}
void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A";
    else if (dynamic_cast<B*>(p))
        std::cout << "B";
    else if (dynamic_cast<C*>(p))
        std::cout << "C";
    else
        std::cerr << "Error: unknown object type";
}
int main() {
    std::srand(std::time(NULL));

    Base *ptr = generate();

    Base &ref = *ptr;
    std::cout << "Identifying by pointer: ";
    identify(ptr);
    std::cout << "\nIdentifying by reference: ";
    identify(ref);
    delete ptr;
    return 0;
}
