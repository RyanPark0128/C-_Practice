#include <iostream>
#include <vector>

class Matrix{
    public:
        Matrix(int num);
        void print();

    private:
        int r;
};

Matrix::Matrix(int num){
    r = num;
}

void Matrix::print(){
  std::cout << r;
}
