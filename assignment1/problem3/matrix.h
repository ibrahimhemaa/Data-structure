#ifndef MAIN_CPP_MATRIX_H
#define MAIN_CPP_MATRIX_H
using namespace std;
template<class type>
class Matrix{
private:
    type** arr;
    int rows, cols;
public:
    Matrix(){}
    Matrix(int r,int c){
        rows=r;
        cols=c;
        arr=new type*[rows];
        for (int i = 0; i <rows ; ++i) {
            arr[i]=new type[cols];
        }
        for (int i = 0; i <rows ; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j]=0;
            }
        }
    }
    Matrix(const Matrix<type>&obj){
        rows=obj.rows;
        cols=obj.cols;
        arr=new type*[rows];
        for (int i = 0; i <rows ; ++i) {
            arr[i]=new type[cols];
        }
        for (int i = 0; i < obj.rows; ++i) {
            for (int j = 0; j <obj.cols ; ++j) {
                arr[i][j]=obj.arr[i][j];
            }
        }
    }

    Matrix<type> operator+(Matrix<type>& obj){
        Matrix<type>temp(rows,cols);
        for (int i = 0; i <rows ; ++i) {
            for (int j = 0; j <cols ; ++j) {
                temp.arr[i][j]=arr[i][j]+obj.arr[i][j];
            }
        }
        return temp;
    }
    Matrix<type> operator-(Matrix<type>& obj){
        Matrix<type>temp(rows,cols);
        for (int i = 0; i <rows ; ++i) {
            for (int j = 0; j <cols ; ++j) {
                temp.arr[i][j]=arr[i][j]-obj.arr[i][j];
            }
        }
        return temp;
    }
    Matrix<type> operator*(Matrix<type>&obj){
        if(cols==obj.rows) {
            Matrix<type> temp(rows, obj.cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < obj.cols; ++j) {
                    type sum = 0;
                    for (int k = 0; k < cols; ++k) {
                        sum += (arr[i][k] * obj.arr[k][j]);
                    }
                    temp.arr[i][j] += sum;
                }
            }
            return temp;
        }
    }

    friend istream& operator>>(istream& in,Matrix<type>&obj){
        for (int i = 0; i <obj.rows ; ++i) {
            for (int j = 0; j <obj.cols ; ++j) {
                in>>obj.arr[i][j];
            }
        }
        return in;
    }
    friend ostream& operator<<(ostream& out,Matrix<type>&obj){
        for (int i = 0; i <obj.rows ; ++i) {
            for (int j = 0; j <obj.cols ; ++j) {
                out<<obj.arr[i][j]<<" ";
            }
            out<<endl;
        }
        return out;
    }
    void print(){
        for (int i = 0; i <rows ; ++i) {
            for (int j = 0; j <cols ; ++j) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void operator=(const Matrix<type>& obj){
        rows=obj.rows;
        cols=obj.cols;
        arr=new type*[rows];
        for (int i = 0; i <rows ; ++i) {
            arr[i]=new type [cols];
        }
        for (int i = 0; i <rows ; ++i) {
            for (int j = 0; j <cols ; ++j) {
                arr[i][j]=obj.arr[i][j];
            }
        }
    }
    void transpose(){
        for (int i = 0; i <cols ; ++i) {
            for (int j = 0; j <rows ; ++j) {
                cout<<arr[j][i]<<" ";
            }
            cout<<endl;
        }
    }
    ~Matrix(){
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
#endif //MAIN_CPP_MATRIX_H
