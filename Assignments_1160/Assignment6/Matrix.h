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
    //the constructor function takes in a file name as string and populates linked list with dynamic array with corresponding file
    Matrix(std::string file);
    void insert(int* x);

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
    //the function takes in both ostream and matrix m. the function prints linked list with dynamic array of the matrix which is formated neatly.
    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

    //input: it takes in another Matrix class variable and check if it is equal to the current Matrix class
    //output: it returns boolean value. If it matches, it returns true, else false.
    //the function check each elements in both matrix,
    //If any one of the elements are not same, it returns false right away. If it does not return false, it means all the
    //elements in the matrix are same. Therefore, return true.
    bool operator==(const Matrix & m);

    //input: it takes in integer (use of function looks like: m1[i])
    //output: it returns the corresponding row of the matrix.
    //the main file had m1[1][2] in line 19 and because we cannot define operator[][],
    //I decided to deal with m1[1] first and then work with [2] later.
    //In order to do that, m1[1] should return an array and array[2] would work.
    //Therefore we simply return the dynamic array of the corresponding row. 
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

    // node struct for each Matrix class.
    // It contains dynamic array and pointer to the next node.
    struct node {
      int * arr;
      node * next;
    };
    node * head;
    // input: dynamic array , and pointer to the next node.
    // output: returns the node struct
    // the function inserts new node at the end of the linked list with given values of array.
    node* insert(int* x, node* p);
    int row;
    int col;

    //input: the function takes in two integer values
    //output: the function does not return anything but construct new 2d Matrix with given integer as row and col.
    // this function is used to create Matrix class variable with given input.
    Matrix(int row,int col);

    //input: none;
    //output: none;
    //this function is called everytime linked list and dynamic array needed to be delete from the memory
    void delete_list();

    //input: the function takes in Matrix class variable
    //output: returns the pointer that would be assigned head;
    //the function takes in a pointer of a Matrix class and creates deep copy of it.
    node* copy_list(Matrix::node* p);
};

Matrix::Matrix() {
  head = nullptr;
}

void Matrix::insert(int* a) {
  head = insert(a, head);
}

Matrix::node* Matrix::insert(int* a, Matrix::node* p) {
  if(!p) {
    return new node{a, p};
  }
  p->next = insert(a,p->next);
  return p;
}

std::ostream & operator <<(std::ostream & out, const Matrix & rhs) {
  if (!rhs.head) {
    out << "Empty" << std::endl;
    return out;
  }
  Matrix::node * p = rhs.head;
  while(p){
    out << "|";
    for (int i=0; i< rhs.col; i++) {
      out << std::setw(4);
      out << p->arr[i];
    }
    out << "|";
    out << std::endl;
    p = p->next;
  }
  out << std::endl;
  return out;
}

Matrix::Matrix(std::string file) {
  std::ifstream fin;
  fin.open(file);
  fin >> row >> col;
  head = nullptr;
  for (int i=0; i< row; i++) {
    int* a = new int[col];
    for (int j=0; j<col; j++) {
      fin >> a[j];
    }
    insert(a);
  }
}

Matrix::~Matrix() {
  delete_list();
  std::cout<< "DELETE" << std::endl;
}

Matrix::Matrix(const Matrix& rhs) {
  this->row = rhs.row;
  this->col = rhs.col;
  head = copy_list(rhs.head);
  std::cout << "COPY" << std::endl;
}

Matrix::Matrix(int r,int c){
  this->row = r;
  this->col = c;
  head = nullptr;
  for (int i=0; i< row; i++) {
    int* a = new int[col];
    for (int j=0; j<col; j++) {
      a[j] = 0;
    }
    insert(a);
  }
}

const Matrix& Matrix::operator=(const Matrix& rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete_list();
  col = rhs.col;
  row = rhs.row;
  head = copy_list(rhs.head);
  std::cout << "ASSGINMENT" <<std::endl;
  return *this;
}

bool Matrix::operator==(const Matrix & m) {
  if (this->row != m.row || this->col != m.col) {
    return false;
  }

  node * p = head;
  node * p2 = m.head;
  for(int i = 0; i < row; i++){
    for(int j = 0 ; j < col; j++){
      if (p->arr[j] != p2->arr[j]) {
        return false;
      }
    }
    p = p->next;
    p2 = p2->next;
  }

  return true;
}

int* Matrix::operator[](int i) {
  node* p = head;
  for (int j=0; j< i; j++) {
    p = p->next;
  }
  return p->arr;
}

Matrix Matrix::operator*(const int multiplier) {
  Matrix temp(*this);
  node * p = temp.head;
  for (int i=0; i< temp.row; i++) {
    for (int j=0; j < temp.col; j++) {
      p->arr[j] *= multiplier;
    }
    p = p->next;
  }
  return temp;
}

Matrix Matrix::operator+(const Matrix & m) {
  if (this->row != m.row || this->col != m.col) {
    return Matrix();
  }

  Matrix temp(m);
  node * p = head;
  node * p2 = temp.head;
  for(int i = 0; i < row; i++){
    for(int j = 0 ; j < col; j++){
      p2->arr[j] += p->arr[j];
    }
    p = p->next;
    p2 = p2->next;
  }

  return temp;
}

Matrix Matrix::operator-(const Matrix & m) {
  if (this->row != m.row || this->col != m.col) {
    return Matrix();
  }

  Matrix temp(m);
  node * p = head;
  node * p2 = temp.head;
  for(int i = 0; i < row; i++){
    for(int j = 0 ; j < col; j++){
      p2->arr[j] = p->arr[j] - p2->arr[j];
    }
    p = p->next;
    p2 = p2->next;
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
    node * p = temp.head;
    node * p1 = head;
    node * p2 = m.head;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < r2; k++) {
                    p->arr[j] += p1->arr[k] * p2->arr[j];
                    p2=p2->next;
                }
                p2=m.head;
            }
            p=p->next;
            p1=p1->next;
        }
    return temp;
  }
  return Matrix();
}

void Matrix::delete_list() {
  while(head) {
    node* tmp = head;
    head = head->next;
    delete tmp->arr;
    delete tmp;
  }
}

Matrix::node* Matrix::copy_list(Matrix::node* p) {
  if(!p) {
    return p;
  }
  int* temp = new int[col];
  for (int i=0; i< col; i++) {
    temp[i] = p->arr[i];
  }
  return new Matrix::node{temp, copy_list(p->next)};
}

#endif