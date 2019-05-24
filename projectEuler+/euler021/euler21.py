#!/bin/python3

from math import sqrt

def factors_sum(n):
    res = 0
    for i in range(2, (int)(sqrt(n)) + 1):
        if n % i == 0:
            if i == (n / i):
                res += i
            else:
                res += i + n / i
    res += 1
    return int(res)

T = int(input().strip())
for _ in range(T):
    N = int(input())
    print(amicable_sum(N))
