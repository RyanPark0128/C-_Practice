#include <iostream>
//Overloading
//prototyping
//global variable

//global variable usually capitalized and declared as constant (const)

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

// & used as reference to edit the variable during the function.
void min_max(int a, int b, int & min, int & max) {
  min = a;
  max = b;
  if (a > b) {
    min = b;
    max = a;
  }
  return;
}

void fun(std::string & s) {
  s[1] = 'A';
}

std::string test(std::string x) {
  x[1] = 'B';
  return x;
}

int main () {
  // int x = times2(2);
  // std::cout << x << std::endl;
  int min,max;
  min_max(34,6, min,max);
  std::cout << min << " " << max << std::endl;
  std::string s = "Hello";
  fun(s);
  std::cout << s << std::endl;

  std::cout << test("yes") << std::endl;
  return 0;

}
