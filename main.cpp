#include <iostream>
//#include "Fraction.h"
#include "Fraction.cpp"

#define PRINT(variable) std::cout << std::string(#variable) << " = "<<variable << std::endl;

int main() {
    Fraction fraction1 = Fraction(3,2);
    Fraction fraction2 = Fraction(1,2);
    PRINT(fraction1)
    PRINT(fraction2)
    PRINT(fraction1.toDouble())
    PRINT(fraction2.toDouble())
    PRINT(fraction1 + fraction2 )
    PRINT(fraction1 - fraction2)
    PRINT(fraction1 * fraction2 )
    PRINT(fraction1 / fraction2)
    return 0;
}

