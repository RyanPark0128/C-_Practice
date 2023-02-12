#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <cmath>

class circle {
  public:
    circle();
    circle(int x, int y, int rad);
    void print();
    friend std::ostream &operator<<(std::ostream &out, const circle &c);
    circle operator+(const circle& c);
    friend bool operator==(const circle & c, const circle & b);

  private:
    struct point
    {
      int x, y;
    };
    point p;
    int r;
};

circle::circle(){
      p = {0, 0};
      r = 10;
}

circle::circle(int x, int y, int rad) {
      p = {x, y};
      r = rad;
}

void circle::print() {
      std::cout << "(" << p.x << "," << p.y << ")"
                << " radius = " << r << std::endl;
}

std::ostream& operator<<(std::ostream &out, const circle &c) {
      out << "(" << c.p.x << "," << c.p.y << ")"
          << " radius = " << c.r << std::endl;
      return out;
}

circle circle::operator+(const circle& c) {
      return circle(p.x+c.p.x, p.y+c.p.y ,r + c.r);
}

bool operator==(const circle & c, const circle & b) {
      if ((c.r + b.r) > sqrt(std::pow(c.p.x - b.p.x,2) + std::pow(c.p.y - b.p.y,2))) {
        return true;
      } 
      return false;
}
#endif