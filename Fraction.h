//
// Created by Michael on 09.02.2020.
//

#ifndef S2LB1_1_FRACTION_H
#define S2LB1_1_FRACTION_H


#include <vector>
#include <ostream>
#include "RunTimeException.h"

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction();

    Fraction(int numerator, int denominator);

    Fraction reduction();

    Fraction plus(Fraction fraction);

    Fraction subtraction(Fraction fraction);

    Fraction multiply(Fraction fraction);

    Fraction division(Fraction fraction);

    void setNumerator(int numerator);

    int getNumerator();

    void setDenominator(int denominator);

    int getDenominator();

    void setFraction(Fraction fraction);

    void setFraction(int numerator, int denominator);

    double toDouble();

    friend std::ostream &operator<<(std::ostream &os, Fraction &fraction);
    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

    friend std::istream &operator>>(std::istream &in, Fraction &f);
    friend Fraction operator+ (Fraction f1, Fraction f2);
    friend Fraction operator- (Fraction f1, Fraction f2);
    friend Fraction operator* (Fraction f1, Fraction f2);
    friend Fraction operator/ (Fraction f1, Fraction f2);

private:
    std::vector<int> getPrimeNumbers(int numBefore);

    int getGCD(int num1, int num2);
};


#endif //S2LB1_1_FRACTION_H
