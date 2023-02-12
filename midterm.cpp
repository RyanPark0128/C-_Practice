#include <iostream>
#include <vector>


int part(std::vector<int> &v, int low, int high, int piv)
{
  if (low > high) {
    return low;
  }

  if (piv < v[high]) {
    return part(v,low,high-1,piv);
  }

  if (piv > v[low]) {
    return part(v,low+1,high,piv);
  }
  int temp = v[low];
  v[low] = v[high];
  v[high] = temp;
  return part(v,low+1,high-1,piv);

  // while (low <= high) {
  //   while (piv > v[low]) {
  //     low++;
  //   }
  //   while (piv < v[high]) {
  //     high--;
  //   }
  //   if (low <= high) {
  //     int temp = v[low];
  //     v[low] = v[high];
  //     v[high] = temp;
  //     low++;
  //     high--;
  //   }
  // }
  // return low;
}

void qs(std::vector<int> &v, int low, int high)
{
  if (low >= high)
  {
    return;
  }
  int pivot = part(v, low, high, v[low]);
  qs(v, low, pivot - 1);
  qs(v, pivot, high);
}

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

  // if (i <= a_end && j <= b_end) {
  //   if (v[i] < v[j]) {
  //     w[k++] = v[i++];
  //   } else if (v[j] < v[i]) {
  //     w[k++] = v[j++];
  //   } else {
  //     w[k++] = v[i++];
  //     w[k++] = v[j++];
  //   }
  // }


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


int isSorted(const std::vector<int> & v, int i =1) {
  if (i > v.size()-1) {
    return 1;
  }

  if (v[i-1] >= v[i]) {
    return 0;
  }

  return isSorted(v,i+1);
}

int sumThing(std::vector<int> & v, int sum, std::string s = "",int total = 0, int count = 0) {
  if (total == sum) {
    std::cout << s << std::endl;
    return 1;
  }

  if (total > sum) {
    return 0;
  }

  for (int i =0; i < v.size(); i++) {
    count += sumThing(v,sum, s+ std::to_string(v[i]),total+v[i]);
  }

  return count;
}

void lower_case (std::string & s) {
  for (int i=0; i< s.size(); i++) {
    if (s[i] < 97) {
      s[i] = s[i] + 32;
    }
  }
}
std::string string_gen (std::string & s) {
  lower_case(s);
  std::string x = "";
  for (int i = 0; i< 26; i++) {
    char y = i + 97;
    bool check = true;
    for (int j =0; j< s.size(); j++) {
      if (y == s[i]) {
        check = false;
      }
    }
    if (check) {
      x = x + y;
    }
  }

  return x;
}

std::string string_recur (std::string & s, std::string x = "", int i = 0) {
  if (i > 25) {
    return x;
  }
  char y = i + 97;
  bool check = true;
    for (int j =0; j< s.size(); j++) {
      if (y == s[j]) {
        check = false;
      }
    }
  if (check) {
      return string_recur(s,x+y,i+1);
  }
  return string_recur(s,x,i+1);
  
}


int main() {
  std::vector<int> v = {2,4,6,8};
  // qs(v,0,v.size()-1);
  // ms(v);
  // std::cout << sumThing(v,10) <<std::endl;
  std::string a = "zayb";
  lower_case(a);
    std::cout <<   a <<std::endl;
  std::cout <<   string_recur(a) <<std::endl;
  // std::cout << std::endl;
  // for (auto x:v) {
  //     std::cout << x << std::endl;
  // }

  return 0;
}