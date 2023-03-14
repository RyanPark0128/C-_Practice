#include <iostream>
#include "matrix.h"

int main() {
   Matrix m1("m1.txt");
   Matrix m2("m2.txt");
   Matrix m3("m3.txt");
   std::cout << "(M1)--------------------" << std::endl;
   std::cout<<m1;
   Matrix m4 = Matrix(m3);
   std::cout << "(M4)--------------------" << std::endl;
   std::cout<<m4;
  //  std::cout << "(M3)--------------------" << std::endl;
  //  std::cout <<m3;
  //  std::cout << "(M1==M1)------------------" << std::endl;
  //  std::cout<<((m1==m1)? "TRUE":"FALSE") << std::endl;
  //  std::cout << "(M1==M2)------------------" << std::endl;
  //  std::cout<<((m1==m2)? "TRUE":"FALSE") << std::endl;
   

  //  Arr m4 = m1*m1[1][2];
  //  std::cout << "(M4)--------------" << std::endl;
  //  std::cout << m4 << std::endl;

  //  Arr m5;
  //  m5 = m1 + m2;
  //  std::cout << "(M5)-------------------" << std::endl;
  //  std::cout << m5 << std::endl;
  //  std::cout << "(M5-M2)------------------" << std::endl;
  //  std::cout << (m5 - m2);
  //  std::cout << "((M5-M2)*M3)-----------------" << std::endl;
  //  std::cout << (m5 - m2)*m3;
  //  std::cout << "(M1*M3)------------------" << std::endl;
  //  std::cout << m1*m3;
  //  std::cout << "(M3*M1)------------------" << std::endl;
  //  std::cout << m3*m1;
   return 0;
}

