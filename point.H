#ifndef POINT_H
#define POINT_H
#include <iostream>

class point {
  public:
    point(int nx, int ny) {
      y = ny;
      x = new int;
      *x = nx;
      std::cout << this->x << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& out, const point &p) {
      out << *p.x << " " << p.y;
      return out;
    }
    ~point(){
      // std::cout << "delete" <<std::endl;
      delete x;
    }

    point(const point & rhs) {
      // std::cout << "copy" <<std::endl;
      // (*this).y = rhs.y;
      this->y = rhs.y;
      // std::cout << *this;
      this->x = new int (*rhs.x);
    }
    
    const point& operator=(const point & rhs) {
      // std::cout << "assign" <<std::endl;
      if(this == &rhs) {
        return *this;
      }
      delete x;
      (*this).y = rhs.y;
      this->x = new int (*rhs.x);
      return *this;
    }

  private:
    int *x, y;
};

#endif