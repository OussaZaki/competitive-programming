/**
 * C++ solution for Day6 - Advent of code 2018
 *
 * link - https://adventofcode.com/2018/day/6
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

typedef pair<int, int> coordinate;

struct place{ 
  int id = 0;
  int min_dist = INT_FAST16_MAX;
  int sum_dist = 0;
};

vector<coordinate> coordinates;
vector<int> rows;
vector<int> cols;

void get_input()
{
  int x, y;

  while (scanf("%i, %i", &x, &y) != EOF) {
    coordinates.push_back({x, y});
    rows.push_back(x);
    cols.push_back(y);
  }
}

int day6_part1()
{
  // Get Grid boundaries
  auto[min_row, max_row] = minmax_element(rows.begin(), rows.end());
  auto[min_col, max_col] = minmax_element(cols.begin(), cols.end());
  cout << *min_row << " " << *max_row << " " << *min_col << " " << *max_col << endl;
  
  for(int i = *min_row; i < *max_row; i++) {
    for(int j = *min_col; j < *max_col; j++) {
      // TODO: construct distance map
    }
  }

  return 0;
}

int day6_part2()
{
  
  return 0;
}

int main()
{
  get_input();
  cout << day6_part1() << endl;
  cout << day6_part2() << endl;
}
