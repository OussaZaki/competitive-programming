/**
 * C++ solution for Day1 - Advent of code 2019
 * 
 * link - https://adventofcode.com/2018/day/1
 * author - Oussa Zaki <me@oussa.dev>
 */
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

//--- Helpers to count execution time, for my own performance challenge.
#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";
//---

#define M 10000000
#define positive(x) !((x & (1 << 31)) | !x)

// Get input lines from the file day.in file
vector<int> get_lines()
{
  vector<int> lines;
  string line;
  while (getline(cin, line))
  {
    lines.push_back(stoi(line, nullptr, 10));
  }
  return lines;
}

int get_required_fuel(int masse)
{
  return floor(masse / 3) - 2;
}

int get_accumulated_fuel(int masse)
{
  // any masse below 7 is under the wishing really hard blessing.
  if (masse < 7) return 0;
  // The required fuel for the given masse.
  int req_fuel = get_required_fuel(masse);

  // The required fuel for the given masse plus the fuel necessary for it's fuel.
  return req_fuel + get_accumulated_fuel(req_fuel);
}

long day1_part1(vector<int> module_masses)
{
  long total_mass = 0;

  for (auto const &value : module_masses)
    total_mass += value;
  return get_required_fuel(total_mass);
}

int day1_part2(vector<int> module_masses)
{
  int total_fuel_requirement = 0;

  /**
   * (m / 3) - 2 = (m- 6)/3
   * ((m-6)/3 / 3) - 2 = (m - 24)/ 9
   * ((m - 24)/3 / 3) - 2 = (m - 24)/ 9 * 3
   * a^i -
   * 
   **/
  for (auto const &value : module_masses)
    total_fuel_requirement += get_accumulated_fuel(value);
  return total_fuel_requirement;
}

int main()
{
  vector<int> fr = get_lines();
  cout << day1_part1(fr) << endl;
  cout << day1_part2(fr) << endl;
}

