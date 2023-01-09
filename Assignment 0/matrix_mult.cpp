#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

 std::vector<std::vector<int> > readIn(std::string file, int & row, int & col){
    std::ifstream fin;
    fin.open(file);
    fin >> row;
    fin >> col;
    std::vector<std::vector<int> > m(row,std::vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            fin >> m[i][j];
            std::cout << m[i][j] << " ";
        }

        std::cout << std::endl;
    }
    return m;

}
int main(){
    std::cout << "enter the file name" << std::endl;
    std::string inputOne;
    std::cin >> inputOne;
    int r1;
    int c1;
    std::vector<std::vector<int>> m1 = readIn(inputOne, r1, c1);

    std::string inputTwo;
    std::cin >> inputTwo;
    int r2;
    int c2;
    std::vector<std::vector<int>> m2 = readIn(inputTwo, r2, c2);

    std::vector<std::vector<int>> multi (r1, std::vector<int>(c2));

    if (c1 == r2) {
        for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            multi[i][j] = 0;
            for (int k = 0; k < r2; k++) {
                multi[i][j] += m1[i][k] * m2[k][j];
            }
            std::cout << multi[i][j] << " ";
        }
        std::cout << std::endl;
    }
    } else {
        std::cout << " can not be multiplied" << std::endl;
    }

    return 0;
}

