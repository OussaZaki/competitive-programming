/**
 * C++ solution for Day4 - Advent of code 2018
 *
 * link - https://adventofcode.com/2018/day/4
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <chrono>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

using namespace std;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING                                                                      \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

vector<string> get_input()
{
  vector<string> inputs;
  string line;

  while (getline(cin, line))
    inputs.push_back(line);
  sort(inputs.begin(), inputs.end());

  return inputs;
}

int day4_part1(vector<string> inputs)
{
  unordered_map<int, std::array<int, 60>> guards;

  smatch m;
  int guard_id, start = 0, end = 0;
  for (const auto &l : inputs) {   
    switch (l[19]) {
      case 'G': {
        regex_match(l, m, regex(R"(.*Guard #(\d+) begins shift)"));
        guard_id = stoi(m[1]);
        break;
      }
      case 'w': {
        regex_match(l, m, regex(R"(.*:(\d+)\] wakes up)"));
        end = stoi(m[1]);
        for (int t = start; t < end; t++) {
          guards[guard_id].at(t)++;
        }

        break;
      }
      case 'f': {
        regex_match(l, m, regex(R"(.*:(\d+)\] falls asleep)"));
        start = stoi(m[1]);
        break;
      }
    }
  }

  // TODO: Find guard with max sum(minutes)
  // TODO: Find max minute within that guard shift table

  return 0;
}

int day4_part2(vector<string> input)
{

  return 0;
}

int main()
{
  vector<string> input = get_input();
  cout << day4_part1(input) << endl;
  cout << day4_part2(input) << endl;
}
