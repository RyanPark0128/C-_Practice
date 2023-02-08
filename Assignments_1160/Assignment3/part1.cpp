#include <iostream>
#include <ctime>

// this function uses a loop to move lowercase characters to the left and uppercase letters to the right.
// It uses two pointer to check if current item is uppercase/lowercase and swap if necessary.
// input: the function takes in the string that needs to be moved around and low (0) and high (size of string) of that string
// output: the function does not return and value but moves around items inside vector
void organize_string(std::string &s, int low, int high)
{
  // we stop the loop when the low gets bigger than high
  while (low < high)
  {
    // ASCII value 65 to 90 is uppercase letter and 97 to 122 is the lowercase letters.
    if (s[low] <= 96 && s[high] >= 96)
    {
      //simple swap algoritm
      int temp = s[low];
      s[low] = s[high];
      s[high] = temp;
      //after swaping values, decrement high, increment low to move on to the next element
      low++;
      high--;
    }
    // if it is lowercase letter, move on to next element without doing anything
    if (s[low] > 96)
    {
      low++;
    }
    // if it is uppercase letter, move on to next element without doing anything
    if (s[high] < 96)
    {
      high--;
    }
  }
  return;
}

int main()
{
  srand(time(0));
  //initialize and declare string
  std::string s = "";
  // use loop to add random characters to the string. Used ASCII value to generate
  for (int i = 0; i < 16; i++)
  {
    int random = rand() % 50 + 66;
    if (random > 90)
    {
      random += 7;
    }
    char x = random;
    s += x;
  }
  std::cout << s << std::endl;
  organize_string(s, 0, s.size() - 1);
  std::cout << s << std::endl;
  return 0;
}