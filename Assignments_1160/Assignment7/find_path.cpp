#include <iostream>
#include <vector>
#include <fstream>
#include "stack.h"

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

struct state {
  int row;
  int col;
  int score;
  int p_row;
  int p_col;
  char dir;
};


void path_stack(std::vector<std::vector<char>> & m, const std::vector<std::vector<int>> & v) {
  stack<state> s;
  s.push({0,0, 0,0,0,'X'});
  while (!s.isEmpty()) {
    state curr = s.pop();
    if (curr.dir == 'P') {
      m[curr.row][curr.col] = '-';
    } else if (curr.row == m.size() -1 && curr.col == m[curr.row].size() -1 && curr.score + v[curr.row][curr.col] == 0){
      m[curr.row][curr.col] = 'X';
      m[curr.p_row][curr.p_col] = curr.dir;
      while (!s.isEmpty()) {
        s.pop();
      }
    } else if (curr.row >= m.size() || curr.col >= m[curr.row].size() || m[curr.row][curr.col] != '-' || (curr.row == m.size() -1 && curr.col == m[curr.row].size() -1)) {

    } else {
      m[curr.p_row][curr.p_col] = curr.dir;
      curr.dir = 'P';
      s.push(curr);
      s.push({curr.row,curr.col-1,curr.score + v[curr.row][curr.col],curr.row, curr.col, '<'});
      s.push({curr.row,curr.col+1,curr.score + v[curr.row][curr.col],curr.row, curr.col, '>'});
      s.push({curr.row-1,curr.col,curr.score + v[curr.row][curr.col],curr.row, curr.col, '^'});
      s.push({curr.row+1,curr.col,curr.score + v[curr.row][curr.col],curr.row, curr.col, 'V'});
    }
  }

}


std::vector<std::vector<int>> readIn(std::string file){
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

int main () {
  std::cout << "Name of the file with the matrix" << std::endl;
  std::string input;
  std::cin >> input;
  std::vector<std::vector<int>> v = readIn(input);
  std::cout << "OG matrix" << std::endl;
  print_matrix(v);
  std::cout << std::endl;
  std::vector<std::vector<char>> map(v.size(), std::vector<char>(v[0].size(), '-'));
  path_stack(map, v);
  if (map[0][0] == '-') {
    std::cout << "No Path Found" << std::endl;
  } else {
    std::cout << "Path Matrix" << std::endl;
    print_matrix(map);
  }
  return 0;
}