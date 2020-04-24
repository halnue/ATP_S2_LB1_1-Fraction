//
// Created by Michael on 09.02.2020.
//

#include <map>
#include <algorithm>
#include "Fraction.h"
#include "RunTimeException.h"

Fraction::Fraction() {
    Fraction(1, 1);
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

void Fraction::setFraction(Fraction fraction) {
    this->numerator = fraction.numerator;
    this->denominator = fraction.denominator;
}

int Fraction::getNumerator() { return numerator; }

int Fraction::getDenominator() { return denominator; }

void Fraction::setNumerator(int numerator) { this->numerator = numerator; }

void Fraction::setDenominator(int denominator) { this->denominator = denominator; }

Fraction Fraction::reduction() {
    if (numerator == denominator)
        return Fraction(1, 1);
    else if (numerator == 0)
        return Fraction(numerator, denominator);
    else if (denominator == 0)
        throw RunTimeException();
    else {
        int gcd = getGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        return Fraction(numerator, denominator);
    }
}

Fraction Fraction::plus(Fraction fraction) {
    Fraction fractionResult = Fraction(numerator * fraction.denominator + fraction.numerator * denominator,
                                       denominator * fraction.denominator);
    return fractionResult.reduction();
}

Fraction Fraction::subtraction(Fraction fraction) {
    Fraction fractionResult = Fraction(numerator * fraction.denominator - fraction.numerator * denominator,
                                       denominator * fraction.denominator);
    return fractionResult.reduction();
}

Fraction Fraction::multiply(Fraction fraction) {
    Fraction fractionResult = Fraction(numerator * fraction.numerator, denominator * fraction.denominator);
    return fractionResult.reduction();
}

Fraction Fraction::division(Fraction fraction) {
    Fraction fractionResult = Fraction(numerator * fraction.denominator, denominator * fraction.numerator);
    return fractionResult.reduction();
}


std::vector<int> Fraction::getPrimeNumbers(int numBefore) {
    std::vector<int> list = {2};
    for (int i = 3; i < /*2147483647*/numBefore; ++i) {
        bool isPrimeNum = false;
        for (int primeNum:list) {
            if (i % primeNum == 0) {
                isPrimeNum = false;
                break;
            } else
                isPrimeNum = true;
        }
        if (isPrimeNum) {
            list.push_back(i);
        }
    }
    return list;
}

int Fraction::getGCD(int num1, int num2) {
    std::vector<int> nums = {num1, num2};
    std::vector<std::vector<int>> listDivs{};
    for (int i = 0; i < nums.size(); ++i) {
        listDivs.push_back(std::vector<int>());
    }
    std::vector<int> listPrimeNumbers = getPrimeNumbers(120);

    for (int j = 0; j < nums.size(); ++j) {
        int quotient = nums[j];
        while (quotient != 1 && quotient != -1) {
            for (auto div: listPrimeNumbers) {
                if (quotient % div == 0) {
                    quotient /= div;
                    listDivs[j].push_back(div);
                }
            }
        }
    }
    struct {
        bool operator()(int a, int b) const {
            return a < b;
        }
    } customLess;
    std::sort(listDivs[0].begin(), listDivs[0].end(), customLess);
    std::sort(listDivs[1].begin(), listDivs[1].end(), customLess);
    std::map<int, int> mapDiv1 = {};
    std::map<int, int> mapDiv2 = {};
    std::vector<std::map<int, int>> maps = {mapDiv1, mapDiv2};
    for (int k = 0; k < nums.size(); ++k) {
        for (int div :listDivs[k]) {
            maps[k][div] += 1;
        }
    }
    int gcd = 1;
    for (auto i : maps[0])
        for (auto j : maps[1])
            if (i.first == j.first)
                gcd *= i.first;
    return gcd;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    Fraction result = fraction;
    result.reduction();
    if (result.getDenominator() == 1) {
        os << result.getNumerator();
    } else {
        os << result.getNumerator() << "/" << result.getDenominator();
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, Fraction &fraction) {
    Fraction result = fraction;
    result.reduction();
    if (result.getDenominator() == 1) {
        os << result.getNumerator();
    } else {
        os << result.getNumerator() << "/" << result.getDenominator();
    }
    return os;
}

std::istream &operator>>(std::istream &in, Fraction &f) {
    int numerator, denominator;
    in >> numerator >> denominator;
    f.setNumerator(numerator);
    f.setDenominator(denominator);
    return in;
}

Fraction operator+(Fraction f1, Fraction f2) {
    return f1.plus(f2);
}

Fraction operator-(Fraction f1, Fraction f2) {
    return f1.subtraction(f2);
}

Fraction operator*(Fraction f1, Fraction f2) {
    return f1.multiply(f2);
}

Fraction operator/(Fraction f1, Fraction f2) {
    return f1.division(f2);
}

double Fraction::toDouble() {
    return (double)numerator/(double)denominator;
}

void Fraction::setFraction(int numerator, int denominator) {
    setFraction(Fraction(numerator,denominator));
}


