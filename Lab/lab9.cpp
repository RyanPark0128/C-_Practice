#include <iostream>
#include "stack.h"

int main(){
  std::cout << "Enter a equation" << std::endl;
  std::string s;
  std::cin >> s;
  stack h;
  for (int i=0; i< s.size(); i++) {
    if (s[i] >= 48 && s[i] <= 57) {
      h.push(s[i] - 48);
    } 
    
    else {
      if (s[i] == '+') {
        double tmp1 = h.pop();
        double tmp2 = h.pop();
        h.push(tmp1 + tmp2);
      } else if (s[i] == '-') {
        double tmp1 = h.pop();
        double tmp2 = h.pop();
        h.push(tmp2 - tmp1);
      } else if (s[i] == '*') {
        double tmp1 = h.pop();
        double tmp2 = h.pop();
        h.push(tmp2 * tmp1);
      } else if (s[i] == '/') {
        double tmp1 = h.pop();
        double tmp2 = h.pop();
        h.push(tmp2 / tmp1);
      }
    }
  }
  std::cout << std::endl;
  while (!h.is_empty()) {
    std::cout << h.pop() <<std::endl;
  }
  return 0;
}


