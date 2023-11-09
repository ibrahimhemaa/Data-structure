
#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
   T data;
   Node* left=NULL, * right=NULL ;
};
template <class T>
//function to insert new node
Node<T>* insert(Node<T> *node, T key)
{
    //if tree is empty create a new node
    if (node == NULL){
        node= new Node<T>;
        node->data=key;
        node->left=node->right;
    }
    // if give key is less than node key-->go left subtree

    if (node->data > key)
        node->left = insert(node->left, key);
    // if give key is greater than node key-->go left subtree
    else if (node->data < key)
        node->right = insert(node->right, key);

    return node;

}
template <class T>
// function return sum of all element smaller than and equal to the kth element
int get_k_smallest(Node<T> *root, int k, int& cnt)
{
    // Base case
    if (root == NULL||cnt>k)
        return 0;
    //Transation
    // Compute sum of elements in left subtree
    int res = get_k_smallest(root->left, k, cnt);
    //check if cnt greater than or equal k;
    if (cnt >= k) {
        return res;
    }
    res += root->data;
    cnt++;
    //check if cnt greater than or equal k;
    if (cnt>= k) {
        return res;
    }
    // If count is less than k, return right subtree Nodes
    return res + get_k_smallest(root->right, k, cnt);
}


int main()
{

    //test1
    Node<int> *root = NULL;
    root = insert(root, 54);
    root = insert(root, 51);
    root = insert(root, 49);
    root = insert(root, 52);
    root = insert(root, 75);
    root = insert(root, 74);
    root = insert(root, 85);

    int k = 3;
    int cnt1=0;
    cout << "Sum of k smallest elements is " << get_k_smallest(root, k, cnt1) << endl;

    //test2
    Node<int> *root2 = NULL;
    root2 = insert(root2, 1);
    root2 = insert(root2, 2);
    root2 = insert(root2, 3);
    root2 = insert(root2, 4);
    root2 = insert(root2, 5);
    root2 = insert(root2, 6);
    root2 = insert(root2, 7);

    int k2 = 4;
    int cnt2=0;
    cout << "Sum of k smallest elements is " << get_k_smallest(root2, k2, cnt2) << endl;

    //test3
    Node<int> *root3 = NULL;
    root3 = insert(root3, 12);
    root3 = insert(root3, 22);
    root3 = insert(root3, 33);
    root3 = insert(root3, 44);
    root3 = insert(root3, 57);
    root3 = insert(root3, 68);
    root3 = insert(root3, 70);

    int k3 = 5;
    int cnt3=0;
    cout << "Sum of k smallest elements is " << get_k_smallest(root3, k3, cnt3) << endl;

    //test4
    Node<int> *root4 = NULL;
    root4 = insert(root4, 4);
    root4 = insert(root4, 5);
    root4 = insert(root4, 6);
    root4 = insert(root4, 8);
    root4 = insert(root4, 9);
    root4 = insert(root4, 10);
    root4 = insert(root4, 3);

    int k4 = 1;
    int cnt4=0;
    cout << "Sum of k smallest elements is " << get_k_smallest(root4, k4, cnt4) << endl;

    //test4
    Node<int> *root5 = NULL;
    root5 = insert(root5, 14);
    root5 = insert(root5, 52);
    root5 = insert(root5, 64);
    root5 = insert(root5, 87);
    root5 = insert(root5, 29);
    root5 = insert(root5, 10);
    root5 = insert(root5, 38);

    int k5 = 2;
    int cnt5=0;
    cout << "Sum of k smallest elements is " << get_k_smallest(root5, k5, cnt5) << endl;
    return 0;
}
