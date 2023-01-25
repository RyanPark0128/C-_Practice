#include <iostream>
#include <vector>
#include <ctime>

int sortRec(std::vector<int>& A, int n) {
  if (n==1)
    return 0;
  int count = sortRec(A, n - 1);
  int i;
  int tmp = A[n - 1];
  i = n-1;
  while (i>0 && ++count && A[i-1] >tmp) {
    A[i] = A[i-1];
    i--;
  }
  A[i] = tmp;
  return count;
}

double averageCase () {
  double count = 0;
  for (int i=0; i < 100; i++) {
    std::vector<int> v(10);
    for (int j=0; j < 10; j++) {
      v[j] = rand()%10;
    }
    count += sortRec(v, v.size());
  }
  return count / 100.00;
}

int main () {
  srand(time(0));
  std::vector<int> best = {0,1,2,3,4,5,6,7,8,9};
  std::vector<int> worst = {9,8,7,6,5,4,3,2,1,0};

  std::cout << averageCase() << std::endl;
  std::cout << "Number of comparisons for best case is: " << sortRec(best,10) << std::endl;
  std::cout << "Number of comparisons for worst case is: " << sortRec(worst,10) << std::endl;
  std::cout << "Number of comparisons for average case is: " << averageCase() << std::endl;
  
  return 0;
}