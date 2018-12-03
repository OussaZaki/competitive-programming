/**
 * C++ solution for Day3 - Advent of code 2018
 *
 * link - https://adventofcode.com/2018/day/3
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

#define M 1000
#define M_CLAIMS 1500

class Claim
{
  public:
    int x, y, w, h;

    Claim(string x1, string y1, string w1, string h1)
    {
      x = stoi(x1) - 1;
      y = stoi(y1) - 1;
      w = stoi(w1);
      h = stoi(h1);
    }
};

vector<Claim*> get_claims()
{
  vector<Claim*> claims;
  string line;

  while (getline(cin, line))
  {
    match_results<const char*> res;
    regex rx("^#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)");
    regex_search(line.c_str(), res, rx);
    claims.push_back(new Claim(res[2], res[3], res[4], res[5]));
  }
  return claims;
}

int day3_part1(vector<Claim*> claims)
{
  int fabric[M][M] = {0};
  for (auto claim = claims.begin(); claim != claims.end(); ++claim)
    for(int i = (*claim)->x; i < (*claim)->x + (*claim)->w; i++)
      for(int j = (*claim)->y; j < (*claim)->y + (*claim)->h; j++)
        fabric[i][j]++; // simply count how many time a piece of fabric was claimed

  int count = 0;
  for(int i = 0; i < M; i++)
    for(int j = 0; j < M; j++)
      if (fabric[i][j] >= 2)
        count++; // count the pieces of fabric that overlapped 
  
  return count;
}

int day3_part2(vector<Claim*> claims)
{
  int fabric[M][M] = {0}; // fabric[i][j] holds the id of the latest claim.
  bool no_overlap[M_CLAIMS] = {0}; // track overlapped claims.
  int claim_id = 1;
  for (auto claim = claims.begin(); claim != claims.end(); ++claim, claim_id++) {
    no_overlap[claim_id] = 1;
    for(int i = (*claim)->x; i < (*claim)->x + (*claim)->w; i++)
    {
      for(int j = (*claim)->y; j < (*claim)->y + (*claim)->h; j++)
      {
        if (fabric[i][j] != 0) no_overlap[fabric[i][j]] = no_overlap[claim_id] = 0;
        fabric[i][j] = claim_id;
      }
    }
  }
  
  for(int i = 1, size = claims.size(); i < size; i++)
    if (no_overlap[i] == 1) return i;

  return 0;
}

int main()
{
  vector<Claim*> claims = get_claims();
  cout << day3_part1(claims) << endl;
  cout << day3_part2(claims) << endl;
}