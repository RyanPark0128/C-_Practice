#include <iostream>
#include <cctype>
#include <vector>

// Initial Idea:
// To find every possible combination by user input, It would be best to use recursion.
// My hypothesis is that every time i run function 


void combination (std::vector<std::string> & v, std::string r, std::string s = "") {
  if (r.size() == 0) {
    v.push_back(s);
  }
  for (int i=0; i< r.size(); i++) {
    std::string temp_s = s;
    std::string temp_r = r;
    temp_r.erase(i,1);
    temp_s = temp_s + r[i] + " ";
    combination(v, temp_r, temp_s);
  }
}

void printCombination(std::vector<std::string> & v) {
  for (int i=0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
  }
}

int main () {
  std::string y = "";
  std::string x;
  bool check = true;
  while (check) {
    std::cin >> x;
    for (int i=0; i< x.size(); i++) {
      if (!std::isalpha(x[i])) {
        check = false;
        break;
      } else {
        y += x[i];
      }
    }
  }
  std::cout << "printing" << std::endl;
  std::vector<std::string> v;
  combination(v, y);
  printCombination(v);


  return 0;
}