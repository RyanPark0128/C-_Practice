#include <iostream>
#include "ll.h"

int main() {
  ll l;
  l.insert(3);
  l.insert(5);
  l.insert(1);
  l.insert(10);
  l.insert(8);
  l.insert(13);
  l.insert(29);
  ll y = ll(l);
  ll x;
  x = l;
  x.remove(29);

  std::cout << x << std::endl;
  std::cout << l << std::endl;
  return 0;
}