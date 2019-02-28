/**
 * Different approaches to get the maximum element of an array.
 *
 * author - Oussama Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>

using namespace std;

int maxRecursive(int *nums, int i, int j)
{
  if (i == j)
    return nums[i];
  int max_1 = maxRecursive(nums, i, i + (j - i) / 2);
  int max_2 = maxRecursive(nums, 1 + i + (j - i) / 2, j);
  if (max_1 > max_2)
    return max_1;
  else
    return max_2;
}

int Max(int *nums, int n)
{
  int max = nums[0];
  for (int i = 1; i < n; i++)
  {
    if (nums[i] > max)
    {
      max = nums[i];
    }
  }
  return max;
}

int main()
{
  int n = 7;
  int nums[] = {2, -3, 0, 17, 1, 1, -9};

  cout << maxRecursive(nums, 0, n);
  return 0;
}
