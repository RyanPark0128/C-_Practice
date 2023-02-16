#include <iostream>
#include <vector>
#include <algorithm>

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
      w[k] = v[i];
      k++;
      i++;
    } else if (v[j] < v[i]) {
      w[k] = v[j];
      k++;
      j++;
    } else {
      w[k] = v[i];
      k++;
      i++;
      w[k] = v[j];
      k++;
      j++;
    }
  }
  while(i <= a_end) {
    w[k] = v[i];
    k++;
    i++;
  }
  while (j <= b_end) {
    w[k] = v[j];
    k++;
    j++;
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

void merge_recur(std::vector<int> & v, int a_start, int a_end, int b_start, int b_end, std::vector<int> & w, int i, int j, int k) {
  if (i > a_end && j > b_end) {
    for (int x =a_start; x <= b_end; x++) {
      v[x] = w[x];
    }
    return;
  }
  if (i <= a_end && j <= b_end) {
    if (v[i] < v[j]) {
    w[k] = v[i];
    merge_recur(v,a_start,a_end,b_start,b_end,w,i+1,j,k+1);
    return;
    } else if (v[j] < v[i]) {
      w[k] = v[j];
      k++;
      j++;
      merge_recur(v,a_start,a_end,b_start,b_end,w,i,j,k);
      return;
    } else {
      w[k] = v[i];
      k++;
      i++;
      w[k] = v[j];
      k++;
      j++;
      merge_recur(v,a_start,a_end,b_start,b_end,w,i,j,k);
      return;
    }
  }

  if (i <= a_end) {
    w[k] = v[i];
    k++;
    i++;
    merge_recur(v,a_start,a_end,b_start,b_end,w,i,j,k);
    return;
  }
  if (j <= b_end) {
    w[k] = v[j];
    k++;
    j++;
    merge_recur(v,a_start,a_end,b_start,b_end,w,i,j,k);
    return;
  }
}


void ms(std::vector<int> & v, int low, int high, std::vector<int> & w) {
  if (low == high) {
    return;
  }

  int mid = (high + low) / 2;
  ms(v,low,mid,w);
  ms(v,mid+1, high, w);
  merge_recur(v,low,mid,mid+1,high,w,low,mid+1,low);
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



int sumThing(std::vector<int> & v, std::vector<std::string> & x, int sum, std::string s = "",int total = 0,int j = 0) {
  if (total == sum) {
    /*std::sort(s.begin(), s.end());
    for (int i =0; i < x.size(); i++) {
      if (s == x[i]) {
        return 0;
      }
    }
    */
    // std::cout << s << std::endl;
    return 1;
  }
  int count = 0;
  if (total > sum) {
    return 0;
  }

  for (int i =j; i < v.size(); i++) {
    count += sumThing(v,x,sum, s+std::to_string(v[i]),total+v[i],i);
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

  std::vector<bool> check (26, true);
  std::string x = "";
  for (int i =0 ; i <s.size(); i++) {
    check[(s[i] - 97)] = false;
  }

  for (int i=0; i <check.size(); i++) {
    if (check[i]) {
      char y = i+97;
      x += y;
    }
  }

  // std::cout << x << std::endl;

  return x;
}


int main() {
  std::vector<int> v = {2,4,6,8};
  std::vector<std::string> x;
  std::vector<std::string> y = {"sad", "notsad", "yessad"};

  // string_gen(x);
  // qs(v,0,v.size()-1);
  // ms(v);
  // std::cout << sumThing(v,x,10) << std::endl;
    // std::vector<bool> check (26, true);
  std::string a = "zayb";
  // lower_case(a);
    // std::cout <<   a <<std::endl;
    std::cout << a << std::endl;
  std::cout <<   string_gen(a) <<std::endl;
  // std::cout << std::endl;
  // for (auto x:check) {
  //     std::cout << x << std::endl;
  // }

  return 0;
}


// useful method to know
// std::to_string(int value)
//
