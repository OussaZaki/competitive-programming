/**
 * C++ solution for A - はじめてのあっとこーだー（Welcome to AtCoder）
 *
 * link - https://atcoder.jp/contests/practice/tasks/practice_1#C++_en
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>

using namespace std;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

int main()
{
    int a;
    cin >> a;

    int b, c;
    cin >> b >> c;

    string s;
    cin >> s;

    cout << (a + b + c) << " " << s << endl;
    return 0;
}