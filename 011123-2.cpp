#include <iostream>
#include <vector>

// pass in vectors by reference
void fill (std::vector<std::vector<int>> & v) {
  for (int i=0; i < v.size(); i++) {
    for (int j=0; j < v[0].size(); j++) {
          v[i][j]= i;
          std::cout << v[i][j];
    }
    std::cout << std::endl;
  }
}
int main() {
  std::vector<int> v(4);
  // try not to use push_back
  // v.push_back(45);


  std::vector<std::vector<int>> m(4, std::vector<int>(4));
  fill(m);

  // auto automatically gets the type of the vector;
  // if you want to change the value of vector, use the reference &. Otherwise it will make copy of it.
  // for (auto & x:v) {
  //     std::cout << x << std::endl;
  // }

  // for (int y:v) {
  //   std::cout << y << std::endl;
  // }
  return 0;
}