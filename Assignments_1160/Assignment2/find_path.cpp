#include <iostream>
#include <vector>
#include <fstream>

void path_finder (std::vector<std::vector<int>> & v, std::vector<std::vector<int>> map, int col, int row) {
  map = v;
  for (int i=0; i < v.size(); i++) {
    for (int j=0; j< v[i].size(); j++) {
      std::cout << map[i][j] << " ";
    }

    std::cout << std::endl;
  }
}

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

int main () {
  std::string input;
  std::cin >> input;

  std::vector<std::vector<int>> map;
    std::vector<std::vector<int>> v = readIn(input);
  
  path_finder(v, map, 0,0);
  return 0;
}