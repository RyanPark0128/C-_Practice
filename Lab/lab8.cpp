#include <iostream>
#include "ll.h"

int main () {
  std::string x;
  std::string y;
  std::cout << "Enter a number" << std::endl;
  std::cin >> x;
  std::cout << "Enter a number" << std::endl;
  std::cin >> y;

  ll list1;
  ll list2;
  for (int i=0; i< x.size(); i++) {
    list1.insert(x[i]-48);
  }

  for (int i=0; i< y.size(); i++) {
    list2.insert(y[i]-48);
  }
  std::cout << list1 << std::endl;
  std::cout << list2 << std::endl;

  ll list3 = list1.merge(list2);

  std::cout << list3 << std::endl;
  
  return 0;
}