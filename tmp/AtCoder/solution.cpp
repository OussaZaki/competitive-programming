/**
 * C++ solution for C - 文字列比較 / String Comparison
 *
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;

int LCSubStr(string X, string Y, int m, int n)
{

  int lcs[m + 1][n + 1]; 
  int result = 0;


  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0) lcs[i][j] = 0;
      else if (X[i - 1] == Y[j - 1])
      {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;

        result = max(result, lcs[i][j]);
      }
      else
        lcs[i][j] = 0;
    }
  }

  return result;
}

bool minSubsitution(string str1, string str2, int n)
{
  int diff_count = 0;
  for (int i = 0; i < n; i++)
  {
    if (str1[i] != str2[i])
    {
      diff_count++;
    }

    if (diff_count > 1)
    {
      return false;
    }
  }

  return (diff_count < 2);
}

string possibleTransformation(string str1, string str2)
{
  int m = str1.size();
  int n = str2.size();
  if ((m == n) && !minSubsitution(str1, str2, n)) return "NO";

  int len = LCSubStr(str1, str2, m, n);
  if (m - len > 1) return "NO";

  if (n - len > 1) return "NO";

  return "YES";
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << possibleTransformation(s1, s2) << endl;

  return 0;
}