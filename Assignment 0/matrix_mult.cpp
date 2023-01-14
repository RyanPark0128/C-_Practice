#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

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

void printMatrix(std::vector<std::vector<int>> & matrix) {
    for (int i=0; i< matrix.size();i++) {
        for (int j=0; j <matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void multiplyMatrix(std::vector<std::vector<int>> & m1, std::vector<std::vector<int>> & m2, std::vector<std::vector<int>> & multi, int r1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            multi[i][j] = 0;
            for (int k = 0; k < m2.size(); k++) {
                    multi[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main(){
    std::cout << "enter the file name" << std::endl;
    std::string inputOne;
    std::cin >> inputOne;
    std::vector<std::vector<int>> m1 = readIn(inputOne);
    int r1 = m1.size();
    int c1 = m1[0].size();

    std::string inputTwo;
    std::cin >> inputTwo;
    std::vector<std::vector<int>> m2 = readIn(inputTwo);
    int r2= m2.size();
    int c2 = m2[0].size();

    std::vector<std::vector<int>> multi (r1, std::vector<int>(c2));

    if (c1 == r2) {
        multiplyMatrix(m1,m2,multi,r1,c2);
        printMatrix(multi);
    } else {
        std::cout << "Matrixes can not be multiplied" << std::endl;
    }

    return 0;
}

