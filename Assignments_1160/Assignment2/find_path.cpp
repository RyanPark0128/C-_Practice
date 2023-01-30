#include <iostream>
#include <vector>
#include <fstream>

void path_finder (std::vector<std::vector<int>> & v, std::vector<std::vector<std::string>> & solution_map,std::vector<std::vector<std::string>> individual_map,  int col, int row,int count = 0) {
  if (solution_map[v.size()-1][v[row].size()-1] == "X") {
    return;
  }

  if (col == v[row].size()-1 && row == v.size()-1 && count + v[row][col] == 0) {
    individual_map[row][col] = "X";
    solution_map = individual_map;
    return;
  }

  std::vector<std::vector<std::string>> temp = individual_map;
  if (row < v.size()-1 && individual_map[row+1][col] == "-") {
    temp[row][col] = "V";
    path_finder (v,solution_map,temp,col,row+1, count + v[row][col]);
  } 
  if (row > 0 && individual_map[row-1][col] == "-") {
    temp[row][col] = "^";
    path_finder (v,solution_map,temp,col,row-1, count + v[row][col]);
  }
  if (col < v[row].size()-1 && individual_map[row][col+1] == "-") {
    temp[row][col] = ">";
    path_finder (v,solution_map,temp,col+1,row, count + v[row][col]);
  }
  if (col > 0 && individual_map[row][col-1] == "-") {
    temp[row][col] = "<";
    path_finder (v,solution_map,temp,col-1,row, count + v[row][col]);
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

void print_matrix (std::vector<std::vector<int>> & m) {
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

void print_matrix (std::vector<std::vector<std::string>> & m) {
  for (int i=0; i< m.size(); i++) {
    for (int j=0; j < m[i].size(); j++) {
        std::cout << "  " << m[i][j] << "  ";
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

  std::vector<std::vector<std::string>> solution_map(v.size(), std::vector<std::string>(v[0].size(), "-"));
  path_finder(v, solution_map,solution_map, 0,0);
  
  if (solution_map[0][0] == "-") {
      std::cout << "No path found" << std::endl;
  } else {
    std::cout << std::endl;
    std::cout << "Path matrix" << std::endl;
    print_matrix(solution_map);
  }
  return 0;
}