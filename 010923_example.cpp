#include <iostream>
#include <cmath>

int my_pow(int x, int n = 4) {
  return pow(x,n);
}

int main() {
  std::cout << my_pow(2) << std::endl;
}