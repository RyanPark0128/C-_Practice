#ifndef Q_H
#define Q_H
#include <iostream>

class queue {
  public:
    queue(int x);
    int dequeue();
    void enqueue(int x);
    bool is_empty();
    bool is_full();
  private:
    int * arr;
    int n;
    int f;
    int e;
    int size;
}

queue::queue(int x) {
  arr = new int[x];
  n = x;
  f = 0;
  e = 0;
  size = 0;
}

int queue::dequeue() {
  if (is_empty()) {
    std::cout << "EMPTY QUEUE";
    exit(1);
  }
  int ret = arr[f];
  f = (f + 1)%n;
  size--;
  return ret;
}

void queue::enqueue(int x) {
  if(is_full()) {
    std::cout << "FULL QUEUE";
    exit(0);
  }
  arr[e] =x;
  e = (e + 1) % n;
  size++;
}

bool queue::is_empty() {
  return size == 0;
}
bool queue::is_full() {
  return n == size;
}