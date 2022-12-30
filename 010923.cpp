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

// when passing variables to reference perimeter, only pass declared variable, unless using const in front of the perimeter
// template : flexability on the perimeter type
template <typename T>
void print(const T & s) {
  std::cout << s << std::endl;
}
template<typename T>
void my_swap(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;

    std::cout << a << " " << b << std::endl;
}
int main () {
  // int x = times2(2);
  // std::cout << x << std::endl;
  // int min,max;
  // min_max(34,6, min,max);
  // std::cout << min << " " << max << std::endl;
  // std::string s = "Hello";
  // fun(s);
  // std::cout << s << std::endl;

  // std::cout << s << std::endl;
  // print("World");
  // print<double>(2);
  // print(2.3);
  int x = 1;
  int y = 5;
  my_swap(x,y);
  
  return 0;

}
