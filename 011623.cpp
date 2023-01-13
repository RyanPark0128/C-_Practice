#include <iostream>
#include <vector>

//recursion
// a ^ n

int factorial(int n) {
  if (n == 1) {
    return 1;
  }
  return n * factorial(n-1);
}

int power (int n, int a) {
  if (n == 1) {
    return a;
  }
  return a * power(n-1,a);
}

int sum_vect(const std::vector<int> & v, int l, int h) {
  if (l == h) {
    return v[l];
  }
  int mid = (l+h)/2;
  return sum_vect(v,l,mid) + sum_vect(v,mid+1,h);
}

bool is_pali(const std::string & s, int i, int j) {
  if (i >= j) {
    return true;
  }
  if (s[i] != s[j]) {
    return false;
  }

  return is_pali(s,i+1, j-1);
}

bool is_pali(std::string s) {
  int length = s.size()-1;
  return is_pali(s, 0, length);
}



int main () {
  std::vector<int> v = {1,2,3,4,5,6};
  // std::cout<< sum_vect(v,0,v.size()-1) <<std::endl;
  // std::cout << std::boolalpha << is_pali("racecar") <<std::endl;
  // std::cout << std::boolalpha << is_pali("abc") << std::endl;
  // std::cout << std::boolalpha << is_pali("tuyyut") <<std::endl;
  // std::cout << std::boolalpha << is_pali("tuy") <<std::endl; 
  // std::cout << std::boolalpha << is_pali("abba") <<std::endl;
  std::string s = "asd";
  std::string s2 = "asd";
  bool x = s == s2;

  std::cout << x << std::endl;
  return 0;
}