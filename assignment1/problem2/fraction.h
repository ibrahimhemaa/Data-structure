#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
using namespace std;
class Fraction
{
private:
    int number1;
    int number2;
public:
    Fraction();
    Fraction(int,int);
    Fraction(const Fraction& obj);
    int gcd(int ,int );
    void reducing();
    bool operator ==(const Fraction& obj2);
    bool operator <(const Fraction& obj3);
    bool operator >(const Fraction& obj4);
    bool operator <=(const Fraction& obj5);
    bool operator >=(const Fraction& obj6);
    friend istream& operator>>(istream& in, Fraction& sii);
    friend ostream& operator<<(ostream& out, Fraction& soo);
    Fraction operator+(Fraction element);
    Fraction operator-(Fraction element);
    Fraction operator*(Fraction element);
    Fraction operator/(Fraction element);
    int getNumber1();
    int getNumber2();
    ~Fraction();

};
#endif // FRACTION_H