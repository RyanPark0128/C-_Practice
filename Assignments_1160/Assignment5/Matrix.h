#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>



// There seems to be delete after copy why??
// Correctly implemented?
// good practice on order of the member functions, constructors, destructors, assignment
// adding if statements generate COPY.


class Matrix {
  public:
    Matrix();
    Matrix(std::string file);
    ~Matrix();
    Matrix(const Matrix& rhs);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);
    bool operator==(const Matrix & m);
    int* operator[](int i);
    friend Matrix operator*(const Matrix & m, const int multiplier);
    Matrix operator+(const Matrix & m);
    Matrix operator-(const Matrix & m);
    friend Matrix operator*(const Matrix & m1, const Matrix & m2);
    const Matrix& operator= (const Matrix& rhs);
  private:
    int row;
    int col;
    int **arr;
    Matrix(int row,int col);
};

Matrix::Matrix() {
  row = 0;
  col = 0;
  arr = new int*[0];
}

Matrix::Matrix(std::string file) {
  std::ifstream fin;
  fin.open(file);
  fin >> row >> col;
  arr = new int*[row];
  for (int i=0; i< row; i++) {
    arr[i] = new int[col];
  }

  for(int i = 0; i < row; i++){
    for(int j = 0 ; j < col ; j++){
      fin >> arr[i][j];
    }
  }
}

Matrix::~Matrix() {
  for (int i=0; i< row; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  std::cout<< "Delete" << std::endl;
}

Matrix::Matrix(const Matrix& rhs) {
  this->row = rhs.row;
  this->col = rhs.col;
  this->arr = new int*[rhs.row];
  for (int i=0; i< rhs.row; i++) {
    arr[i] = new int[rhs.col];
  }
  for(int i = 0; i < rhs.row; i++){
    for(int j = 0 ; j < rhs.col ; j++){
      arr[i][j] = rhs.arr[i][j];
    }
  }
  std::cout << "COPY" << std::endl;
}

Matrix::Matrix(int r,int c){
  row = r;
  col = c;
  arr = new int*[row];
  for (int i=0; i< row; i++) {
    arr[i] = new int[col];
  }
}

std::ostream &operator<<(std::ostream &out, const Matrix &m) {
  if (!m.row) {
    return out << "Empty" << std::endl;
  }

  for(int i = 0; i < m.row; i++){
    out << "|";
    for(int j = 0 ; j < m.col; j++){
      out << std::setw(4);
      out << m.arr[i][j];
    }
    out << "|" << std::endl;
  }
  out << std::endl;
  return out;
}

bool Matrix::operator==(const Matrix & m) {
  if (row != m.row || col != m.col) {
    return false;
  }
  for(int i = 0; i < row; i++){
      for(int j = 0 ; j < col; j++){
        if (arr[i][j] != m.arr[i][j]) {
          return false;
        }
    }
  }

  return true;
}

int* Matrix::operator[](int i) {
  return arr[i];
}

Matrix operator*(const Matrix & m, const int multiplier) {
  Matrix temp = Matrix(m);
  for (int i=0; i< temp.row; i++) {
    for (int j=0; j < temp.col; j++) {
      temp.arr[i][j] *= multiplier;
    }
  }

  return temp;
}

Matrix Matrix::operator+(const Matrix & m) {
  // if (row != m.row || col != m.col) {
  //   return Matrix();
  // }
  Matrix temp = Matrix(m);
  for (int i=0; i< temp.row; i++) {
    for (int j=0; j < temp.col; j++) {
      temp.arr[i][j] += this->arr[i][j];
    }
  }

  return temp;
}

Matrix Matrix::operator-(const Matrix & m) {
  if (row != m.row || col != m.col) {
    return Matrix();
  }
  Matrix temp = Matrix(m);
  for (int i=0; i< temp.row; i++) {
    for (int j=0; j < temp.col; j++) {
      temp.arr[i][j] = arr[i][j] - temp.arr[i][j];
    }
  }

  return temp;
}

Matrix operator*(const Matrix & m1, const Matrix & m2) {
  int r1 = m1.row;
  int c1 = m1.col;
  int r2 = m2.row;
  int c2 = m2.col;
  if (c1 == r2) {
    Matrix temp(r1,c2);
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                temp.arr[i][j] = 0;
                for (int k = 0; k < r2; k++) {
                    temp.arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
                }
            }
        }
    return temp;
  }
  return Matrix();
}

const Matrix& Matrix::operator= (const Matrix& rhs) {
  if (this == &rhs) {
    return *this;
  }
  for (int i=0; i< row; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  std::cout << "Delete" << std::endl;

  this->row = rhs.row;
  this->col = rhs.col;
  this->arr = new int*[rhs.row];
  for (int i=0; i< rhs.row; i++) {
    arr[i] = new int[rhs.col];
  }
  for(int i = 0; i < rhs.row; i++){
    for(int j = 0 ; j < rhs.col ; j++){
      arr[i][j] = rhs.arr[i][j];
    }
  }
  std::cout << "Assignment" << std::endl;
  return *this;
}

#endif