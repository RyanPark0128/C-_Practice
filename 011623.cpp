#include <iostream>
#include <vector>

//recursion
// a ^ n

int factorial(int n) {
  if (n == 1) {
    return 1;
  }
  return n * factorial(n-1);
}

int power (int n, int a) {
  if (n == 1) {
    return a;
  }
  return a * power(n-1,a);
}

int sum_vect(const std::vector<int> & v, int l, int h) {
  if (l == h) {
    return v[l];
  }
  int mid = (l+h)/2;
  return sum_vect(v,l,mid) + sum_vect(v,mid+1,h);
}

int main () {
  std::vector<int> v = {1,2,3,4,5,6};
  std::cout<< sum_vect(v,0,v.size()-1) <<std::endl;
  return 0;
}