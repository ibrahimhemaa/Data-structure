#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class BigInt{
private:
    string num;
    bool sign;
    int sz;
public:
    BigInt(string nu){
        if(nu[0]=='-')
            sign= true;
        else sign=false;
        int index=0;
        for (int i = 0; i <nu.size() ; ++i) {
            if(nu[i]!='0'&&nu[i]!='-'){
                index=i;
                break;
            }
        }
        num=nu.substr(index);
        sz=num.size();
    }
    BigInt(int nu){
        string temp= to_string(nu);
        if(temp[0]=='-')
            sign= true;
        else sign=false;
        int index=0;
        for (int i = 0; i <temp.size() ; ++i) {
            if(temp[i]!='0'&&temp[i]!='-'){
                index=i;
                break;
            }
        }
        num=temp.substr(index);
        sz=num.size();
    }
    int size(){
        return sz;
    }
    void operator=(BigInt& obj){
        num=obj.num;
        sign=obj.sign;
        sz=obj.sz;
    }
    string operator+(BigInt& obj){
        vector<int>ans(max(num.size(),obj.num.size())+1,0);
        int i=0;
        char ti='0';
        if((sign&&obj.sign)||(!sign&&!obj.sign)){
            reverse(obj.num.begin(),obj.num.end());
            reverse(num.begin(),num.end());
            for ( ; i <min(obj.num.size(),num.size()) ; ++i) {
                ans[i]=(int)(obj.num[i]-'0')+(int)(num[i]-'0');
            }
        }else if((!sign&&obj.sign)||(sign&&!obj.sign)){
            if(num>=obj.num&&sz>=obj.sz){
                reverse(obj.num.begin(),obj.num.end());
                reverse(num.begin(),num.end());
                for ( ; i <min(obj.num.size(),num.size()) ; ++i) {
                    ans[i] = ((int) (num[i] -ti) - (int) (obj.num[i] -'0'));
                    if(ans[i]<0){
                        ans[i]+=10;
                        ti='1';
                    }else{
                        ti='0';
                    }
                }
            }else {
                reverse(obj.num.begin(),obj.num.end());
                reverse(num.begin(),num.end());
                for ( ; i <min(obj.num.size(),num.size()) ; ++i) {
                    ans[i] = ((int) (obj.num[i] -ti) - (int) (num[i] -'0'));
                    if(ans[i]<0){
                        ans[i]+=10;
                        ti='1';
                    }else{
                        ti='0';
                    }
                }
            }
        }
        while(i<obj.num.size()){
            ans[i]=(int)(obj.num[i]-ti);
            ti='0';
            i++;
        }
        while(i<num.size()){
            ans[i]=(int)(num[i]-ti);
            ti='0';
            i++;
        }
        for (int j = 0; j <ans.size() ; ++j) {
            if(j==ans.size()-1)continue;
            if(ans[j]>9) {
                int temp = ans[j];
                ans[j] = temp % 10;
                ans[j + 1] += temp / 10;
            }
        }
        reverse(ans.begin(),ans.end());
        reverse(obj.num.begin(),obj.num.end());
        reverse(num.begin(),num.end());
        stringstream temp;
        int index= 0;
        if((sign&&!obj.sign)||(!sign&&obj.sign)){
            for (int j = 0; j <ans.size() ; ++j) {
                if(ans[j]){
                    index=j;
                    break;
                }
            }
            for (int j = index; j < ans.size(); ++j) {
                temp<<ans[j];
            }
        }else {
            for (int j = 0; j < ans.size(); ++j) {
                if (ans[j] ) {
                    index=j;
                    break;
                }
            }
            for (int j = index; j < ans.size(); ++j) {
                temp<<ans[j];
            }
        }
        string res;
        if(count(ans.begin(),ans.end(),0)==ans.size()){
            res='0';
        }else {
            if (sign && obj.sign) {
                res.push_back('-');
            }else if(sign && !obj.sign){
                if(num>obj.num||sz>obj.sz){
                    res.push_back('-');
                }
            }else if(obj.sign && !sign){
                if(num<obj.num||sz<obj.sz){
                    res.push_back('-');
                }
            }
            res += temp.str();
        }
        return res;
    }
    friend ostream& operator<<(ostream& out,BigInt& obj){
        if(obj.sign)
            out<<"number is: -"<<obj.num<<endl;
        else out<<"number is: "<<obj.num<<endl;
        return out;
    }
    ~BigInt(){}
};
int main() {

    cout<<"Case 1:"<<endl;
    string s1,s2;
    string res;
    s1="15874359416358943157946794";
    s2="548742167863068563065621479716863681368564613379";
    BigInt obj1(s1),obj2(s2);
    res=obj1+obj2;
    cout<<"the result is"<<endl;
    cout<<res<<endl;
    cout<<"/*******************************************************************/"<<endl;
    cout<<"Case 2:"<<endl;
    s1="-158743594163589431579467945257555512";
    s2="5487421678630685630656214797168636813616897359";
    BigInt obj3(s1),obj4(s2);
    res=obj3+obj4;
    cout<<"the result is"<<endl;
    cout<<res<<endl;
    cout<<"/*********************************************************************/"<<endl;
    cout<<"Case 3:"<<endl;
    s1="-1587435941635894315794679452575555124166302661";
    s2="-5487421678630685630656214797168636813616897359";
    BigInt obj5(s1),obj6(s2);
    res=obj5+obj6;
    cout<<"the result is"<<endl;
    cout<<res<<endl;
    cout<<"/**********************************************************************/"<<endl;
    cout<<"Case 4:"<<endl;
    s1="1587435941635894315794679452575555124166302661";
    s2="-5487421678630685630656214797168636813616897359";
    BigInt obj7(s1),obj8(s2);
    res=obj7+obj8;
    cout<<"the result is"<<endl;
    cout<<res<<endl;
    cout<<"/************************************************************************/"<<endl;
    cout<<"Case 5:"<<endl;
    int s3=64106541,s4=12358489;
    BigInt obj11(s3),obj12(s4);
    res=obj11+obj12;
    cout<<"the result is"<<endl;
    cout<<res<<endl;

    return 0;
}
