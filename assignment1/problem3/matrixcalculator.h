#ifndef MATRIX_CPP_MATRIXCULCULATOR_CUH
#define MATRIX_CPP_MATRIXCULCULATOR_CUH
#include <iostream>
#include "matrix.h"
using namespace std;
class MatrixCalc{
public:
    MatrixCalc(){
        cout << "Welcome to MR-Robot Matrix Calculator" << endl;
        while (true) {
            cout << "1- Perform Matrix Addition" << endl;
            cout << "2- Perform Matrix Subtraction" << endl;
            cout << "3- Perform Matrix Multiplication" << endl;
            cout << "4- Matrix Transpose" << endl;
            cout<<endl
                <<"enter the number of operation:";
            int num;
            cin >> num;
            int rows, cols, rows1, cols1;
            if (num == 1) {
                cout << "enter the size of first matrix" << endl;
                cin >> rows >> cols;
                cout << "enter the size of second matrix" << endl;
                cin >> rows1 >> cols1;
                if (rows1 == rows && cols1 == cols) {
                    Matrix<int> obj1(rows, cols), obj2(rows1, cols1), result;
                    cout << "enter the first matrix of size " << rows << "x" << cols << endl;
                    cin >> obj1;
                    cout << "enter the second matrix of size " << rows1 << "x" << cols1 << endl;
                    cin >> obj2;
                    result = obj1 + obj2;
                    cout << "the result matrix is: " << endl;
                    cout << result;
                } else {
                    cout << "can't addition two matrices" << endl;
                }
            } else if (num == 2) {
                cout << "enter the size of first matrix" << endl;
                cin >> rows >> cols;
                cout << "enter the size of second matrix" << endl;
                cin >> rows1 >> cols1;
                if (rows1 == rows && cols1 == cols) {
                    Matrix<int> obj1(rows, cols), obj2(rows1, cols1), result;
                    cout << "enter the first matrix of size " << rows << "x" << cols << endl;
                    cin >> obj1;
                    cout << "enter the second matrix of size " << rows1 << "x" << cols1 << endl;
                    cin >> obj2;
                    result = obj1 - obj2;
                    cout << "the result matrix is: " << endl;
                    cout << result;
                } else {
                    cout << "can't subtraction two matrices" << endl;
                }
            } else if (num == 3) {
                cout << "enter the size of first matrix" << endl;
                cin >> rows >> cols;
                cout << "enter the size of second matrix" << endl;
                cin >> rows1 >> cols1;
                if (cols == rows1) {
                    Matrix<int> obj1(rows, cols), obj2(rows1, cols1), result;
                    cout << "enter the first matrix of size " << rows << "x" << cols << endl;
                    cin >> obj1;
                    cout << "enter the second matrix of size " << rows1 << "x" << cols1 << endl;
                    cin >> obj2;
                    result = obj1 * obj2;
                    cout << "the result matrix is: " << endl;
                    cout << result;
                } else {
                    cout << "can't multiplication two matrices" << endl;
                }
            } else if (num == 4) {
                cout << "enter the size of matrix" << endl;
                cin >> rows >> cols;
                Matrix<int>obj1(rows,cols);
                cout << "enter the matrix of size " << rows << "x" << cols << endl;
                cin >> obj1;
                obj1.transpose();
            }else{
                cout<<"invalid number"<<endl;
            }
            cout<<"do you want to make another operation ,enter(Y or N)"<<endl;
            char x;
            cin>>x;
            if(x=='N'||x=='n')break;
        }
    }
};

#endif
