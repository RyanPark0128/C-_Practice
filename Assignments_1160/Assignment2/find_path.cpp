#include <iostream>
#include <vector>
#include <fstream>

//initial idea:
//The path_finder should find path to destination and have equal number of -1 and 1.
//which means that the sum of the number it passes through should equal to 0 (count)
//First, I call function recursively to every direction (south, north, west, east)
// with selection statement to check bounds and check if the path was previously accessed.
// after we call the function recursively, if we fail to reach the destination or count is not equal to 0,
// we want to rewrite the value to '-' at the position to go back to previous position.
// If we successfully reach the destinaton with correct count, we return true for all the previous recursive call
// and finishes the function returning true.

// input: the input for path_finder is 2d vector for the number matrix, 2d vector to track the path, current col, row , and count for sum.
// output: after going through recursion calls, it will return true if it finds the correct path. It returns false otherwise.
bool path_finder (std::vector<std::vector<int>> & v,std::vector<std::vector<char>> & map,  int col, int row, int count = 0) {

  // if current col and row are at the destination and the sum of the number matrix to the path equals 0, it reached the destination
  // declare X at the col and row and return true.
  if (col == v[row].size()-1 && row == v.size()-1 && count + v[row][col] == 0) {
    map[row][col] = 'X';
    return true;
  }

  // checks bound for downward direction and check if it was previously accessed.
  // If it is valid, we decide to go down ('V') and call the function recursively.
  // if the recursive function returns true, it means that this path is part of the correct path.
  // therefore return true with out going further down the function
  if (row < v.size()-1 && map[row+1][col] == '-') {
    map[row][col] = 'V';
    if (path_finder (v,map,col,row+1, count + v[row][col])) {
      return true;
    }
  } 

  // checks bound for upward direction and check if it was previously accessed.
  // If it is valid, we decide to go up ('^') and call the function recursively.
  // if the recursive function returns true, it means that this path is part of the correct path.
  // therefore return true with out going further down the function
  if (row > 0 && map[row-1][col] == '-') {
    map[row][col] = '^';
    if (path_finder (v,map,col,row-1, count + v[row][col])) {
      return true;
    }
  }

  // checks bound for right direction and check if it was previously accessed.
  // If it is valid, we decide to go right ('>') and call the function recursively.
  // if the recursive function returns true, it means that this path is part of the correct path.
  // therefore return true with out going further down the function  
  if (col < v[row].size()-1 && map[row][col+1] == '-') {
    map[row][col] = '>';
    if (path_finder (v,map,col+1,row,count + v[row][col])) {
      return true;
    }
  }

  // checks bound for left direction and check if it was previously accessed.
  // If it is valid, we decide to go left ('<') and call the function recursively.
  // if the recursive function returns true, it means that this path is part of the correct path.
  // therefore return true with out going further down the function
  if (col > 0 && map[row][col-1] == '-') {
    map[row][col] = '<';
    if (path_finder (v,map,col-1,row, count + v[row][col])) {
      return true;
    }
  }

  // if all direction fails, mark the current position with '-' and returns false because correct path does not exist on this instance. returns false
  map[row][col] = '-';
  return false;
}


//input: takes in input value from user as string
//output: the readIn function populates the 2d vector from the file and returns the 2d vector.
std::vector<std::vector<int> > readIn(std::string file){
    std::ifstream fin;
    fin.open(file);
    int row,col;
    fin >> row >> col;
    std::vector<std::vector<int> > m(row,std::vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            fin >> m[i][j];
        }
    }
    return m;
}

// I used template so that it could be used with different type (2d vector<int>, 2d vector<char>),
// because same function can be used for printing OG matrix, and path matrix.
// input: the function takes it 2d vector
// output: the function loops through the 2d vector and prints the content to the console.
template <typename T>
void print_matrix (T & m) {
  for (int i=0; i< m.size(); i++) {
    for (int j=0; j < m[i].size(); j++) {
      if (m[i][j] < 0) {
        std::cout << " " << m[i][j] << "  ";
      } else {
        std::cout << "  " << m[i][j] << "  ";
      }
    }
    std::cout << std::endl;
  }
}

int main () {
  // guide message for user
  std::cout << "Name of the file with the matrix" << std::endl;
  // initialize and declare userinput into a string variable.
  std::string input;
  std::cin >> input;
  // invoke readIn function to get the 2d vector (OG matrix)
  std::vector<std::vector<int>> v = readIn(input);
  std::cout << "OG matrix" << std::endl;
  // prints matrix
  print_matrix(v);
  // initialize and populate our map
  std::vector<std::vector<char>> map(v.size(), std::vector<char>(v[0].size(), '-'));
  // if the path_finder returns with true, it means we found the path to destination
  // therefore, we print the path.
  // otherwise alert user that there is no path available.
  if (path_finder(v,map, 0,0)) {
    std::cout << std::endl;
    std::cout << "Path matrix" << std::endl;
    print_matrix(map);
  } else {
    std::cout << "No path found" << std::endl;
  }
  return 0;
}