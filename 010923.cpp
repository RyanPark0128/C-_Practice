#include <iostream>
//Overloading
//prototyping
//global variable

int thing = 7;


// Times a number by 2
// input: int x that is timed by 2
// output: the result of the math
int times2 (int x = 3, int y =1) {
  return x*y;
}

int times2 (int x) {
  return x*5;
}

int main () {
  int x = times2(2);
  std::cout << x << std::endl;
  return 0;

}
