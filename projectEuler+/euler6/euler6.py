import sys

def sum_square_diff(n):
    sumSquare = n * (n+1) * (2*n+1) // 6
    squareSum = (n * (n+1) // 2) ** 2
    return squareSum - sumSquare

t = int(input().strip())
for i in range(t):
    N = int(input().strip())
    print(sum_square_diff(N))
