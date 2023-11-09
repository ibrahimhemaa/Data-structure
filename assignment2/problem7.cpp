#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   struct Node*right;
   struct Node*left;
};
struct Node*newnode(int data)
{
    struct Node*node = (struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    return(node);
};
void flip(struct Node*node)
{
    if (node==NULL)
    {
        return;
    }
    else
    {
      struct Node*tmp;
      flip(node->left);
      flip(node->right);
      tmp=node->left;
      node->left=node->right;
      node->right=tmp;
    }
}
void Inorder(struct Node*node)
{
    if(node==NULL)
        return;
    Inorder(node->left);
    cout<<node->data<<"  ";
    Inorder(node->right);
}



int main()
{
  struct Node*r1=newnode(1);
  r1->left=newnode(2);
  r1->right=newnode(3);
  r1->left->left=newnode(4);
  r1->left->right=newnode(5);
  cout<<"Test case 1"<<endl;
  cout<<"The inorder of the Main tree :"<<endl;
  Inorder(r1);
  flip(r1);
  cout<<endl;
  cout<<"The inorder of the Mirror tree :"<<endl;
  Inorder(r1);
  cout<<"\n----------------------------------------\n";
  struct Node*r2=newnode(1);
  r2->left=newnode(2);
  r2->right=newnode(3);
  r2->right->left=newnode(4);
  r2->right->right=newnode(5);
  cout<<"Test case 2"<<endl;
  cout<<"The inorder of the Main tree :"<<endl;
  Inorder(r2);
  flip(r2);
  cout<<endl;
  cout<<"The inorder of the Mirror tree :"<<endl;
  Inorder(r2);
  cout<<"\n----------------------------------------\n";
  struct Node*r3=newnode(1);
  r3->left=newnode(2);
  r3->right=newnode(3);
  r3->left->left=newnode(4);
  r3->left->right=newnode(5);
  r3->right->left=newnode(6);
  r3->right->right=newnode(7);
  cout<<"Test case 3"<<endl;
  cout<<"The inorder of the Main tree :"<<endl;
  Inorder(r3);
  flip(r3);
  cout<<endl;
  cout<<"The inorder of the Mirror tree :"<<endl;
  Inorder(r3);
  cout<<"\n----------------------------------------\n";
  struct Node*r4=newnode(1);
  r4->left=newnode(2);
  r4->right=newnode(3);
  r4->left->left=newnode(4);
  r4->left->right=newnode(5);
  r4->left->left->left=newnode(6);
  r4->right->right=newnode(7);
  cout<<"Test case 4"<<endl;
  cout<<"The inorder of the Main tree :"<<endl;
  Inorder(r4);
  flip(r4);
  cout<<endl;
  cout<<"The inorder of the Mirror tree :"<<endl;
  Inorder(r4);
  cout<<"\n----------------------------------------\n";
  struct Node*r5=newnode(1);
  r5->left=newnode(2);
  r5->right=newnode(3);
  r5->right->right=newnode(4);
  r5->right->left=newnode(5);
  r5->left->left=newnode(6);
  r5->left->right=newnode(7);
  r5->left->right->left=newnode(8);
  r5->left->right->right=newnode(9);
  cout<<"Test case 5"<<endl;
  cout<<"The inorder of the Main tree :"<<endl;
  Inorder(r5);
  flip(r5);
  cout<<endl;
  cout<<"The inorder of the Mirror tree :"<<endl;
  Inorder(r5);
  cout<<"\n----------------------------------------\n";
  return 0;
}
