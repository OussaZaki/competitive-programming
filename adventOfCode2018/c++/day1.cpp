/**
 * C++ solution for Day1 - Advent of code 2018
 * 
 * link - https://adventofcode.com/2018/day/1
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <chrono>

using namespace std;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

#define M 10000000
#define positive(x) !((x & (1 << 31)) | !x)

vector<int> get_frequencies()
{
  vector<int> fr;
  string line;
  while (getline(cin, line))
  {
    fr.push_back(stoi(line, nullptr, 10));
  }
  return fr;
}

int day1_part1(vector<int> fr)
{
  int final_frequency = 0;

  for (auto const &value : fr)
    final_frequency += value;
  return final_frequency;
}

int day1_part2(vector<int> fr)
{
  int final_frequency = 0;
  set<int> freq_history;

  vector<int>::iterator fr_it = fr.begin();
  int count = 0;
  while (1)
  {
    final_frequency += *fr_it;
    if (!freq_history.insert(final_frequency).second)
      break;
    count++;
    fr_it++;
    if (fr_it == fr.end())
      fr_it = fr.begin();
  }
  return final_frequency;
}

/**
 * Enhanced implementation using bitset instead of set
 */
int day1_part2_bitset(vector<int> fr)
{
  int ff = 0;
  bitset<M> positive_sums;
  bitset<M> negative_sums;
  negative_sums[0] = 1;

  vector<int>::iterator fr_it = fr.begin();
  while (1)
  {
    ff += *fr_it;
    if (positive(ff))
    {
      if (positive_sums[ff])
        break;
      positive_sums[ff] = 1;
    }
    else
    {
      if (negative_sums[-ff])
        break;
      negative_sums[-ff] = 1;
    }

    fr_it++;
    if (fr_it == fr.end())
      fr_it = fr.begin();
  }
  return ff;
}

int main()
{
  vector<int> fr = get_frequencies();
  cout << day1_part1(fr) << endl;
  cout << day1_part2_bitset(fr) << endl;
}