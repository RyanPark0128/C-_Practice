#include <iostream>
#include <ctime>
#include <vector>

//print_vector function just print all the item inside a vector
//input: the function takes in a vector
//output: the function does not return anything but simple prints every element of the vector
void print_vector(const std::vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

//combine_vector function combines two different vector into one and sorts elements inside it while combining it.
//Instead of using sort algoritm, since two array is sorted either in ascending order or in descending order, we only need to use while loop to sort it.
//input: the function takes in two vectors that will be combined, one vector to save the result, i and j to track the index.
//output: the function does not return anything but combines two vector into one sorted vector
void combine_vector(std::vector<int> &one, std::vector<int> &two, std::vector<int> &combined, int i, int j)
{
  // it loops until both i is greather than first vector's size and j is smaller than 0
  while (i < one.size() || j > 0)
  {
    // if i is bigger than one's (first vector) size, it means we have no item left in the first vector, so add item from the second vector.
    if (i > one.size())
    {
      combined.push_back(two[j]);
      j--;
    }
    // if j is smaller than 0, it means we have no item left in the second vector, so add item from the first vector.
    else if (j < 0)
    {
      combined.push_back(one[i]);
      i++;
    }
    // if item for first vector is bigger than the item from second vector, we add the item from the second vector to the combined vector
    else if (one[i] >= two[j])
    {
      combined.push_back(two[j]);
      j--;
    }
    // if item for second vector is bigger than the item from first vector, we add the item from the first vector to the combined vector
    else if (one[i] < two[j])
    {
      combined.push_back(one[i]);
      i++;
    }
  }
}

//generate_vector function populates two vectors. first vector is populated in ascending order, and the second vector is populated in descending order
//input: the function takes in two vector which needs to be populated in asceding order of descending order
//output: the function returns nothing but it defines values for each vector that is takes in with ascending/descending values.
void generate_vector(std::vector<int> &one, std::vector<int> &two)
{
  for (int i = 0; i < one.size(); i++)
  {
    if (i == 0)
    {
      one[0] = (rand() % 10);
      two[0] = (rand() % 10);
    }
    else
    {
      // add random value each time it loops to the first vector and subtract random value each time to the second vector
      one[i] = one[i - 1] + ((rand() % 10) + 1);
      two[i] = two[i - 1] - ((rand() % 10) + 1);
    }
  }

  return;
}
int main()
{
  srand(time(0));
  // declare vectors
  std::vector<int> one(8);
  std::vector<int> two(8);
  std::vector<int> combined;
  generate_vector(one, two);
  std::cout << "Vector one" << std::endl;
  print_vector(one);
  std::cout << "Vector two" << std::endl;
  print_vector(two);
  combine_vector(one, two, combined, 0, two.size() - 1);
  std::cout << "Combo vector" << std::endl;
  print_vector(combined);
  return 0;
}