/**
 * C++ solution for Day5 - Advent of code 2018
 *
 * link - https://adventofcode.com/2018/day/5
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <stack>
#include <string>
#include <chrono>

using namespace std;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

string get_input() {
  string s;
  cin >> s;
  return s;
}

bool same_polarity(char c, char C) {
  return abs(c - C) == abs('A'-'a');
}

int day5_part1(string polymer) {
  stack<char> s;
  for (char c: polymer) {
    if (s.empty()) {
      s.push(c);
    } else {
      if (same_polarity(c, s.top())) s.pop();
      else s.push(c);
    }
  }
  return s.size();
}

int day5_part2(string polymer) {
  int min_size = INT_FAST16_MAX;
  for (char alpha = 'a'; alpha <= 'z'; alpha++) {
    string new_polymer;
    for (char c: polymer) {
      if (!(c == alpha || c == toupper(alpha))) {
        new_polymer += c;
      }
    }
    min_size = min(min_size, day5_part1(new_polymer));
  }
  return min_size;
}

int main()
{
  string polymer = get_input();
  cout << day5_part1(polymer) << endl;
  cout << day5_part2(polymer) << endl;
}
