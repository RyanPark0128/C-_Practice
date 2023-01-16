#include <iostream>
#include <cmath>
#include <vector>

// int bin_print (int k) {
//   if (k==0) {
//     std::cout<< str <<std:: endl;
//     return;
//   }

//   bin_print(k-1,str + '0');
//   bin_print(k-1,str + '1');
// }

int bin_s(const std::vector<int> &v, int k,  int l, int h) {
  if (l > h) {
    return -1;
  }

  int mid = (l+h)/2;
  if (v[mid] == k) {
    return mid;
  }

  if (v[mid] > k) {
    return bin_s(v,k,l,mid-1);
  }
  return bin_s(v,k,mid+1,h);


}

int bin_s(const std::vector<int> &v, int k) {
  return bin_s(v,k,0,v.size()-1);
}
int main() {
  // std::vector<int> v = {1,3,7,10,11,14,17};
  // int k;
  // std::cin >> k;
  // bin_print(k);
  // std::cout << bin_s(v,k) << std::endl;
  std::cout << 5/2 <<std::endl;
  return 0;
}