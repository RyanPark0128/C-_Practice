#include <iostream>
#include <ctime>
// g++ -pedantic -Wall -Wextra -std=c++17 lab1.cpp -o test

void rollDice(int & sum) {
    int one = rand()%6 +1;
    int two = rand()%6 +1;
    sum = one + two;
}

bool calculateResult (int sum, bool & winner) {
  if (sum == 7 || sum == 11) {
    winner = true;
    std::cout << "sum 7 or 11 end game win" << std::endl;
    return true;
  } else if (sum == 2 || sum == 3 || sum == 12) {
    winner = false;
        std::cout << "sum 2 or 3 or 12 end game lose" << std::endl;
    return true;
  } else {
    int temp = sum;
    int newSum;
    rollDice(newSum);
    while (newSum != 7 && newSum != temp) {
      rollDice(newSum);
    }
    if (temp == newSum) {
      winner = true;
      std::cout << "sum = temp end game win" << std::endl;
    } else if (newSum == 7) {
      winner = false;
      std::cout << "sum = 7 end game lose" << std::endl;
    }
    return true;
  }
}

int playgame() {
  int sum = 0;
  bool winner;
  rollDice(sum);
  calculateResult(sum, winner);
  return winner;
}

int main() {
  srand(time(0));
  int win = 0;
  for (int i =0; i < 1000000; i++) {
    win += playgame();
  }

  std::cout << "win rate is " << win << "/" << 1000000 << std::endl;

  return 0;
}
