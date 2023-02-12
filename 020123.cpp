#include <iostream>
#include <vector>
// T(1) = 0
// T(n) = n-1 + 2T(n/2)
void merge(std::vector<int> & v, int a_start, int a_end, int b_start, int b_end, std::vector<int> & w) {
  int i= a_start;
  int j =b_start;
  int k = a_start;

  while (i <= a_end && j <= b_end) {
    if (v[i] < v[j]) {
      w[k++] = v[i++];
    } else if (v[j] < v[i]) {
      w[k++] = v[j++];
    } else {
      w[k++] = v[i++];
      w[k++] = v[j++];
    }
  }
  while(i <= a_end) {
    w[k++] = v[i++];
  }
  while (j <= b_end) {
    w[k++] = v[j++];
  }
  for (int x =a_start; x <= b_end; x++) {
    v[x] = w[x];
  }
}

void ms(std::vector<int> & v, int low, int high, std::vector<int> & w) {
  if (low == high) {
    return;
  }

  int mid = (high + low) / 2;
  ms(v,low,mid,w);
  ms(v,mid+1, high, w);
  merge(v,low,mid,mid+1,high,w);
}

void ms(std::vector<int> & v) {
  std::vector<int> w(v.size());
  ms(v,0,v.size()-1,w);
}

int main () {
  std::vector<int> v = {5,2,8,12,7,9,10};
  return 0;
}

