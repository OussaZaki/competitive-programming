/**
 * C++ solution for Foregone - Google Code Jam 2019
 * 
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <set>
#include <iterator>


using namespace std;
#define ulli unsigned long long int;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

int quick_pow10(int n)
{
    static int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    return pow10[n]; 
}

unsigned long long extractFours(string N) {
  unsigned long long fours = 0;
  for (int i = 0, l = N.size(); i < l; i++) {
    if (N[i] == '4') {
        fours += 4 * quick_pow10(l - 1 - i);
    }
  }
  return fours;
};


int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    unsigned long long N;
    cin >> N;
    unsigned long long foursOur = extractFours(to_string(N));

    cout << "Case #" << i + 1 << ": " << N - foursOur / 2 << " " << foursOur / 2 << endl;
  }
  return 0;
}