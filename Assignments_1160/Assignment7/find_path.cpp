#include <iostream>
#include <vector>
#include <fstream>
#include "stack.h"


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


//custom struct that will be pushed into the stack.
//stack is templated so that it accepts struct as data.
//The struct contains row,col (current coordinate)
//score, which adds all the numbers along the path
//p_row,p_col (coordinates of previous location)
//dir for which direction it goes
struct state {
  int row;
  int col;
  int score;
  int p_row;
  int p_col;
  char dir;
};



//input = 1 original matrix, and map matrix
//output = none, but it updates the map when if finds correct path to the destination
//path_stack functions uses stack to find the valid path to destination.
//the function begins with initial location at 0,0
//then the function enters the while loop in which it pops item from the stack (item at the top)
//at each valid location, 4 items get pushed into the stack (up,down,right,left).
void path_stack(std::vector<std::vector<char>> & m, const std::vector<std::vector<int>> & v) {
  //declare stack for state 
  stack<state> s;
  // initial location at 0,0;
  s.push({0,0});
  while (!s.isEmpty()) {
    // pops the item from the stack
    state curr = s.pop();
    // If it has dir P, it means that this location has tested all the possible path but failed to find valid path.
    // Therefore, mark the current location to "-" and move back
    if (curr.dir == 'P') {
      m[curr.row][curr.col] = '-';
    } 
    // if it reaches the destination and have overall score of 0, it means we found the correct path.
    // Therefore, we mark the location with X, previous location with the direction, and pop everything until we empty the stack
    else if (curr.row == m.size() -1 && curr.col == m[curr.row].size() -1 && curr.score + v[curr.row][curr.col] == 0){
      m[curr.row][curr.col] = 'X';
      m[curr.p_row][curr.p_col] = curr.dir;
      while (!s.isEmpty()) {
        s.pop();
      }
    } 
    // if the stack item is out of bound, or at a location we have been to, or reached destination but score is not 0,
    // we do nothing which means the stack item disappears.
    else if (curr.row >= m.size() || curr.col >= m[curr.row].size() || m[curr.row][curr.col] != '-' || (curr.row == m.size() -1 && curr.col == m[curr.row].size() -1)) {} 
    
    // if the code reaches else statement, it means the location is valid.
    // therfore, we mark the prev location with the direction and then we declare dir to be 'P'.
    // and pushes the curr stack back into the stack. Dir p is used to indicate that this location
    // does not lead to a correct path when it gets poped out of the stack. So we would mark it back to '-' and move on.
    // We also push items to stack for each direction with updated value.
    else {
      m[curr.p_row][curr.p_col] = curr.dir;
      curr.dir = 'P';
      s.push(curr);
      s.push({curr.row,curr.col-1,curr.score + v[curr.row][curr.col],curr.row, curr.col, '<'});
      s.push({curr.row,curr.col+1,curr.score + v[curr.row][curr.col],curr.row, curr.col, '>'});
      s.push({curr.row-1,curr.col,curr.score + v[curr.row][curr.col],curr.row, curr.col, '^'});
      s.push({curr.row+1,curr.col,curr.score + v[curr.row][curr.col],curr.row, curr.col, 'V'});
    }
  }

}


//input: takes in input value from user as string
//output: the readIn function populates the 2d vector from the file and returns the 2d vector.
std::vector<std::vector<int>> readIn(std::string file){
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

int main () {
  std::cout << "Name of the file with the matrix" << std::endl;
  std::string input;
  std::cin >> input;
  std::vector<std::vector<int>> v = readIn(input);
  std::cout << "OG matrix" << std::endl;
  print_matrix(v);
  std::cout << std::endl;
  std::vector<std::vector<char>> map(v.size(), std::vector<char>(v[0].size(), '-'));
  path_stack(map, v);
  if (map[0][0] == '-') {
    std::cout << "No Path Found" << std::endl;
  } else {
    std::cout << "Path Matrix" << std::endl;
    print_matrix(map);
  }
  return 0;
}