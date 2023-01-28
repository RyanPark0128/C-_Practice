#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>


// Input: for this function is string value which is input from user to select file name;
// Output: the function will return the 2d matrix read from file
// The function receives a filename as a string and open the corresponding file and process the contents, and return the matrix in 2d vector
std::vector<std::vector<int> > readIn(std::string file){
    std::ifstream fin;
    fin.open(file);
    int row,col;
    fin >> row;
    fin >> col;
    std::vector<std::vector<int> > m(row,std::vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            fin >> m[i][j];
        }
    }
    return m;
}

// Input: for this function is 2d vector matrix which will be printed
// Output: the function will not return anything but print the input 2d vector matrix
// The function takes in 2d vector that will be looped to print out the content of the 2d vector matrix.
void printMatrix(std::vector<std::vector<int>> & matrix) {
    for (int i=0; i< matrix.size();i++) {
        for (int j=0; j <matrix[i].size(); j++) {
            // prints the content and add space to make it visible
            std::cout << matrix[i][j] << " ";
        }
        // move it to the next line
        std::cout << std::endl;
    }
}

// Input: for this function is first 2d vector matrix, second 2d vector matrix,
// resulting 2d vector matrix, row and column for both first and second 2d vector matrix.
// Output: the function does not return anything, instead it will print the multiplied 2d vector matrix
// The function takes in two 2d matrixs and multiply them together and creates a new 2d vector matrix.
// After creating the resulting matrix, it calls the printMatrix function to print them out in the terminal.
void multiplyMatrix(std::vector<std::vector<int>> & m1, std::vector<std::vector<int>> & m2, std::vector<std::vector<int>> & multi, int r1,int c1, int r2, int c2) {
    // if the column number of the first matrix does not match the row number of the second matrix,
    // it means that the two matrixs cannot be multiplied. Therefore it will just print error message.
    if (c1 == r2) {

        // nested loop to loop through all the values(position) in the resulting 2d vector
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {

                // declares value to be 0 initially
                multi[i][j] = 0;
                for (int k = 0; k < r2; k++) {
                    // It will loop through and add all the product of columns (first matrix) and rows (second matrix).
                    multi[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }

        // Now the loop ended, we print the resulting matrix by calling the printMatrix function
        printMatrix(multi);
    } else {

        // error message, since c1 != r2, matrixs cannot be multiplied.
        std::cout << "Matrixes can not be multiplied" << std::endl;
    }
}

int main(){

    // ask user for the first filename
    std::cout << "enter the first file name" << std::endl;
    std::string inputOne;
    std::cin >> inputOne;

    // use the readIn function to read the file and store the resulting 2d vector matrix into a variable
    std::vector<std::vector<int>> m1 = readIn(inputOne);

    // declare rows and columns for this matrix
    int r1 = m1.size();
    int c1 = m1[0].size();

    // ask user for the second filename
    std::cout << "enter the second file name" << std::endl;
    std::string inputTwo;
    std::cin >> inputTwo;

    // use the readIn function to read the file and store the resulting 2d vector matrix into a variable
    std::vector<std::vector<int>> m2 = readIn(inputTwo);

    // declare rows and columns for this matrix
    int r2= m2.size();
    int c2 = m2[0].size();

    // initialize the resulting 2d vector variable 
    std::vector<std::vector<int>> multi (r1, std::vector<int>(c2));

    // invoke multiplyMatrix function to multiply 2 matrixs
    multiplyMatrix(m1,m2,multi,r1,c1,r2,c2);

    return 0;
}

