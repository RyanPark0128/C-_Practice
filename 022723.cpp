#include <iostream>
// memory management

int main () {

// * means memory address
// * modifies varaible but not type. example: int *a,c; int *a,*c
// never dereference something that has not been declared with value;
  int *a;
  int b = 5;

  // & means it points to specific memory location.
  a = &b;
  *a = 6;

  // making reference to different type will cause error. pointer can only point to same type (You cant cast it).


  std::cout << b;
  return 0;
}