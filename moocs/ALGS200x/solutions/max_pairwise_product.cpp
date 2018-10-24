/**
 * C++ solution for Maximum Pairwise Product from ALGS200x/week1
 *
 * author - Oussama Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>

using namespace std;

int main(){
  int n = 0;
  cin >> n;
  
  long long max = 0, second_max = 0, tmp = 0;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp > max) second_max = max, max = tmp;
    else if (tmp == max || tmp > second_max) second_max = tmp;
  }
  
  cout << max * second_max;
  return 0;
}