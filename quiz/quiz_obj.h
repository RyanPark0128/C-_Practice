#ifndef QO_H
#define QO_H
#include <iostream>

/*
SAMPLE OUTPUT
------OBJECT 1--------
2 4
4 8

2 4 0 0
4 8 0 0 
0 0 0 0
0 0 0 0

------OBJECT 2--------
0 1 6
4 5 9
9 5 4
2 6 6
4 1 3

0
4
9
2
4

------OBJECT 3--------
4 9 0 5
7 0 0 1
2 0 5 1

4

------OBJECT 4--------
7

7 0 0 0
*/
class quiz_obj
{
    public:
    //create a 2d array with n rows and m columns filled with random numbers
    quiz_obj(int n,int m);

    //delete all dynamic memory 
    ~quiz_obj();

    // delete old memory and then deep copy
    const quiz_obj& operator=(const quiz_obj&);

    //deep copy
    quiz_obj(const quiz_obj&);

    //prints out the 2d array
    friend std::ostream& operator<<(std::ostream&, const quiz_obj&);

    //resize the matrix to n rows and m columns. 
    //if extra rows or columns are added fill those extra spots with 0's
    //if rows or columns are removed they are just gone
    void resize(int n,int m);
    
private:
    //you can not add more variables
    int * col; //number of columns
    int * row; //number of rows
    int ** matrix; // array to store the ints
};
void quiz_obj::resize(int n, int m){
    int ** tmp = new int*[n];
    for (int i=0; i< n; i++) {
        tmp[i] = new int[m];
    }

    for (int i=0; i< n; i++) {
        for (int j=0; j< m; j++) {
            if (i >= *row || j >= *col) {
                tmp[i][j] = 0;
            } else {
                tmp[i][j] = matrix[i][j];
            }
        }
    }

    for (int i=0; i< *row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete col;
    delete row;
    row = new int(n);
    col = new int(m);
    matrix = tmp;
}

std::ostream& operator<<(std::ostream& out, const quiz_obj& obj){
    for (int i=0; i < *obj.row; i++) {
        for (int j=0; j < *obj.col; j++) {
            out << obj.matrix[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

quiz_obj::quiz_obj(int n,int m)
{      
    row = new int(n);
    col = new int(m);
    matrix = new int*[*row];
    for (int i=0; i< *row; i++) {
        matrix[i] = new int[*col];
    }
    for (int i=0; i < *row; i++) {
        for (int j=0; j< *col; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

quiz_obj::~quiz_obj()
{
    for (int i=0; i< *row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete col;
    delete row;
}

const quiz_obj& quiz_obj::operator=(const quiz_obj& rhs){
    if (this == &rhs) {
        return *this;
    }
    for (int i=0; i< *row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete col;
    delete row;

    this->row = new int(*rhs.row);
    this->col = new int(*rhs.col);
    this->matrix = new int*[*rhs.row];
    for (int i=0; i< *rhs.row; i++) {
        this->matrix[i] = new int[*rhs.col];
    }

    for (int i=0; i < *rhs.row; i++) {
        for (int j=0; j< *rhs.col; j++) {
            this->matrix[i][j] = rhs.matrix[i][j];
        }
    }

    return *this;
}

quiz_obj::quiz_obj(const quiz_obj& rhs){
    this->row = new int(*rhs.row);
    this->col = new int(*rhs.col);
    this->matrix = new int*[*rhs.row];
    for (int i=0; i< *rhs.row; i++) {
        this->matrix[i] = new int[*rhs.col];
    }

    for (int i=0; i < *rhs.row; i++) {
        for (int j=0; j< *rhs.col; j++) {
            this->matrix[i][j] = rhs.matrix[i][j];
        }
    }
}


#endif