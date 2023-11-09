
#include <iostream>
using namespace std;
template<class T>
class node {
public:
    T data;
    node* left;
    node* right;
    node(int ele){
        data=ele;
        left=NULL;
        right=NULL;
    }
};
/* converts a tree to its mirror image */
template<class T>
void getmirror(node<T>* Node)
{
    if (Node == NULL)
        return;
    else {
        node<T>* temp;
        getmirror(Node->left);
        getmirror(Node->right);
        // swap the pointers in this node
        temp = Node->left;
        Node->left = Node->right;
        Node->right = temp;
    }
}
/* returns true if structure of
    two trees node1 and node2 is same*/
template<class T>
bool isequal(node<T>* node1, node<T>* node2)
{
    if (node1 == NULL && node2 == NULL) {
        return true;
    }
    if (node1 != NULL && node2 != NULL && isequal(node1->left, node2->right) && isequal(node1->right, node2->left)) {
        return true;
    }
    return false;
}
template<class T>
// Returns true if the given tree is foldable
bool isFoldable(node<T>*root)
{
    bool flag;
    // base case
    if (root == NULL)
        return true;
    // Compare the structures of the right subtree and opsite left subtree
    flag = isequal(root->left, root->right);
    return flag;
}


int main()
{
    //test1
    node<int>* root = new node<int>(1);
    root->left = new  node<int>(2);
    root->right = new node<int>(3);
    root->right->left = new node<int>(4);
    root->left->right = new node<int>(5);

    if (isFoldable(root)) {
        cout << "tree is foldable\n";
    }
    else {
        cout << "tree is not foldable\n";
    }

    //test2
    node<int>* root2 = new node<int>(1);
    root2->left = new  node<int>(2);
    root2->right = new node<int>(3);
    root2->left->left = new node<int>(4);
    root2->right->right = new node<int>(5);

    if (isFoldable(root2)) {
        cout << "tree is foldable\n";
    }
    else {
        cout << "tree is not foldable\n";
    }

    //test3
    node<int>* root3 = new node<int>(1);
    root3->left = new  node<int>(2);
    root3->right = new node<int>(3);
    root3->left->left = new node<int>(4);
    root3->left->right = new node<int>(6);
    root3->right->right = new node<int>(5);

    if (isFoldable(root3)) {
        cout << "tree is foldable\n";
    }
    else {
        cout << "tree is not foldable\n";
    }

    //test4
    node<int>* root4 = new node<int>(1);
    root4->left = new  node<int>(2);
    root4->right = new node<int>(3);
    root4->left->left = new node<int>(4);
    root4->right->left = new node<int>(5);

    if (isFoldable(root4)) {
        cout << "tree is foldable\n";
    }
    else {
        cout << "tree is not foldable\n";
    }
    //test5
    node<int>* root5=new node<int>(1);
    root5->left=new node<int>(2);
    root5->right=new node<int>(3);
    root5->left->left=new node<int>(4);
    root5->left->right=new node<int>(5);
    root5->right->left=new node<int>(6);
    root5->right->right=new node<int>(7);

    if (isFoldable(root5)) {
        cout << "tree is foldable\n";
    }
    else {
        cout << "tree is not foldable\n";
    }
    return 0;
}
