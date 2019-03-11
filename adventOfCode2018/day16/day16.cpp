/**
 * C++ solution for Day16 - Advent of code 2018
 *
 * link - https://adventofcode.com/2018/day/16
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>
#include <regex>

using namespace std;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

vector<int> get_input()
{
  vector<int> inputs;
  string line;

  while (getline(cin, line))
  {
    // TODO parse input
    inputs.push_back(0);
  }
  return inputs;
}

int day16_part1(vector<int> input)
{
  
  return 0;
}

int day16_part2(vector<int> input)
{
  
  return 0;
}

int main()
{
  vector<int> input = get_input();
  cout << day16_part1(input) << endl;
  cout << day16_part2(input) << endl;
}
