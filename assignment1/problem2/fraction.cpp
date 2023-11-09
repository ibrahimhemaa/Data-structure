#include "fraction.h"

Fraction::Fraction()
{
   number1=number2=0;
}
Fraction::Fraction(int num1,int num2)
{
    number1=num1;
    number2=num2;
}
Fraction::Fraction(const Fraction& obj)
{
    number1=obj.number1;
    number2=obj.number2;
}
int Fraction::gcd(int N1,int N2){
    if(N2==0){
        return N1;
    }
    else return gcd(N2,N1%N2);
}
void Fraction::reducing(){
    int divid=gcd(number1,number2);
    number1/=divid;
    number2/=divid;
}
bool Fraction::operator==(const Fraction& obj2){
    if(number1==obj2.number1&&number2==obj2.number2){
        return 1;
    }
    else return 0;
}
bool Fraction::operator<(const Fraction& obj3){
    if((double)(number1/number2*1.0)<(double)(obj3.number1/obj3.number2*1.0)){
        return 1;
    }
    else return 0;

}
bool Fraction::operator>(const Fraction& obj4){
    if((double)(number1/number2*1.0)>(double)(obj4.number1/obj4.number2*1.0)){
        return 1;
    }
    else return 0;
}

bool Fraction::operator<=(const Fraction& obj5){
    if((double)(number1/number2*1.0)<=(double)(obj5.number1/obj5.number2*1.0)){
        return 1;
    }
    else return 0;
}
bool Fraction::operator>=(const Fraction& obj6){
    if((double)(number1/number2*1.0)>=(double)(obj6.number1/obj6.number2*1.0)){
        return 1;
    }
    else return 0;
}

istream& operator>>(istream& in, Fraction& sii){
    cout<<"please enter the fraction in form (x/y)"<<endl;
    char ch;
    while(in>>sii.number1>>ch>>sii.number2&&sii.number2==0){
        cout<<"invalid input,enter again"<<endl;
    }
    sii.reducing();
    return in;
}
ostream &operator<<(ostream& out, Fraction& soo){
    if(soo.number1==0)out<<0;
    else out<<soo.number1<<'/'<<soo.number2;
    return out;
}
Fraction Fraction::operator+(Fraction element){
    Fraction obj;
    obj.number1=number1*element.number2+element.number1*number2;
    obj.number2=number2*element.number2;
    obj.reducing();
    return obj;
}
Fraction Fraction::operator-(Fraction element){
    Fraction obj;
    obj.number1=number1*element.number2-element.number1*number2;
    obj.number2=number2*element.number2;
    obj.reducing();
    return obj;
}

Fraction Fraction::operator*(Fraction element){
    Fraction obj;
    obj.number1=number1*element.number1;
    obj.number2=number2*element.number2;
    obj.reducing();
    return obj;
}
Fraction Fraction::operator/(Fraction element){
    Fraction obj;
    obj.number1=number1*element.number2;
    obj.number2=number2*element.number1;
    obj.reducing();
    return obj;
}
Fraction::~Fraction() {}
int Fraction::getNumber1() {
    return number1;
}
int Fraction::getNumber2() {
    return number2;
}