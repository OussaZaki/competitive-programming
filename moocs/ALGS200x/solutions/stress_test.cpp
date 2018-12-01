/**
 * C++ solution for Maximum Pairwise Product from ALGS200x/week1
 *
 * author - Oussama Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <random>

#define max(x,y) ((x > y)? x : y)
#define N 5
#define M 2e5

using namespace std;

int64_t maxProductNaive(int n, int* list);
int64_t maxProductSmart(int n, int* list);

int main(){
  random_device rd;  //Will be used to obtain a seed for the random number engine
  mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  uniform_int_distribution<int> disN(1, N);
  uniform_int_distribution<int> disM(1, M);
  int n;

  while(1) {
    n = disN(gen);
    int list[n];

    for(int i = 0; i < n; i++){
      list[i] = disM(gen);
      cout << list[i] << " ";
    }
    cout << "\n";

    int64_t r1 = maxProductNaive(n, list);
    int64_t r2 = maxProductSmart(n, list);

    if (r1 == r2) {
      cout << "OK\n";
    } else {
      cout << "Not Ok: " << r1 << " " << r2;
      break;
    }
  }
  return 0;
}

int64_t maxProductNaive(int n, int64_t* list) {
  int64_t _max = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      _max = max(_max, (int64_t)list[i] * list[j]);
    }
  }
  return _max;
}

int64_t maxProductSmart(int n, int64_t* list) {
  int64_t max = 0, second_max = 0;
  for (int i = 0; i < n; i++) {
    if (list[i] > max) second_max = max, max = list[i];
    else if (list[i] == max || list[i] > second_max) second_max = list[i];
  }

  return max * second_max;
}

