#pragma once
#include "fraction.h"

class MixedFraction : public Fraction {
private:
    int whole;
public: 
MixedFraction(int whole, int n, int d); 
MixedFraction(const Fraction& Fraction);

friend MixedFraction operator+(const MixedFraction& lhs, const MixedFraction& rhs);
friend MixedFraction operator-(const MixedFraction& lhs, const MixedFraction& rhs);
friend MixedFraction operator*(const MixedFraction& lhs, const MixedFraction& rhs);
friend MixedFraction operator/(const MixedFraction& lhs, const MixedFraction& rhs);  // Throws exception if denominator is zero
friend std::ostream& operator<<(std::ostream& os, const MixedFraction& frac);
}; 