#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack{ // a stack uses one queue
private:
    queue<int>q;
public:
    void push(int v)
    {
      int s =q.size(); // to get previous size of queue
      q.push(v);
      for(int i=0;i<s;i++) // dequeue all previous elements & put them after the pushed v
      {
        q.push(q.front()); //pushing all previous elements to rear of queue
        q.pop();// after each pushed element delete it from front
      }
    }
    void pop()//remove top val
    {
        if(q.empty())
            cout<<"It has no elements\n";
        else
            q.pop();
    }
    int top() //getting the top
    {
       return (q.empty())? -1 : q.front();
    }
};


int main()
{
   Stack n;
   n.push(30);
   n.push(7);
   n.pop();
   n.push(4);
   cout<<n.top()<<endl;
   return 0;
}
