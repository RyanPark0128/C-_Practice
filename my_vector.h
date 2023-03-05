#ifndef MV_H
#define MV_H

class my_vector {
  public:
    my_vector(int N) {
      arr = new int[N];
      size = N;
      n = 0;
    }
    my_vector() {
      arr = new int[0];
      size = 0;
      n = 0;
    }
    int len() {
      return n;
    }
    void append(int x) {
      if (size == n) {
        size = size*2 + 1;
        int * brr = new int[size];
        for (int i =0; i< n; i++) {
          brr[i] = arr[i];
        }
        delete[] arr;
        arr = brr;
      }
      arr[n++] = x;
    }
    int & operator[] (int i) {
      if (i < 0 || i >= n) {
        std::cout << "Out of bounds" << std::endl;
        exit(1);
      }
      return arr[i];
    }

    ~my_vector() {
      delete[] arr;
    }
    my_vector(const my_vector& rhs) {
      this->n = rhs.n;
      this->size = rhs.size;
      this->arr = new int[this->size];
      for (int i=0; i< this->n; i++) {
        this->arr[i] = rhs.arr[i];
      }
    }
    const my_vector& operator= (const my_vector&) {
      if (this == &rhs) {
        return *this;
      }
      delete[] arr;

      this->n = rhs.n;
      this->size = rhs.size;
      this->arr = new int[this->size];
      for (int i=0; i< this->n; i++) {
        this->arr[i] = rhs.arr[i];
      }
      return *this;
    }
  
  private:
    int size;
    int *arr;
    int n;

};

#endif