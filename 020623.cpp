#include <iostream>
#include <vector>

struct point {
  // you can declare to set the default value
  int x = 4;
  int y = 12;

  bool operator ==(const point & p) {
    if (x == p.x && y == p.y) {
      return true;
    }
    return false;
  }
  std::string to_string() {
    std::string str = std::to_string(x);
    str += "," + std::to_string(y);
    return str;
  }
};

int main () {
  point p;
  point q;
  std::vector<point> p_list(10);
  p.x = 4;
  p.y = 12;
  // std::cout << p.to_string() << std::endl;
  std::cout << p == q << std::endl;
  return 0;
}