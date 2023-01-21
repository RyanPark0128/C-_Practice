#include <iostream>
#include <cctype>
#include <vector>



int main () {
  std::string y = "";
  std::string x;
  bool check = true;
  while (check) {
    std::cin >> x;
    for (int i=0; i< x.size(); i++) {
      if (!std::isalpha(x[i])) {
        // std::cout << "reached";
        check = false;
      } else {
        y += x[i];
      }
    }
  }

  std::vector<std::string> v(y.size());
  for (int i=0; i< v.size(); i++) {
    v[i] = y[i];
  }

  
  return 0;
}