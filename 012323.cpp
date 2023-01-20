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

void selection_sort(std::vector<int> & v) {
  for (int i=0; i< v.size(); i++) {
    int min = i;
    for (int j=i+1; j< v.size(); j++) {
      if (v[min] > v[j]) {
        min = j;
      }
    }
    int temp = v[i];
    v[i] = v[min];
    v[min] = temp;
  }
}

int main() {
  std::vector<int> v = {6,3,7,12,8,4,1};
  // std::cout << selection_sort(v) << std::endl;
  selection_sort(v);

  for(auto x : v) {
    std::cout << x << std::endl;
  }
  return 0;
}