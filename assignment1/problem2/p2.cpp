#include <iostream>
#include "fraction.h"
using namespace std;
class FractionCalculator{
private:
    Fraction ans;
public:
    FractionCalculator(){
        char ch;
        while(true) {
            cout<<"+ addition two fractions"<<endl
                <<"- subtraction two fractions"<<endl
                <<"* multiplication two fractions"<<endl
                <<"/ divide two fractions"<<endl
                <<"(>,>=,<,<=,==) comparison two fractions"<<endl
                << "(r) reduce fraction"<<endl;
            cout<<endl
                <<"enter the operation: ";
            string option;
            cin>>option;
            if (ans.getNumber1() == 0 && ans.getNumber2() == 0) {
                Fraction obj1, obj2;
                if(option!="r") {
                    cout << "enter the first fraction: " << endl;
                    cin >> obj1;
                    cout << "enter the second fraction: " << endl;
                    cin >> obj2;
                }else{
                    cout << "enter the first fraction: " << endl;
                    cin >> obj1;
                    ans=obj1;
                }
                if (option == "+") {
                    ans = obj1 + obj2;
                } else if (option == "-") {
                    ans = obj1 - obj2;
                } else if (option == "*") {
                    ans = obj1 * obj2;
                } else if (option == "/") {
                    ans = obj1 / obj2;
                } else if (option == ">") {
                   if(obj1 > obj2){
                       cout<<"the first fraction is greater than second fraction"<<endl;
                   }else{
                       cout<<"the second fraction is greater than first fraction"<<endl;
                   }
                } else if (option == "<") {
                    if(obj1 < obj2){
                        cout<<"the first fraction is less than second fraction"<<endl;
                    }else{
                        cout<<"the first fraction is greater than second fraction"<<endl;
                    }
                } else if (option == ">=") {
                    if(obj1 >= obj2){
                        cout<<"the first fraction is greater than second fraction"<<endl;
                    }else{
                        cout<<"the first fraction is less than second fraction"<<endl;
                    }
                } else if (option == "<=") {
                    if(obj1 <= obj2){
                        cout<<"the first fraction is less than second fraction"<<endl;
                    }else{
                        cout<<"the first fraction is greater than second fraction"<<endl;
                    }
                } else if (option == "==") {
                    if(obj1 == obj2){
                        cout<<"the first fraction is equal second fraction"<<endl;
                    }else{
                        cout<<"the first fraction is not equal than second fraction"<<endl;
                    }
                }else if(option=="r"){
                    ans.reducing();
                }
            } else {
                Fraction obj;
                if(option!="r") {
                    cout << "enter the fraction: " << endl;
                    cin >> obj;
                }
                if (option == "+") {
                    ans = ans + obj;
                } else if (option == "-") {
                    ans = ans - obj;
                } else if (option == "*") {
                    ans = ans * obj;
                } else if (option == "/") {
                    ans = ans / obj;
                }else if (option == ">") {
                    if(ans > obj){
                        cout<<"the first fraction is greater than second fraction"<<endl;
                    }else{
                        cout<<"the second fraction is greater than first fraction"<<endl;
                    }
                } else if (option == "<") {
                    if(ans < obj){
                        cout<<"the first fraction is less than second fraction"<<endl;
                    }else{
                        cout<<"the first fraction is greater than second fraction"<<endl;
                    }
                } else if (option == ">=") {
                    if(ans >= obj){
                        cout<<"the first fraction is greater than second fraction"<<endl;
                    }else{
                        cout<<"the first fraction is less than second fraction"<<endl;
                    }
                } else if (option == "<=") {
                    if(ans <= obj){
                        cout<<"the first fraction is less than second fraction"<<endl;
                    }else{
                        cout<<"the first fraction is greater than second fraction"<<endl;
                    }
                } else if (option == "==") {
                    if(ans == obj){
                        cout<<"the first fraction is equal second fraction"<<endl;
                    }else{
                        cout<<"the first fraction is not equal than second fraction"<<endl;
                    }
                }else if(option=="r"){
                    ans.reducing();
                }
            }
            if(option!=">"&&option!="<"&& option!=">="&&option!="<="&&option!="=="){
                cout<<"the result is: ";
                cout<<ans<<endl;
            }
            cout<<"do you want to make another operation on the result,enter (Y,N): ";
            cin>>ch;
            if(ch=='N'||ch=='n')break;
        }
    }
};

int main()
{
    FractionCalculator F;

    return 0;
}




