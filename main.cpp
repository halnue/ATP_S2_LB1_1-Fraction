#include <iostream>
//#include "Fraction.h"
#include "Fraction.cpp"

#define PRINT(variable) std::cout << std::string(#variable) << " = "<<variable << std::endl;

int main() {
    Fraction fraction1 = Fraction(9,6);
    Fraction fraction2 = Fraction(2,5);
    PRINT(fraction1)
    PRINT(fraction2)
    PRINT(fraction1.toDouble())
    PRINT(fraction2.toDouble())
    PRINT(fraction1 + fraction2 )
    PRINT(fraction1 - fraction2)
    PRINT(fraction1 * fraction2 )
    PRINT(fraction1 / fraction2)
    std::cout << "Enter fraction3" << std::endl;
    Fraction fraction3;
    std::cin >> fraction3;
    PRINT(fraction3)
    return 0;
}

