/**
 * C++ solution for B - インタラクティブ練習 (Interactive Sorting)
 *
 * link - https://atcoder.jp/contests/practice/tasks/practice_2
 * author - Oussa Zaki <zaki.oussama@gmail.com>
 */
#include <iostream>
#include <string>
using namespace std;

#define START_TIMING auto start = std::chrono::high_resolution_clock::now();
#define END_TIMING \
  chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start; \
  cout << "Execution time: " << elapsed.count() << " s\n";

bool query(int c1, int c2) {
    cout << "? " << (char)('A' + c1) << " " << (char)('A' + c2) << endl;
    cout.flush();

    char ans;
    cin >> ans;
    
    return ans == '>';
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (int j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (!query(L[i], R[j])) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}  

void printAlphabets(int A[], int size) 
{
    cout << "! ";
    for (int i = 0; i < size; i++) 
        cout << (char)('A' + A[i]); 
    cout << endl;
    cout.flush();
} 

void magicSeven(int A[])  {
  if(A[1] > A[0]) 
    swap(A[0], A[1]);
  if(A[3] > A[2])
    swap(A[3], A[2]);
  if(A[2] > A[0]) {
    swap(A[2], A[1]);
    swap(A[1], A[0]);
  }
  // Sort E into {A, C, D} - 2 comparisons
  if(A[4] > A[2]) { // Compare E and new C #4
    swap(A[4], A[3]);
    swap(A[3], A[2]);
    if(A[2] > A[0]) { // Compare E and new A #5
      swap(A[2], A[1]);
      swap(A[1], A[0]);
      if(A[4] > A[3]) { // #6
        swap(A[4], A[3]);
        if(A[2] < A[3]) // #7
          swap(A[2], A[3]);
      }
      return A;
    }
  }
  else
  if(A[4] > A[3]) // Compare E and new D #5
    swap(A[4], A[3]);
  // Sort B into {E, C, D} - 2 comparisons
  if(A[1] < A[3]) { // Compare new B and new D #6
    swap(A[1], A[2]);
    swap(A[2], A[3]);
    if(A[3] < A[4]) // Compare new D and new E #7
      swap(A[3], A[4]);
    return A;
  }
  else {
    if(query(A[1],A[2])) // Compare new B and new C #7
      swap(A[1], A[2]);
    return A;
  }
  return A;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    
    int alpha[N];
    for(int i = 0; i < N; i++) alpha[i] = i;
    mergeSort(alpha, 0, N - 1);
    printAlphabets(alpha, N);
    return 0;
}