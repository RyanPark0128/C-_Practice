#include <iostream>
#include <vector>

int findPath (std::vector<std::vector<char>> m, int i =0 , int j=0) {
  if (i == m.size() || j == m[0].size() || m[i][j] == 'X') return 0;
  if (i == m.size()-1 && j == m[0].size()-1) return 1;
  return findPath(m,i+1,j) + findPath(m, i, j+1);
}

int main () {
  std::vector<std::vector<char>>m (5,std::vector<char>(5,'-'));
  m[1][1] = 'X';
  m[2][2] = 'X';
  m[3][2] = 'X';
  std::cout << findPath(m) << std::endl;
  return 0;
}