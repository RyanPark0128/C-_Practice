#include <iostream>
#include <fstream>

class Matrix {
  public:
    Matrix();
    Matrix(std::string file);
    Matrix(int r, int c);
    friend std::ostream& operator<<(std::ostream& out, Matrix & m);
    ~Matrix();
    Matrix(Matrix & m);
    const Matrix operator=(Matrix & rhs);
  private:
    int row;
    int col;
    int **a;
};

Matrix::~Matrix() {
  for (int i=0; i< row; i++) {
    delete[] a[i];
  }
  delete[] a;
  std::cout << "delete" << std::endl;
}

Matrix::Matrix(Matrix & rhs) {
  this->row = rhs.row;
  this->col = rhs.col;
  this->a = new int*[rhs.row];
  for (int i=0; i< rhs.row; i++) {
    this->a[i] = new int[col];
  }

  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      this->a[i][j] = rhs.a[i][j];
    }
  }
}

Matrix::Matrix(std::string file) {
  std::ifstream fin;
  fin.open(file);
  fin >> row >> col;
  a = new int*[row];
  for (int i=0; i< row; i++) {
    a[i] = new int[col];
  }

  for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      fin >> a[i][j];
    }
  }
}

Matrix::Matrix() {
  row = 0;
  col = 0;
  a = new int*[0];
}

Matrix::Matrix(int r, int c) {
  row = r;
  col = c;
  a = new int*[row];
  for (int i=0; i< row; i++) {
    a[i] = new int[col];
  }
}

std::ostream& operator<<(std::ostream& out, Matrix & m) {
  for (int i=0; i< m.row; i++) {
    for (int j=0; j< m.col; j++) {
      out << m.a[i][j] << " ";
    }

    out << std::endl;
  }

  return out;
}


int **arr;
arr = new int*[8];
for (int i=0; i< row; i++) {
  arr[i] = new int[col];
}

Matrix::~Matrix() {
  for (int i=0; i< row; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}

Matrix::Matrix(const Matrix & rhs) {
  this->row = rhs.row;
  this->col = rhs.col;
  this->arr = new int*[rhs.row];
  for (int i=0; i< row; i++) {
    this->arr[i] = new int[col];
  }

  for (int i =0; i< row; i++) {
    for int(j=0; j<col; j++) {
      this->arr[i][j] = rhs.arr[i][j];
    }
  }
}

const Matrix & operator=(const Matrix & rhs) {
  if (this == rhs) {
    return *this;
  }
  for (int i=0; i< row; i++) {
    delete[] arr[i];
  }
  delete[] arr;

  this->row = rhs.row;
  this->col = rhs.col;
  this->arr = new int*[rhs.row];
  for (int i=0; i< row; i++) {
    this->arr[i] = new int[col];
  }

  for (int i =0; i< row; i++) {
    for int(j=0; j<col; j++) {
      this->arr[i][j] = rhs.arr[i][j];
    }
  }

  return *this;
}