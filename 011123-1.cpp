#include <iostream>


void print_arr(int a[], int n) {
  for(int i =0; i< n; i++) {
    std::cout << a[i];
  }

}

void print_m(int a[][3], int row, int col) {
  for (int i =0; i < row; i++) {
    for (int j=0; j< col; j++) {
      std::cout << a[i][j] << " ";
    }

    std::cout << std::endl;
  }
}
int main () {

  // array sizes need to be literal value or constant value
  // int SIZE = 8;
  // int arr[SIZE];
  // int arr2[] = {1,2,3,4};

  //assigns every value with 0;
  // int arr3[8] = {0}

  // std::cout << arr << std::endl;


  // 2d dimentional arrays
  int m[3][3];
  print_m(m,2,2);


  return 0;
}