#include <iostream>
#include <vector>
#include <cmath>

void forward(int n) {
  if (n == -1) {
    return;
  }

  forward(n-1);
  std::cout << n << ",";
}
void backward(int n) {
  if (n == -1) {
    return;
  }
  std::cout << n << ",";
  backward(n -1);
};
int sumR(int n) {
  if (n <= 0) {
    return n;
  }

  return n + sumR(n-1);
};
int sumDigits(int n) {
  if (n == 0) {
    return 0;
  }
  return (n % 10) + sumDigits(n / 10);
};

int maxR(const std::vector<int> &v,int i = 0) {
  if (i == v.size()) {
    return 0;
  }

  return std::max(v[i], maxR(v, i+1));
};
void revV(std::vector<int> &v,int i = 0) {
  if (i == v.size()/2) {
    return;
  }
  int temp = v[i];
  v[i] = v[v.size()-1 - i];
  v[v.size()-1 - i] = temp;
  revV(v, i+1);
}

int main(){
  int n;
  std::vector<int> v = {3,16,2,19,7,11,3};
  std::cout <<"Enter an positive integer:";
  std::cin >> n;
  forward(n);
  std::cout << std::endl;
  backward(n);
  std::cout << std::endl; 
  std::cout << sumR(n) << std::endl;
  std::cout <<"Enter an positive integer:";
  std::cin >> n;
  std::cout << sumDigits(n) << std::endl;
  std::cout << "Max in vector = " << maxR(v) << std::endl; 
  revV(v);
  std::cout << "The vector is now reversed" << std::endl;
  std::cout << "[";
  for(auto i:v){
    std::cout << i << ",";
  }  
  std::cout << "]" << std::endl;
  return 0; 

}