#include <iostream>
#include <set>
#include<string>
using namespace std;
set<string>st;
void RecPermute(string soFar, string rest)
{
    if (rest == "") // No more characters
        st.insert(soFar);
         // Print the word
    else // Still more chars
// For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
}
// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
}
int main(){
    string ss;
    cin>>ss;
    ListPermutations(ss);
    for (auto it:st) {
        cout<<it<<endl;
    }
    return 0;
}