#include <iostream>
#include <stdexcept>
#include "mixedFraction.h"

using namespace std;

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n, d) {
    this->whole = whole;
}

MixedFraction::MixedFraction(const Fraction& frac) : Fraction(frac) {
    this->whole = 0;
}

MixedFraction operator+(const MixedFraction& lhs, const MixedFraction& rhs) {
    int n1 = lhs.getNum() + lhs.getDen() * lhs.whole;
    int n2 = rhs.getNum() + rhs.getDen() * rhs.whole;
    int d = lhs.getDen() * rhs.getDen();
    return MixedFraction(0, n1 * rhs.getDen() + n2 * lhs.getDen(), d);
}

MixedFraction operator-(const MixedFraction& lhs, const MixedFraction& rhs) {
    int n1 = lhs.getNum() + lhs.getDen() * lhs.whole;
    int n2 = rhs.getNum() + rhs.getDen() * rhs.whole;
    int d = lhs.getDen() * rhs.getDen();
    return MixedFraction(0, n1 * rhs.getDen() - n2 * lhs.getDen(), d);
}

MixedFraction operator*(const MixedFraction& lhs, const MixedFraction& rhs) {
    int n1 = lhs.getNum() + lhs.getDen() * lhs.whole;
    int n2 = rhs.getNum() + rhs.getDen() * rhs.whole;
    int d = lhs.getDen() * rhs.getDen();
    return MixedFraction(0, n1 * n2, d);
}

MixedFraction operator/(const MixedFraction& lhs, const MixedFraction& rhs) {
    int n1 = lhs.getNum() + lhs.getDen() * lhs.whole;
    int n2 = rhs.getNum() + rhs.getDen() * rhs.whole;
    int d = lhs.getDen() * rhs.getNum();
    if (d == 0) {
        throw invalid_argument("Division by zero");
    }
    return MixedFraction(0, n1 * rhs.getDen(), d * n2);
}

ostream& operator<<(ostream& os, const MixedFraction& frac) {
    os << frac.whole << " " << frac.getNum() << "/" << frac.getDen();
    return os;
}

