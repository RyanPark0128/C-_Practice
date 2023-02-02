#include <iostream>
#include <vector>
#include <ctime>

int part_first (std::vector<int> & v, int low, int high, int & count) {
  int piv = v[low];

  while (low < high) {
    while (low < high &&++count &&  piv <= v[high]) {
      high--;
    }
    v[low] = v[high];
    while ( low < high &&++count && piv >= v[low]) {
      low++;
    }
    v[high] = v[low];
  }
  v[low] = piv;
  return low;
}

int part_mid (std::vector<int> & v, int low, int high, int & count) {
  int piv = v[(low+high)/2];

  while (low < high) {
    while ( low < high &&++count && piv <= v[high]) {
      high--;
    }
    while ( low < high &&++count && piv >= v[low]) {
      low++;
    }
    int temp = v[low];
    v[low] = v[high];
    v[high] = temp;
  }
  v[low] = piv;
  return low;
}


void qs_mid (std::vector<int> & v, int low, int high, int & count) {
  if (low >= high) {
    return;
  }
  int pivot = part_mid(v,low,high,count);
  qs_mid(v,low,pivot-1,count);
  qs_mid(v,pivot+1,high,count);
}

void qs_first (std::vector<int> & v, int low, int high, int & count) {
  if (low >= high) {
    return;
  }
  int pivot = part_first(v,low,high,count);
  qs_first(v,low,pivot-1,count);
  qs_first(v,pivot+1,high,count);
}

// int qs(std::vector<int> & v) {
//   int count = 0;
//   qs(v,0,v.size()-1, count);
//   return count;
// }

int main () {
  srand(time(0));
  int size;
  std::cout << "enter size" << std::endl;
  std::cin >> size;
  std::cout << std::endl;
  std::vector<int> v (size);
  for (int i=0; i<size; i++) {
    v[i] = i+1;
  }

  int count_first = 0;
  int count_mid = 0;
  qs_first(v,0,v.size()-1,count_first);
  qs_mid(v,0,v.size()-1,count_mid);
  std::cout << "Test 1" << std::endl;
  std::cout << std::endl;
  std::cout << "Middle: " << count_mid << std::endl;
  std::cout << "First: " << count_first << std::endl;
  std::cout << std::endl;
  std::cout << "Test 2" << std::endl;


  count_first = 0;
  count_mid = 0;
  for (int i=0; i < 1000; i++) {
    for (int j=0; j< size; j++) {
      v[j] = rand();
    }
    qs_first(v,0,v.size()-1,count_first);
  }

  for (int i=0; i < 1000; i++) {
    for (int j=0; j< size; j++) {
      v[j] = rand();
    }
    qs_first(v,0,v.size()-1,count_mid);
  }

  std::cout << "Middle: " << count_mid/ 1000 << std::endl;
  std::cout << "First: " << count_first/1000 << std::endl;

  // for (auto x: v) {
  //   std::cout << x << std::endl;
  // }
  return 0;
}