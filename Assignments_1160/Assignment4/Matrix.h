#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>


// initialize class for Matrix
class Matrix {
  public:
    //prototyping for public access specifier

    //Input: takes in a string (name of the file that user want to retreive)
    //output: no output
    //the constructor function takes in a file name as string and populates 2d vector with corresponding file
    Matrix(std::string file);

    //input: the function takes in std::ostream and Matrix m
    //output: the function returns std::ostream (contents that gets to be printed)
    //the function takes in both ostream and matrix m. the function prints the matrix formatly neatly.
    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

    //input: it takes in another Matrix class variable and check if it is equal to the current Matrix class
    //output: it returns boolean value. If it matches, it returns true, else false.
    //the function enters into nested loop and check each elements in both matrix,
    //If any one of the elements are not same, it returns false right away. If it does not return false, it means all the
    //elements in the matrix are same. Therefore, return true.
    bool operator==(const Matrix & m);

    //input: it takes in integer (use of function looks like: m1[i])
    //output: it returns the corresponding row of the vector.
    //the main file had m1[2][3] in line 19 and because we cannot define operator[][],
    //I decided to deal with m1[2] first and then work with [3] later.
    //In order to do that, m1[2] should return a vector and vector[3] would work.
    //Therefore we simply return the vector of the corresponding row. 
    std::vector<int> operator[](int i);

    //input: the function takes in Matrix class and integer
    //output: the function returns a new Matrix class with updated value.
    //the function will take in an int and multiply all the items in the 2d matrix with the int.
    //To return Matrix class, I made a copy temp, and updated the temp before returning it.
    //I used temp because I did not want to make any changes to the Matrix m that is passed in as a parameter.
    friend Matrix operator*(const Matrix & m, const int multiplier);

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

    //input: the function takes in two Matrix classes.
    //output: the function returns a new Matrix class after the matrix multiplication.
    //the functon takes in two Matrix classes to do matrix multiplication.
    //Because I want to return new Matrix class, I made a copy of the Matrix class called temp.
    //Then I perform the Matrix multiplication after initializing/declaring variable necessary.
    // When I am finished I return the resulting Matrix class.
    friend Matrix operator*(const Matrix & m1, const Matrix & m2);
  private:
    // create 2d vector to store 2d matrix information within the private access specifier
    std::vector<std::vector<int>> v;
    // create new instance with row and col.
    Matrix(int row,int col);
};

Matrix::Matrix(std::string file) {
      std::ifstream fin;
      fin.open(file);
      int row,col;
      fin >> row >> col;
      // before entering into the loop, we resize the vector to match the row and col of matrix
      v.resize(row, std::vector<int>(col));
      for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
          fin >> v[i][j];
      }
    }
}

Matrix::Matrix(int row,int col){
    v.resize(row, std::vector<int>(col));
}

std::ostream &operator<<(std::ostream &out, const Matrix &m) {
  // if the matrix has size 0 or if it doesn't exist, returns right away
  if (!m.v.size()) {
    return out << "Empty" << std::endl;
  }

  // if the matrix exists, enters into nested loop to format and print the content.
  for(int i = 0; i < m.v.size(); i++){
    out << "|";
    for(int j = 0 ; j < m.v[i].size() ; j++){
      out << std::setw(4);
      out << m.v[i][j];
    }
    out << "|" << std::endl;
  }
  out << std::endl;

  //after we are done, we return out  
  return out;

}

bool Matrix::operator==(const Matrix & m) {
    if (v.size() != m.v.size() || v[0].size() != m.v[0].size()) {
      return false;
    }
    for(int i = 0; i < m.v.size(); i++){
        for(int j = 0 ; j < m.v[i].size() ; j++){
          // if they do not equal, return false
          if (v[i][j] != m.v[i][j]) {
            return false;
          }
      }
    }

    return true;
}

std::vector<int> Matrix::operator[](int i) {
  return v[i];
}

Matrix operator*(const Matrix & m, const int multiplier) {
  // creates copy of m;
  Matrix temp = m;
  // do the multiplication within the nested loop
  for (int i=0; i< temp.v.size(); i++) {
    for (int j=0; j < temp.v[i].size(); j++) {
      temp.v[i][j] *= multiplier;
    }
  }

  //returns the Matrix class with updated matrix
  return temp;
}

Matrix Matrix::operator+(const Matrix & m) {
  if (v.size() != m.v.size() || v[0].size() != m.v[0].size()) {
    Matrix temp(0,0);
    return temp;
  }
  // creates copy of m;
  Matrix temp = m;
  // do the addition within the nested loop
  for (int i=0; i< temp.v.size(); i++) {
    for (int j=0; j < temp.v[i].size(); j++) {
      temp.v[i][j] += v[i][j];
    }
  }

  // returns the new updated Matrix class
  return temp;
}

Matrix Matrix::operator-(const Matrix & m) {
  if (v.size() != m.v.size() || v[0].size() != m.v[0].size()) {
    Matrix temp(0,0);
    return temp;
  }
  //creats a copy
  Matrix temp = m;
  //Do subtraction within the loop.
  for (int i=0; i< temp.v.size(); i++) {
    for (int j=0; j < temp.v[i].size(); j++) {
      temp.v[i][j] = v[i][j] - temp.v[i][j];
    }
  }

  //return the new updated Matrix class
  return temp;
}

Matrix operator*(const Matrix & m1, const Matrix & m2) {
  // row and col for matrix from first Matrix class
  int r1 = m1.v.size();
  int c1 = m1.v[0].size();
  // row and col for matrix from second Matrix class
  int r2 = m2.v.size();
  int c2 = m2.v[0].size();
  // if c1 does not equal r2, it means we cannot perform matrix multiplication
  // and we dont do anything after which will return empty vec
  if (c1 == r2) {
    Matrix temp(r1,c2);
    // if the matrixs can be multiplied, then we perform the matrix multiplcation.
    // before we begin we resize the resulting matrix to appropriate size.
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                temp.v[i][j] = 0;
                for (int k = 0; k < r2; k++) {
                    temp.v[i][j] += m1.v[i][k] * m2.v[k][j];
                }
            }
        }
    return temp;   
  }
  Matrix temp(0,0);
  return temp;
}

#endif