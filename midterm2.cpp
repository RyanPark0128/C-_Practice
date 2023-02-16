#include <iostream>
#include <vector>



void merge(std::vector<int> &v, int a_start, int a_end, int b_start, int b_end, std::vector<int> & w, int i, int j, int k) {

  if (i > a_end && j > b_end) {
    for (int i = a_start; i <= b_end; i++) {
      v[i] = w[i];
    }
    return;
  }
  if (i <= a_end && j <= b_end) {
    if (v[i] < v[j]) {
      w[k++] = v[i++];
      merge(v,a_start,a_end,b_start,b_end,w,i,j,k);
      return;
    } if (v[i] > v[j]) {
      w[k++] = v[j++];
      merge(v,a_start,a_end,b_start,b_end,w,i,j,k);
      return;
    }
    w[k++] = v[i++];
    w[k++] = v[j++];
    merge(v,a_start,a_end,b_start,b_end,w,i,j,k);
    return;
  }

  if (i <= a_end) {
    w[k++] = v[i++];
    merge(v,a_start,a_end,b_start,b_end,w,i,j,k);
    return;
  }
  if (j <= b_end) {
    w[k++] = v[j++];
    merge(v,a_start,a_end,b_start,b_end,w,i,j,k);
    return;
  }

  // while (i <= a_end && j <= b_end) {
  //   if (v[i] < v[j]) {
  //     w[k++] = v[i++];
  //   } else if (v[i] > v[j]) {
  //     w[k++] = v[j++];
  //   } else {
  //     w[k++] = v[i++];
  //     w[k++] = v[j++];
  //   }
  // }

  // while (i <= a_end ) {
  //   w[k++] = v[i++];
  // }

  // while (j <= b_end){
  //   w[k++] = v[j++];
  // }

  // for (int i = a_start; i <= b_end; i++) {
  //   v[i] = w[i];
  // }

}

void ms(std::vector<int> & v, int low, int high, std::vector<int> & w) {
  if (low == high) {
    return;
  }

  int mid = (low+high) / 2;
  ms(v,low,mid,w);
  ms(v,mid+1,high,w);
  merge(v,low,mid,mid+1,high,w,low,mid+1,low);
}


int part(std::vector<int> & v, int low, int high) {
  int piv = v[low];

  while (low <= high) {
    while (piv < v[high]) {
      high--;
    }
    while (piv > v[low]) {
      low++;
    }
      if (low <= high) {
      int temp = v[low];
      v[low] = v[high];
      v[high] = temp;
      high--;
      low++;
      }
  }
  // v[low] = piv;
  return low;
}

void qs(std::vector<int> &v, int low, int high) {
  if (low >= high) {
    return ;
  }

  int pivot = part(v,low,high);
  qs(v, low, pivot-1);
  qs(v, pivot, high);
}

bool isPalindrome (std::string & s, int n) {
  if (n == s.size()/2) {
    return true;
  }

  if (s[n] != s[s.size()-1-n]) {
    return false;
  }

  return isPalindrome(s,n+1);
}

int main () {

  std::vector<int> v = {5,7,9,2,1,-5,10};
  std::vector<int> w (v.size());
  // std::string s = "anaana";
  ms(v,0,v.size()-1, w);
  // qs(v,0,v.size()-1);
  // std::cout << isPalindrome(s, 0) << std::endl;
  for (auto x:v) {
    std::cout << x << std::endl;
  }
  return 0;
}
