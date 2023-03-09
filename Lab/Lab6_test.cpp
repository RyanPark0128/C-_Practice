#include <iostream>

int main() {
  int num = 5;
  int* pointer = &num;

  std::cout << num << std::endl;
  std::cout << pointer << std::endl;
  std::cout << *pointer << std::endl;

  int *x = new int(5);

  return 0;
}