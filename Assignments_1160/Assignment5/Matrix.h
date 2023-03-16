#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <fstream>

// initialize class for Matrix
class Matrix {
  //prototyping for public access specifier
  public:
    //Input: none;
    //Output: none;
    //basic constructor function without any parameter. the function initialize varibles with 0;
    Matrix();

    //Input: takes in a string (name of the file that user want to retreive)
    //output: no output
    //the constructor function takes in a file name as string and populates 2d array with corresponding file
    Matrix(std::string file);

    //input: none;
    //output: none;
    //deconstructor function is invoked automatically when the object goes out of scope.It deallocate memory and do other cleanup.
    ~Matrix();

    //input: another Matrix class variable;
    //output: none. construct new Matrix class with deep copy of input.
    //This creates deep copy of the input and construct new Matrix class variable.
    Matrix(const Matrix& rhs);

    //input: another Matrix class variable
    //output: returns Matrix class that gets assigned to
    //This is assignment function that declares a Matrix class variable to be another Matrix class variable
    const Matrix& operator= (const Matrix& rhs);


    //input: the function takes in std::ostream and Matrix m
    //output: the function returns std::ostream (contents that gets to be printed)
    //the function takes in both ostream and matrix m. the function prints 2d array of the matrix which is formated neatly.
    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

    //input: it takes in another Matrix class variable and check if it is equal to the current Matrix class
    //output: it returns boolean value. If it matches, it returns true, else false.
    //the function enters into nested loop and check each elements in both matrix,
    //If any one of the elements are not same, it returns false right away. If it does not return false, it means all the
    //elements in the matrix are same. Therefore, return true.
    bool operator==(const Matrix & m);

    //input: it takes in integer (use of function looks like: m1[i])
    //output: it returns the corresponding row of the 2d array.
    //the main file had m1[2][3] in line 19 and because we cannot define operator[][],
    //I decided to deal with m1[2] first and then work with [3] later.
    //In order to do that, m1[2] should return an arry and array[3] would work.
    //Therefore we simply return the vector of the corresponding row. 
    int* operator[](int i);

    //input: the function takes in integer that gets multiplied
    //output: the function returns a new Matrix class with updated value.
    //the function will take in an int and multiply all the items in the 2d matrix with the int.
    //To return Matrix class, I made a copy(deep copy) temp, and updated the temp before returning it.
    //I used temp because I did not want to make any changes to the Matrix m that is passed in as a parameter.
    Matrix operator*(const int multiplier);

    //input: the function takes in Matrix class
    //output: the function returns a new Matrix class with updated values
    //The function takes in the Matrix class, and add matrix from two Matrix class together.
    //Because I do not want to modify any original values, I create copy of a Matrix class.
    //And add values together within the temp Matrix class.
    //After the operation, returns temp.
    Matrix operator+(const Matrix & m);

    //input: the function takes in a Matrix class.
    //output:: the function returns a new Matrix class after the operation.
    //The function returns new Matrix class that result from subtraction between two Matrix classes.
    //I also created temp Matrix to make a copy to it, and after the subtraction I return the temp.
    Matrix operator-(const Matrix & m);

    //input: the function takes in a Matrix classe.
    //output: the function returns a new Matrix class after the matrix multiplication.
    //the functon takes in a Matrix classs to do matrix multiplication.
    //Because I want to return new Matrix class, I made a copy of the Matrix class called temp.
    //Then I perform the Matrix multiplication after initializing/declaring variable necessary.
    // When I am finished I return the resulting Matrix class.
    Matrix operator*(const Matrix & m2);
  private:
    int row;
    int col;
    // 2d array variable (dynamic)
    int **arr;

    //input: the function takes in two integer values
    //output: the function does not return anything but construct new Matrix with 2d array with given integer as row and col.
    // this function is used to create Matrix class variable with given input.
    Matrix(int row,int col);

    //input: none;
    //output: none;
    //this function is called everytime arr should be delete from the memory
    void delete_arr();
    //input: the function takes in Matrix class variable
    //output: none;
    //the function takes in Matrix class and creates deep copy of it.
    void copy_arr(const Matrix & rhs);
};

Matrix::Matrix() {
  this->row = 0;
  this->col = 0;
  this->arr = new int*[0];
}

Matrix::Matrix(std::string file) {
  std::ifstream fin;
  fin.open(file);
  fin >> row >> col;
  this->arr = new int*[row];
  for (int i=0; i< row; i++) {
    this->arr[i] = new int[col];
  }

  for(int i = 0; i < row; i++){
    for(int j = 0 ; j < col ; j++){
      fin >> this->arr[i][j];
    }
  }
}

Matrix::~Matrix() {
  delete_arr();
  std::cout<< "DELETE" << std::endl;
}

Matrix::Matrix(const Matrix& rhs) {
  copy_arr(rhs);
  std::cout << "COPY" << std::endl;
}

Matrix::Matrix(int r,int c){
  this->row = r;
  this->col = c;
  this->arr = new int*[row];
  for (int i=0; i< row; i++) {
    this->arr[i] = new int[col];
  }
}

const Matrix& Matrix::operator= (const Matrix& rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete_arr();
  copy_arr(rhs);
  std::cout << "Assignment" << std::endl;
  return *this;
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
  if (this->row != m.row || this->col != m.col) {
    return false;
  }
  for(int i = 0; i < row; i++){
      for(int j = 0 ; j < col; j++){
        if (this->arr[i][j] != m.arr[i][j]) {
          return false;
        }
    }
  }

  return true;
}

int* Matrix::operator[](int i) {
  return this->arr[i];
}

Matrix Matrix::operator*(const int multiplier) {
  Matrix temp(*this);
  for (int i=0; i< temp.row; i++) {
    for (int j=0; j < temp.col; j++) {
      temp.arr[i][j] *= multiplier;
    }
  }
  return temp;
}

Matrix Matrix::operator+(const Matrix & m) {
  if (this->row != m.row || this->col != m.col) {
    return Matrix();
  }
  Matrix temp(m);
  for (int i=0; i< temp.row; i++) {
    for (int j=0; j < temp.col; j++) {
      temp.arr[i][j] += this->arr[i][j];
    }
  }

  return temp;
}

Matrix Matrix::operator-(const Matrix & m) {
  if (this->row != m.row || this->col != m.col) {
    return Matrix();
  }
  Matrix temp(m);
  for (int i=0; i< temp.row; i++) {
    for (int j=0; j < temp.col; j++) {
      temp.arr[i][j] = this->arr[i][j] - temp.arr[i][j];
    }
  }

  return temp;
}

Matrix Matrix::operator*(const Matrix & m) {
  int r1 = this->row;
  int c1 = this->col;
  int r2 = m.row;
  int c2 = m.col;
  if (c1 == r2) {
    Matrix temp(r1,c2);
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                temp.arr[i][j] = 0;
                for (int k = 0; k < r2; k++) {
                    temp.arr[i][j] += this->arr[i][k] * m.arr[k][j];
                }
            }
        }
    return temp;
  }
  return Matrix();
}

void Matrix::delete_arr() {
  for (int i=0; i< row; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}

void Matrix::copy_arr(const Matrix & rhs) {
  this->row = rhs.row;
  this->col = rhs.col;
  this->arr = new int*[rhs.row];
  for (int i=0; i< rhs.row; i++) {
    this->arr[i] = new int[rhs.col];
  }
  for(int i = 0; i < rhs.row; i++){
    for(int j = 0 ; j < rhs.col ; j++){
      this->arr[i][j] = rhs.arr[i][j];
    }
  }
}

#endif