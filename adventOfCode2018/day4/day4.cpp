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
#include <numeric>
#include <regex>

using namespace std;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING                                                                      \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

unordered_map<int, std::array<int, 60>> guards;

void construct_timetable(vector<string> inputs)
{
  smatch m;
  int guard_id, start = 0, end = 0;
  for (const auto &l : inputs)
  {
    switch (l[19])
    {
      case 'G':
      {
        regex_match(l, m, regex(R"(.*Guard #(\d+) begins shift)"));
        guard_id = stoi(m[1]);
        break;
      }
      case 'w':
      {
        regex_match(l, m, regex(R"(.*:(\d+)\] wakes up)"));
        end = stoi(m[1]);
        for (int t = start; t < end; t++)
          guards[guard_id].at(t)++;
        break;
      }
      case 'f':
      {
        regex_match(l, m, regex(R"(.*:(\d+)\] falls asleep)"));
        start = stoi(m[1]);
        break;
      }
    }
  }
}

void get_input() 
{
  vector<string> inputs;
  string line;

  while (getline(cin, line))
    inputs.push_back(line);
  sort(inputs.begin(), inputs.end());

  construct_timetable(inputs);
}

int day4_part1()
{
  // Find laziest guard, i.e. the one that slept most minutes
  int lazy_guard = 0, most_minutes = 0;
  for (auto &it : guards)
  {
    int total_minutes = accumulate(it.second.begin(), it.second.end(), 0);
    if (total_minutes > most_minutes)
      most_minutes = total_minutes;
      lazy_guard = it.first;
  }
  // Get the most slept-during minute
  int max_minute = distance(guards[lazy_guard].begin(), max_element(guards[lazy_guard].begin(), guards[lazy_guard].end()));

  return lazy_guard * max_minute;
}

int day4_part2()
{
  // 2 dimential max, first by guard, then max from all guards.
  int guard = 0, minute = 0, absolute_max_minute = 0;
  for (auto &it : guards)
  {
    int* max_minute_by_guard = max_element(it.second.begin(), it.second.end());
    if (*max_minute_by_guard > absolute_max_minute) {
      guard = it.first;
      absolute_max_minute = *max_minute_by_guard;
      minute = distance(guards[guard].begin(), max_minute_by_guard);
    }
  }
  return guard * minute;
}

int main()
{
  get_input();
  cout << day4_part1() << endl;
  cout << day4_part2() << endl;
}
