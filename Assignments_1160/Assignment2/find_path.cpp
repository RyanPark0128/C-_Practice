#include <iostream>
#include <vector>
#include <fstream>

bool path_finder (std::vector<std::vector<int>> & v,std::vector<std::vector<char>> & map,  int col, int row, int count = 0) {
  if (col == v[row].size()-1 && row == v.size()-1 && count + v[row][col] == 0) {
    map[row][col] = 'X';
    return true;
  }
  if (row < v.size()-1 && map[row+1][col] == '-') {
    map[row][col] = 'V';
    if (path_finder (v,map,col,row+1, count + v[row][col])) {
      return true;
    }
  } 
  if (row > 0 && map[row-1][col] == '-') {
    map[row][col] = '^';
    if (path_finder (v,map,col,row-1, count + v[row][col])) {
      return true;
    }
  }
  if (col < v[row].size()-1 && map[row][col+1] == '-') {
    map[row][col] = '>';
    if (path_finder (v,map,col+1,row,count + v[row][col])) {
      return true;
    }
  }
  if (col > 0 && map[row][col-1] == '-') {
    map[row][col] = '<';
    if (path_finder (v,map,col-1,row, count + v[row][col])) {
      return true;
    }
  }
  map[row][col] = '-';
  return false;
}

std::vector<std::vector<int> > readIn(std::string file){
    std::ifstream fin;
    fin.open(file);
    int row,col;
    fin >> row >> col;
    std::vector<std::vector<int> > m(row,std::vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            fin >> m[i][j];
        }
    }
    return m;
}

template <typename T>
void print_matrix (T & m) {
  for (int i=0; i< m.size(); i++) {
    for (int j=0; j < m[i].size(); j++) {
      if (m[i][j] < 0) {
        std::cout << " " << m[i][j] << "  ";
      } else {
        std::cout << "  " << m[i][j] << "  ";
      }
    }
    std::cout << std::endl;
  }
}

int main () {
  std::cout << "Name of the file with the matrix" << std::endl;
  std::string input;
  std::cin >> input;
  std::vector<std::vector<int>> v = readIn(input);
  std::cout << "OG matrix" << std::endl;
  print_matrix(v);
  std::vector<std::vector<char>> map(v.size(), std::vector<char>(v[0].size(), '-'));
  if (path_finder(v,map, 0,0)) {
    std::cout << std::endl;
    std::cout << "Path matrix" << std::endl;
    print_matrix(map);
  } else {
    std::cout << "No path found" << std::endl;
  }
  return 0;
}