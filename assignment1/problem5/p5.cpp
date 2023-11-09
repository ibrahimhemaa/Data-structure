#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class studentName{
private:
    string name;
public:
    studentName(string s){
        name=s;
        int cnt=0;
        string temp;
        for (int i = 0; i <name.size() ; ++i) {
            if(name[i]==' '){
                cnt++;
                temp.clear();
            }else{
                temp.push_back(name[i]);
            }
        }
        if(cnt==1){
            name+=' ';
            name+=temp;
        }else if(cnt==0){
            name+=' ';
            name+=temp;
            name+=' ';
            name+=temp;
        }
    }
    bool replace(int pos1,int pos2){
        vector<string>na;
        string temp;
        for (int i = 0; i <name.size() ; ++i) {
            if(name[i]==' '){
                na.push_back(temp);
                temp.clear();
            }else{
                temp.push_back(name[i]);
            }
        }
        na.push_back(temp);
        pos1--;
        pos2--;
        if((pos1>=0&&pos1<na.size())&&(pos2>=0&&pos2<na.size())){
            swap(na[pos1],na[pos2]);
            name="";
            for (int i = 0; i <na.size() ; ++i) {
                name+=na[i];
                if(i!=na.size()-1)
                    name+=' ';
            }
            return true;
        }else{
            cout<<"invalid input,out of range"<<endl;
            return false;
        }
    }
    void print(){
        int j=1;
        string temp;
        for (int i = 0; i <name.size() ; ++i) {
            if(name[i]==' '){
                cout<<j++<<") "<<temp<<endl;
                temp.clear();
            }else{
                temp.push_back(name[i]);
            }
        }
        cout<<j++<<") "<<temp<<endl;
    }

};
int main() {

    cout<<"Case 1:"<<endl;
    string s1;
    s1="ahmed Mohamed sayed";
    studentName obj(s1);
    obj.replace(1,3);
    obj.print();
    cout<<"/**************************************************/"<<endl;
    cout<<"Case 2:"<<endl;
    s1="sara ahmed";
    studentName obj2(s1);
    obj2.replace(1,4);
    obj2.print();
    cout<<"/**************************************************/"<<endl;
    cout<<"Case 3:"<<endl;
    s1="Khaled";
    studentName obj3(s1);
    obj3.replace(1,2);
    obj3.print();
    cout<<"/**************************************************/"<<endl;
    cout<<"Case 4:"<<endl;
    s1="aya ali ahmed sayed";
    studentName obj4(s1);
    obj4.replace(1,2);
    obj4.print();
    cout<<"/**************************************************/"<<endl;
    cout<<"Case 5:"<<endl;
    s1="zeyad farag mohamed";
    studentName obj5(s1);
    obj5.replace(1,2);
    obj5.print();


    return 0;
}
