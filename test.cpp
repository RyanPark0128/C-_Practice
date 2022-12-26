//Lecture 1 2023-01-04

#include <iostream>
#include <ctime> // time into computer, generate random values

int main() {
  srand(time(0));
  int x = 42;
  // if you add int to a string, corresponding ASCII char will be added

  // unsigned x = 42;
  // only positive

  std::string s;
  std::string y = "Hello World";
  s += " world";
  s += '!';
  s += std::to_string(x);

  std::cout << s.size() << std::endl; //length of string

  // std::cout << "enter something" << std::endl;
  // std::cin >> s;  // uses space as delimiter
  // std::cout << "You entered " << s << std::endl;

  // std::cout << "enter something" << std::endl;
  // getline(std::cin,y); //reads the whole line as string
  // std::cout << "You entered " << y << std::endl;

  std::cout << s << std::endl;
  s[0] = 'D'; // use single quote to specifically set it as char
  std::cout << s <<std::endl;

  //for loops, if, while loops, are essentially the same


// s[i] vs s.at(i)   .at checks bound and breaks if we go out of bound
for (int i=0; i < 10; i++) {
  std::cout << (rand()%10 +1) << std::endl;
}
// rand() % 10 + 1     generates 1 to 10


  return 0;
}