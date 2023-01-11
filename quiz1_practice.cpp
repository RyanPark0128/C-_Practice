#include <iostream>
#include <vector>
#include <fstream>



void multiloop (std::vector<std::vector<int>> & m) {
  for (int i=0; i< m.size(); i++) {
    for (int j=0; j<m[i].size(); j++) {
      m[i][j] = i+j;
      std::cout << m[i][j] << " ";
    }

    std::cout << std::endl;
  }
}

int main () {
  std::ifstream fin;
  std::string s;

  fin.open("./example.txt");
  if (fin.is_open()) {
    while (getline(fin, line)) {
      std::cout << line << std::endl;
    }
  }
  std::vector<std::vector<int>> m (10, std::vector<int>(5));
  multiloop(m);
  return 0;
}


