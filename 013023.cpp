#include <iostream>
#include <vector>

int part (std::vector<int> & v, int low, int high) {
  int piv = v[low];

  while (low < high) {
    while (low < high && piv < v[high]) {
      high--;
    }
    v[low] = v[high];
    while (low < high && piv > v[low]) {
      low++;
    }
    v[high] = v[low];
  }
  v[low] = piv;
  return low;
}

void qs (std::vector<int> & v, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = part(v,low,high);
  // qs(v,low,pivot-1);
  // qs(v,pivot+1,high);
}

void qs(std::vector<int> & v) {
  qs(v,0,v.size()-1);
}

int main () {
  std::vector<int> v = {7,3,9,4,8,12,1};
  qs(v);
    for (auto x: v) {
    std::cout << x << std::endl;
  }
  return 0;
}

// n =5
// 2+2+2+2+4 = 12

// n = 6
// 14

// n = 7
// 16

// n*2 + 2