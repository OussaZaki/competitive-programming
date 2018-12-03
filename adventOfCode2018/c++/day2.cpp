/**
 * C++ solution for Day2 - Advent of code 2018
 * 
 * link - https://adventofcode.com/2018/day/2
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <chrono>
#include <algorithm>

using namespace std;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

vector<string> get_ids()
{
  vector<string> ids;
  string line;
  while (getline(cin, line))
  {
    ids.push_back(line);
  }
  return ids;
}

int day2_part1(vector<string> ids)
{
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  
  int double_count = 0;
  int tripple_count = 0;
  
  for (auto const &id : ids) {
    bool double_found = 0;
    bool tripple_found = 0;
    int i = 0;
    while (i < 27) {
      size_t n = count(id.begin(), id.end(), alpha[i++]);
      if (!double_found && n == 2) {
        double_count++;
        double_found = 1;
      }

      if (!tripple_found && n == 3) {
        tripple_count++;
        tripple_found = 1;
      }

      if (tripple_found && double_found) {
        break;
      }
    }
  }
  
  return double_count * tripple_count;
}

string day2_part2(vector<string> ids)
{
  string candidate_solution;
  int diffs;
  int id_size = ids[0].size(); // All IDs have same length
  int ids_count = ids.size();

  for(int i = 0; i < ids_count - 1; i++) {
    for(int j = i + 1; j < ids_count; j++) {
      if (!ids[i].compare(ids[j])) continue;

      diffs = 0;
      candidate_solution = "";
      for (int x = 0; x < id_size && diffs < 2; x++) {
        if (ids[i][x] == ids[j][x]) candidate_solution += ids[i][x];
        else diffs++;
      }

      if (diffs == 1) return candidate_solution;
    }
  }
  return "";
}

int main()
{
  vector<string> ids = get_ids();
  cout << day2_part1(ids) << endl;
  cout << day2_part2(ids) << endl;
}