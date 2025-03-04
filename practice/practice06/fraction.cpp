#include "Fraction.h"
#include <iostream>
#include <stdexcept>

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    num = n;
    den = d;
    simplify();
}

int Fraction::getNum() const {
    return num;
}

int Fraction::getDen() const {
    return den;
}

void Fraction::setNum(int n) {
    num = n;
    simplify();
}

void Fraction::setDen(int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    den = d;
    simplify();
}

void Fraction::simplify() {
    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    num /= gcd;
    den /= gcd;
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int n = lhs.num * rhs.den + rhs.num * lhs.den;
    int d = lhs.den * rhs.den;
    return Fraction(n, d);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int n = lhs.num * rhs.den - rhs.num * lhs.den;
    int d = lhs.den * rhs.den;
    return Fraction(n, d);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int n = lhs.num * rhs.num;
    int d = lhs.den * rhs.den;
    return Fraction(n, d);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    int n = lhs.num * rhs.den;
    int d = lhs.den * rhs.num;
    return Fraction(n, d);
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.num << "/" << frac.den;
    return os;
}
