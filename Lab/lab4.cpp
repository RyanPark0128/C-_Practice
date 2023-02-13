#include <iostream>
#include <vector>
#include <ctime>


int part_mid (std::vector<int> & v, int low, int high) {
  int piv = v[(low+high)/2];

  while (low <= high) {
    while (piv > v[low]) {
      low++;
    }
    while (piv < v[high]) {
      high--;
    }
    if (low <= high) {
      int temp = v[low];
      v[low] = v[high];
      v[high] = temp;
      low++;
      high--;
    }
  }
  return low;
}


void qs_mid (std::vector<int> & v, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = part_mid(v,low,high);
  // std::cout << pivot;
  qs_mid(v,low,pivot-1);
  qs_mid(v,pivot,high);
}

int main () {
  std::vector<int> v = {8,3,7,6,1,10,5,9,-2,-1,-99, 100};
  // srand(time(0));
  // int size;
  // std::cout << "enter size" << std::endl;
  // std::cin >> size;
  // std::cout << std::endl;
  // std::vector<int> v (size);
  // for (int i=0; i<size; i++) {
  //   v[i] = i+1;
  // }

  // int count_first = 0;
  // int count_mid = 0;
  // qs_first(v,0,v.size()-1,count_first);
  qs_mid(v,0,v.size()-1);
  for (auto x:v) {
    std::cout << x << std::endl;
  }
  // std::cout << "Test 1" << std::endl;
  // std::cout << std::endl;
  // std::cout << "Middle: " << count_mid << std::endl;
  // std::cout << "First: " << count_first << std::endl;
  // std::cout << std::endl;
  // std::cout << "Test 2" << std::endl;


  // count_first = 0;
  // count_mid = 0;
  // for (int i=0; i < 1000; i++) {
  //   for (int j=0; j< size; j++) {
  //     v[j] = rand();
  //   }
  //   qs_first(v,0,v.size()-1,count_first);
  // }

  // for (int i=0; i < 1000; i++) {
  //   for (int j=0; j< size; j++) {
  //     v[j] = rand();
  //   }
  //   qs_first(v,0,v.size()-1,count_mid);
  // }

  // std::cout << "Middle: " << count_mid/ 1000 << std::endl;
  // std::cout << "First: " << count_first/1000 << std::endl;

  // for (auto x: v) {
  //   std::cout << x << std::endl;
  // }


  return 0;
}