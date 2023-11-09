//problem 7
#include <iostream>
#include<vector>
using namespace std;
void BiasedSort( vector<string>&v){
    int count=0;
    for (int i = 0; i < v.size(); i++) {
        if(v[i]=="Untitled")
        {
            swap(v[i],v[count]);
            count++;
        }
    }
    for (int i = count; i < v.size()- 1; i++) {
        for (int j = v.size() - 1; j > i; --j){
            if (v [j] < v[j-1])
                swap (v [j], v [j - 1]);
        }
    }
    for (int i = 0; i <v.size(); i++) {
        cout<<v[i]<<endl;
    }
}
int main()
{
    cout<<"please enter number of song \n";
    int n;cin>>n;
    vector<string>vec(n);
    cout<<"please enter your list of songs \n";
    for (int i = 0; i <n; i++) {
        cin>>vec[i];
    }
    cout<<"print sorted songs \n";
    BiasedSort(vec);
    return 0;
}