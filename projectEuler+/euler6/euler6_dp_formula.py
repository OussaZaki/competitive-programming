import sys
import functools

@functools.lru_cache(maxsize = 10000)
def sum_square_diff(n):
    if n == 1:
        return 0
    return sum_square_diff(n-1) + ((n**2)*(n-1))

t = int(input().strip())
for i in range(t):
    N = int(input().strip())
    print(sum_square_diff(N))
