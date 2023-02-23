#include <iostream>
// memory management

struct point {
  int z,y;
  void to_string() {

  }
};

//example of swap function
void swap (int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
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


int c = 5;
int d = 6;
swap(&c, &d);

// using "new" will create dynamic memory and responsible for managing memeory.
// assign value
int *x = new int(5);
// frees up the memory.
delete x;
// set it to nullptr if you are done with it.
a = nullptr;
// assign random vaue;
// int *x = new int;

// memory leak if you dont have access to memory location.

// to check if it is nullptr or not
// if (!p)

point *p = new point;
p->y = 6;


  std::cout << (*p).y << std::endl;
  return 0;
}