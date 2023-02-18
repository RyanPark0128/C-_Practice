#include <iostream>
#include <vector>


int run (std::vector<int> v, int i, int j) {
  if (i == j) {
    return v[i];
  }
  int x = (i+j) / 2;
  int y = run(v, i, x);
  int z = run(v, x+1, j);

  std::cout << y << " " << z << std::endl;
  if (y < z) {
    return z;
  }
  return y;

}

int main () {
  std::vector<int> v = {6,1,2,3,4,5,-1,0,9};
  std::cout << run(v,0,v.size()-1) << std::endl;


  return 0;
}