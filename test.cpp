//Lecture 1 2023-01-04

#include <iostream>

int main() {
  int x = 42;
  // if you add int to a string, corresponding ASCII char will be added
  std::string s;
  std::string y = "Hello World";
  s += " world";
  s += '!';
  s += std::to_string(x);

  // std::cout << "enter something" << std::endl;
  // std::cin >> s;  // uses space as delimiter
  // std::cout << "You entered " << s << std::endl;

  // std::cout << "enter something" << std::endl;
  // getline(std::cin,y); //reads the whole line as string
  // std::cout << "You entered " << y << std::endl;

  std::cout << y << std::endl;
  y[0] = 'D'; // use single quote to specifically set it as char
  std::cout << y << std::endl;


  return 0;
}