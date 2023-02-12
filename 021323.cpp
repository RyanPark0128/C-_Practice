#include <iostream>
#include <vector>
#include "circle.h"


int main()
{
  circle c(5, 1, 7);
  circle c2(20, 1, 7);
  std::vector<circle>cir_list(10);
  // c.print();
  // bool t = c==c2;
  // std::cout << (c==c2) << std::endl;
  // operator<<(std::cout, c);
  // std::cout << (c==c2) <<std::endl;

  std::cout << c;
  std::cout << (c==c2) <<std::endl;
  return 0;
}