#include <iostream>
#include <cstdlib>
#include <string>
#include "big_num_dy.h"


int main() {
   std::string str;
   std::cout << "Enter a number: ";
   getline(std::cin,str);
   big_num x(str);
   std::cout << "Enter a number: ";
   getline(std::cin,str);
   big_num y(str);
   std::cout << x << std::endl;
   big_num result = (x+y);
   std::cout << x  <<"  +  " << y << " = " << result;
   std::cout << std::endl;
   return 0;
}