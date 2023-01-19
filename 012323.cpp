#include <iostream>
#include <vector>


int find_max(std::vector<int> v, int i =0) {

  if (i == v.size()-1) {
    return v[i];
  }
  int max = find_max(v, i+1);
  if (max > v[i]) {
    return max;
  }
  return v[i];
}
int main() {
  std::vector<int> v = {6,3,7,12,8,4,1};
  std::cout << find_max(v) << std::endl;
  return 0;
}