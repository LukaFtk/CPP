#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class VectorArr {
private:
    unsigned int N;
    T* data;
    void setN(unsigned int N) {
        this->N = N;
    }
    void clear() {
        for (int i = 0; i < getN(); i++) {
            data[i] = 0;
        }
    }
public:
    VectorArr() {
        N = 0;
        data = new T[N];
    }
    VectorArr(unsigned int N) {
        setN(N);
        data = new T[N];
        clear();
    }
    unsigned int getN() {
        return N;
    }
    void setI(unsigned int i, T myData) {
        data[i] = myData;
    }
    T getI(unsigned int i) {
        return data[i];
    }
};
template <class T>
istream& operator>>(istream& is, VectorArr<T> &A){
    for (int i = 0; i < A.getN(); i++) {
        T data;
        cout << "arr[" << i << "] = ";
        cin >> data;
        A.setI(i, data);
    }
    return is;
}
template <class T>
ostream& operator<<(ostream& os, VectorArr<T>& A) {
    for (int i = 0; i < A.getN(); i++) {
        cout << "arr[" << i << "] = " << A.getI(i) << "\t";
    }
    return os;
}

template <class T>
class VectorMatrix {
private:
    unsigned int N;
    VectorArr<T>* data;
    void setN(unsigned int N) {
        this->N = N;
    }
public:
    VectorMatrix() {
        N = 1;
        data = new VectorArr<T>[N];
    }
    VectorMatrix(unsigned int N) {
        setN(N);
        data = new VectorArr<T>[N];
    }
    unsigned int getN() {
        return N;
    }
    void setI(unsigned int i, VectorArr<T>& myData) {
        data[i] = myData;
    }
    VectorArr<T> getI(unsigned int i) {
        return data[i];
    }
    template <typename T>
    VectorMatrix<T> Transpose() {
        VectorMatrix<T> Transpose = VectorMatrix<T>(getN());
        for (int i = 0; i < getN(); i++) {
            VectorArr<T> tmp = VectorArr<T>(getN());
            for (int j = 0; j < getN(); j++) {
                tmp.setI(j, data[j].getI(i));
            }
            Transpose.setI(i, tmp);
        }
        return Transpose;
    }

};


template <class T>
istream& operator>>(istream& is, VectorMatrix<T>& A){
    for (int i = 0; i < A.getN(); i++) {
        VectorArr<T> tmp = VectorArr<T>(A.getN());
        cin >> tmp;
        A.setI(i, tmp);
    }
    cout << endl;
    return is;
}
template <class T>
ostream& operator<<(ostream& os, VectorMatrix<T>& A) {
    for (int i = 0; i < A.getN(); i++) {
        VectorArr<T> tmp = A.getI(i);
        cout << tmp << endl;
    }
    return os;
}
template <class T>
VectorMatrix<T> operator+(VectorMatrix<T>& A, VectorMatrix<T>& B) {
    VectorMatrix<T> C = VectorMatrix<T>(A.getN());
    for (int i = 0; i < A.getN(); i++) { 
        VectorArr<T> tmp = VectorArr<T>(A.getN());
        for(int j = 0; j < A.getN(); j++){
            tmp.setI(j, A.getI(i).getI(j) + B.getI(i).getI(j));
        }
        C.setI(i, tmp);
    }
    return C;
}
template <class T>
VectorMatrix<T> operator-(VectorMatrix<T>& A, VectorMatrix<T>& B) {
    VectorMatrix<T> C = VectorMatrix<T>(A.getN());
    for (int i = 0; i < A.getN(); i++) {
        VectorArr<T> tmp = VectorArr<T>(A.getN());
        for (int j = 0; j < A.getN(); j++) {
            tmp.setI(j, A.getI(i).getI(j) - B.getI(i).getI(j));
        }
        C.setI(i, tmp);
    }
    return C;
}
template <class T>
VectorMatrix<T> operator*(VectorMatrix<T>& A, VectorMatrix<T>& B) {
    VectorMatrix<T> C = VectorMatrix<T>(A.getN());
    for (int i = 0; i < A.getN(); i++) {
        VectorArr<T> tmp = VectorArr<T>(A.getN());
        for (int j = 0; j < A.getN(); j++) {
            T sum = 0;
            for (int k = 0; k < A.getN(); k++) {
                sum += A.getI(i).getI(k) * B.getI(k).getI(j);
            }
            tmp.setI(j, sum);
        }
        C.setI(i, tmp);
    }
    return C;
}

int main()
{   
    VectorMatrix<int> R1 = VectorMatrix<int>(2);
    cin >> R1;
    R1.Transpose<int>();
    cout << R1;
}

