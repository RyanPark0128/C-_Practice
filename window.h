#include <iostream>
#include <vector>

class Matrix{
    public:
        Matrix(int num);
        void print();
        void operator+(int num);
        void operator+(Matrix & v);
        bool operator==(Matrix & v);

    private:
        int r;
};

Matrix::Matrix(int num){
    r = num;
}

void Matrix::print(){
  std::cout << r << std::endl;
}

void Matrix::operator+(int num) {
    r+= num;
}

void Matrix::operator+(Matrix & v) {
    r += v.r;
}

bool Matrix::operator==(Matrix & v) {
    return r == v.r;
}
