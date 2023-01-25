#include <iostream>
#include <cctype>
#include <vector>

// Initial Idea:
// To find every possible combination by user input, It would be best to use recursion.
// My hypothesis is that every time i run the recursive function, for each character (in a loop), add that character to result string and
// deleting it from the original string. For example, lets say we got user input "abc".
// original string would be abc, and when it first runs function, resulting string would be empty.
// after 1 recursion, the result string will be "a", "b", "c", and corresponding original string would be "bc", "ac", "ab"
// and continues until we find all the combination.
// example with input ABC:
//

/*
      ABC(root)
      /  |   \ 
     A   B    C
    / \ / \  / \ 
   B  C A  C A  B
   |  | |  | |  |
   C  B C  A B  A 
*/

// With the diagram we know that the number of recursion equals the length of the string,
// therefore, we can create base case where the recursion stops when # of recursion calls equal the length of the original string.

// combination function takes in vector and user input to generate all the possible combination from user input
//input: The function takes in string vector and user input as string
//output: The function returns nothing but instead add each combination to vector by push_back method.
void combination (std::vector<std::string> & v, const std::string & remainder, std::string s = "") {
  // This is our base case. When the size of the string r equals 0 it should add result string to vector.
  if (remainder.size() == 0) {
    v.push_back(s);
  }

  //It loops around the remaining string to add it to resulting string and deleting it from the remaining string.
  for (int i=0; i< remainder.size(); i++) {
    //creates copy of resulting string so that it can generate unique resulting string for each character 
    std::string temp_s = s;

    //creates copy of remainder string so that when we delete character from the string, the loop is not affected by it.
    std::string temp_r = remainder;

    // we add the character to copy of the resulting string
    temp_s = temp_s + remainder[i] + " ";

    // we delete added character from remainder string
    temp_r.erase(i,1);

    // now we pass both the temp_s (resulting array for each instances) and temp_r (remainder string) to do recursion for every items in the loop
    combination(v, temp_r, temp_s);
  }
}

// printCombination function takes in a vector and print them each by each using loop;
// input: vector that needs to be printed
// output: no output, just prints them
void printCombination(std::vector<std::string> & v) {
  for (int i=0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
  }
}

// userInput function validates and process user input.
// input: none
// output: returns validated and processed user input.
std::string userInput() {
  // to receive input continuously until we find any string other than letter, I used while loop to validate the user input
  std::string y = "";
  std::string x;
  // check variable implemented to stop while loop if we see any unwanted characters
  bool check = true;
  while (check) {
    std::cin >> x;
    // after getting the user input, I loop through the user input each by each to check if it is letter.
    for (int i=0; i< x.size(); i++) {
      // if it is letter, it is added to variable y, but if it is not a letter, i break out of loop and throw away anything that comes after.
      if (!std::isalpha(x[i])) {
        check = false;
        break;
      } else {
        y += x[i];
      }
    }
  }

  return y;
}

int main () {
  std::cout << "enter letters to get the combinations" << std::endl;
  // calls userInput function to get the validated user input
  std::string y = userInput();
  std::vector<std::string> v;

  // once I get the validated user input, I simply run my recursion to get the combinations
  std::cout << "printing all combinations" << std::endl;
  combination(v, y);
  printCombination(v);


  return 0;
}