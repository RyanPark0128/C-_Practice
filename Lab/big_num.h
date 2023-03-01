#ifndef BIGNUM_H
#define BIGNUM_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

class big_num {
   public:
      big_num(std::string str);
      friend std::ostream& operator << (std::ostream& out,  big_num&);
      friend big_num operator +( big_num& num, big_num& num1);
      int& operator [](int i)  {return digits[i];}
      int size() const {return digits.size();}   
   private:
      std::vector<int> digits; // an array of numDigits digits 
      big_num(int size) {
         digits.resize(size);
      }
};

big_num::big_num(std::string str) {
   digits.resize(str.size());
   reverse(str.begin(), str.end());
   for (int i=0; i < str.size(); i++) {
      digits[i] = str[i] - 48;
   }
}

big_num operator +(big_num& num, big_num& num1) {
   big_num temp = num.size() >= num1.size() ? num : num1;
   int smaller = fmin(num.size(), num1.size());
   int carry = 0;
   for (int i = 0; i< smaller; i++) {
      if ((num[i] + num1[i] + carry) > 9) {
         temp[i]= (num[i] + num1[i] + carry) % 10;
         carry = 1;
      } else {
         temp[i]= num[i] + num1[i] + carry;
         carry = 0;
      }
   }

   while (carry == 1 && smaller < temp.size()) {
      if ((temp[smaller] + carry) > 9) {
         temp[smaller]= 0;
         carry = 1;
         smaller++;
      } else {
         temp[smaller] += carry;
         carry = 0;
      }
   }
   
   if (carry) {
      temp.digits.push_back(1);
   }

   return temp;
}

std::ostream& operator << (std::ostream& out,  big_num& num) {
   for (int i=num.size()-1; i >= 0; i--) {
      out << num[i];
   }
   return out;
}


#endif 