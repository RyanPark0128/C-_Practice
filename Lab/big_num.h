#ifndef BIGNUM_H
#define BIGNUM_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

class big_num {
   public:
      big_num(std::string str);
      friend std::ostream& operator << (std::ostream& out,  big_num&);
      friend big_num operator +( big_num& num, big_num& num1);
      int& operator [](int i)  {return digits[i];}
      int size() const {return digits.size();}   
   private:
      std::vector<int> digits; // an array of numDigits digits 
};

big_num::big_num(std::string str) {
   digits.resize(str.size());
   reverse(str.begin(), str.end());
   for (int i=0; i < str.size(); i++) {
      digits[i] = str[i] - 48;
   }
}

big_num operator +(big_num& num, big_num& num1) {
   big_num temp = num;
   int min_size = std::min(num.size(),num1.size());
   int max_size = std::max(num.size(),num1.size());
   temp.digits.resize(max_size);
   int carry = 0;

   for (int i=0; i < min_size; i++) {
      if (carry > 0) {
         if ((num[i] + num1[i] + carry) == 10) {
            temp[i] = 0;
         } else if ((num[i] + num1[i] + carry) > 10){
            temp[i] = ((num[i] + num1[i])%10) + 1;
         } else {
            temp[i] = num[i] + num1[i] + 1;
            carry = 0;
         }
      } else if (carry == 0) {
         if ((num[i] + num1[i]) == 10) {
            temp[i] = 0;
            carry = 1;
         } else if ((num[i] + num1[i] + carry) > 10){
            temp[i] = ((num[i] + num1[i])%10);
            carry = 1;
         } else {
            temp[i] = num[i] + num1[i];
            carry = 0;
         }
      }
   }
   while (carry) {
      if (min_size > max_size) {
         temp.digits.resize(min_size);
         temp[min_size] += 1;
      }
      if ((temp[min_size] + 1) > 9 ) {
         temp[min_size] = 0;
         min_size++;
      }
      else{
         temp[min_size] += 1;
         carry = 0;
      }
      // if (carry && min_size == max_size) {
      //    temp.digits.resize(min_size+1);
      //    temp[min_size] += 1;
      // } else if (carry) {
      //    temp[min_size] += 1;
      // }
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