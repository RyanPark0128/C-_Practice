#ifndef POINT_H
#define POINT_H
#include <iostream>

class point {
  public:
    point(int nx, int ny) {
      y = ny;
      x = new int;
      *x = nx;
    }
    friend std::ostream& operator<<(std::ostream& out, const point &p) {
      out << *p.x << " " << p.y;
      return out;
    }
    ~point(){
      delete x;
    }

    point(const point & rhs) {
      this->y = rhs.y;
      std::cout << *this;
    }
    ]
  private:
    int *x, y;
}