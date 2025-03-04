#pragma once 
#include <stdexcept>

class Fraction {
private:  
    int num; 
    int den; 

public: 
    
    Fraction(); 

    // Parameterized constructor
    Fraction(int n, int d); 

    // Getters
    int getNum() const; 

    int getDen() const;
    
    // Setters
    void setNum(int n); 

    void setDen(int d); 

    // Simplify the fraction using the Euclidean Algorithm
    void simplify(); 

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);  // Throws exception if denominator is zero
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};
