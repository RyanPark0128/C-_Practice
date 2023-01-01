#include <iostream>
#include <fstream>

int main () {
  std::ifstream fin;
  std::string line;
  char c;
  fin.open("./example.txt");
  if(fin.is_open()) {
    // line by line
    while(getline(fin, line)) {
      std::cout << line << std::endl;
    }

    // word by word
    while(fin >> line) {
      std::cout << line << std::endl;
    }

    // by character
    while(fin >> c) {
      std::cout << c << std::endl;
    }

    // other ways of doing it
    while(!fin.eof()) {
      fin >> line;
      std::cout << line << std::endl;
    }

  }
  return 0;
}